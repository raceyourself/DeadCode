/**
 * AudioFingerprinter.java
 * EchoprintLib
 * 
 * Created by Alex Restrepo on 1/22/12.
 * Copyright (C) 2012 Grand Valley State University (http://masl.cis.gvsu.edu/)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

package edu.gvsu.masl.echoprint;

import android.app.Activity;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.util.Base64;
import android.util.Log;
import android.util.Pair;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.zip.InflaterOutputStream;

/**
 * Main fingerprinting class<br>
 * This class will record audio from the microphone, generate the fingerprint code using a native library and query the data server for a match
 * 
 * @author Alex Restrepo (MASL)
 *
 */
public class AudioFingerprinter implements Runnable 
{
	public final static String META_SCORE_KEY = "meta_score";
	public final static String SCORE_KEY = "score";
	public final static String ALBUM_KEY = "release";
	public final static String TITLE_KEY = "track";
	public final static String TRACK_ID_KEY = "track_id";
	public final static String ARTIST_KEY = "artist";
	
	private final String SERVER_URL = "http://developer.echonest.com/api/v4/song/identify?api_key=SNXY9BJV1D3O9ONEB&version=4.11&code=";

    private final Map<Long, List<String>> reverseIndex = new HashMap<Long, List<String>>();
    private final Map<String, List<Pair<Long, Long>>> fingerprints = new HashMap<String, List<Pair<Long, Long>>>();
    private final AtomicInteger idSequence = new AtomicInteger(0);
	
	private final int FREQUENCY = 11025;
	private final int CHANNEL = AudioFormat.CHANNEL_IN_MONO;
	private final int ENCODING = AudioFormat.ENCODING_PCM_16BIT;	
	
	private Thread thread;
	private volatile boolean isRunning = false;
	AudioRecord mRecordInstance = null;
	
	private short audioData[];
	private int bufferSize;	
	private int secondsToRecord;
	private volatile boolean continuous;
	
	private AudioFingerprinterListener listener;
	
	/**
	 * Constructor for the class
	 * 
	 * @param listener is the AudioFingerprinterListener that will receive the callbacks
	 */
	public AudioFingerprinter(AudioFingerprinterListener listener)
	{
		this.listener = listener;
	}
	
	/**
	 * Starts the listening / fingerprinting process using the default parameters:<br>
	 * A single listening pass of 20 seconds 
	 */
	public void fingerprint()
	{
		// set dafault listening time to 20 seconds
		this.fingerprint(20);
	}
	
	/**
	 * Starts a single listening / fingerprinting pass
	 * 
	 * @param seconds the seconds of audio to record.
	 */
	public void fingerprint(int seconds)
	{
		// no continuous listening
		this.fingerprint(seconds, false);
	}
	
	/**
	 * Starts the listening / fingerprinting process
	 * 
	 * @param seconds the number of seconds to record per pass
	 * @param continuous if true, the class will start a new fingerprinting pass after each pass
	 */
	public void fingerprint(int seconds, boolean continuous)
	{
		if(this.isRunning)
			return;
				
		this.continuous = continuous;
		
		this.secondsToRecord = Math.max(seconds, 10);
		
		// start the recording thread
		thread = new Thread(this);
		thread.start();
	}
	
	/**
	 * stops the listening / fingerprinting process if there's one in process
	 */
	public void stop() 
	{
		this.continuous = false;
		if(mRecordInstance != null)
			mRecordInstance.stop();
	}
	
	/**
	 * The main thread<br>
	 * Records audio and generates the audio fingerprint, then it queries the server for a match and forwards the results to the listener.
	 */
	public void run() 
	{
		this.isRunning = true;
		try 
		{			
			// create the audio buffer
			// get the minimum buffer size
			int minBufferSize = AudioRecord.getMinBufferSize(FREQUENCY, CHANNEL, ENCODING);
			
			// and the actual buffer size for the audio to record
			// frequency * seconds to record.
			bufferSize = Math.max(minBufferSize, this.FREQUENCY * this.secondsToRecord);
						
			audioData = new short[bufferSize];
						
			// start recorder
			mRecordInstance = new AudioRecord(
								MediaRecorder.AudioSource.MIC,
								FREQUENCY, CHANNEL, 
								ENCODING, minBufferSize);
						
			willStartListening();
			
			mRecordInstance.startRecording();
			boolean firstRun = true;
			do 
			{		
				try
				{
					willStartListeningPass();
					
					long time = System.currentTimeMillis();
					// fill audio buffer with mic data.
					int samplesIn = 0;
					do 
					{					
						samplesIn += mRecordInstance.read(audioData, samplesIn, bufferSize - samplesIn);
						
						if(mRecordInstance.getRecordingState() == AudioRecord.RECORDSTATE_STOPPED)
							break;
					} 
					while (samplesIn < bufferSize);				
					Log.d("Fingerprinter", "Audio recorded: " + (System.currentTimeMillis() - time) + " millis");

                    didFinishListeningPass();

					// create an echoprint codegen wrapper and get the code
					time = System.currentTimeMillis();
					Codegen codegen = new Codegen();
                    willStartCodegenPass();
	    			String code = codegen.generate(audioData, samplesIn);
	    			Log.d("Fingerprinter", "Codegen created in: " + (System.currentTimeMillis() - time) + " millis");
                    didFinishCodegenPass();

	    			if(code.length() < 50*10)
	    			{
	    				// no code?
	    				// not enough audio data?
                        didNotFindMatchForCode(code);
						continue;
	    			}

	    			didGenerateFingerprintCode(code);
                    Log.d("Fingerprinter", "code " + code.length());

                    List<Pair<Long,Long>> tuples = decodeFingerprint(code);
                    if(tuples.size() < 50)
                    {
                        didNotFindMatchForCode(code);
                        continue;
                    }
                    Pair<String, String> best = bestMatch(tuples);

                    if (best == null) {
                        didNotFindMatchForCode(code);
                    } else {
                        Hashtable<String, String> match = new Hashtable<String, String>();
                        match.put(SCORE_KEY, best.second);
                        match.put(TRACK_ID_KEY, best.first);

                        didFindMatchForCode(match, code);
                    }


//                    // fetch data from echonest
//	    			time = System.currentTimeMillis();
//
//					String urlstr = SERVER_URL + code;
//					Log.d("Fingerprinter", urlstr);
//					HttpClient client = new DefaultHttpClient();
//	    			HttpGet get = new HttpGet(urlstr);
//
//	    			// get response
//	    			HttpResponse response = client.execute(get);
//	    			// Examine the response status
//	    	        Log.d("Fingerprinter",response.getStatusLine().toString());
//
//	    	        // Get hold of the response entity
//	    	        HttpEntity entity = response.getEntity();
//	    	        // If the response does not enclose an entity, there is no need
//	    	        // to worry about connection release
//
//	    	        String result = "";
//	    	        if (entity != null)
//	    	        {
//	    	            // A Simple JSON Response Read
//	    	            InputStream instream = entity.getContent();
//	    	            result= convertStreamToString(instream);
//	    	            // now you have the string representation of the HTML request
//	    	            instream.close();
//	    	        }
//	     			Log.d("Fingerprinter", "Results fetched in: " + (System.currentTimeMillis() - time) + " millis\n"+result);
//
//
//	    			// parse JSON
//		    		JSONObject w = new JSONObject(result);
//		    		JSONObject r = w.getJSONObject("response");
//		    		JSONObject status = r.getJSONObject("status");
//		    		JSONArray songs = r.getJSONArray("songs");
//
//
//
//		    		if(status.has("code"))
//		    			Log.d("Fingerprinter", "Response code:" + status.getInt("code") + " (" + this.messageForCode(status.getInt("code")) + ")");
//
//		    		if(songs != null && songs.length() > 0)
//		    		{
//		    		    for(int i=0; i< songs.length();i++) {
//		    		        JSONObject jo = (JSONObject)songs.get(i);
//		    				Hashtable<String, String> match = new Hashtable<String, String>();
//		    				match.put(SCORE_KEY, jo.getInt("score") + "");
//		    				match.put(TRACK_ID_KEY, jo.getString("id"));
//
//                            match.put(TITLE_KEY, jo.getString("title"));
//                            match.put(ARTIST_KEY, jo.getString("artist_name"));
//
//		    				didFindMatchForCode(match, code);
//		    			}
//		    		}
//		    		else
//		    		{
//                        didNotFindMatchForCode(code);
//		    		}
//
//		    		firstRun = false;
				
				}
				catch(Exception e)
				{
					e.printStackTrace();
					Log.e("Fingerprinter", e.getClass().getSimpleName() + " " + e.getLocalizedMessage());
					
					didFailWithException(e);
				}
			}
			while (this.continuous);
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
			Log.e("Fingerprinter", e.getLocalizedMessage());
			
			didFailWithException(e);
		}
		
		if(mRecordInstance != null)
		{
			mRecordInstance.stop();
			mRecordInstance.release();
			mRecordInstance = null;
		}
		this.isRunning = false;
		
		didFinishListening();
	}

    private static List<Pair<Long, Long>> decodeFingerprint(String code) throws IOException {
        byte[] bytes = Base64.decode(code.getBytes("UTF-8"), Base64.URL_SAFE);
        Log.d("Fingerprinter", "decoded " + bytes.length);

        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        InflaterOutputStream dos = new InflaterOutputStream(baos);
        dos.write(bytes);
        dos.finish();
        dos.flush();
        byte[] deflated = baos.toByteArray();
        Log.d("Fingerprinter", "decompressed " + deflated.length);

        int n = deflated.length / 10;
        int split = n*5;
        List<Pair<Long, Long>> tuples = new ArrayList<Pair<Long, Long>>(n);
        for (int i=0; i<n; i++) {
            int ts_i = i*5;
            String hexTimestamp = new String(deflated, ts_i, 5, "utf-8");
            int hash_i = split + i*5;
            String hexHash = new String(deflated, hash_i, 5, "utf-8");

            long timestamp = Long.parseLong(hexTimestamp, 16);
            long hash = Long.parseLong(hexHash, 16);

            tuples.add(new Pair<Long, Long>(new Long(hash), new Long(timestamp)));
        }
        return tuples;
    }

    private Pair <String, String> bestMatch(List<Pair<Long, Long>> tuples) {
        Set<Long> uniqueKeys = new HashSet<Long>(); // Unique keys
        Map<String, Integer> matchHits = new HashMap<String, Integer>(); // Frequency of matched ids
        for (Pair<Long, Long> tuple : tuples) {
            long hash = tuple.first;
            if (!uniqueKeys.contains(hash)) {
                uniqueKeys.add(hash);
                List<String> ids = reverseIndex.get(hash);
                if (ids == null) ids = new LinkedList<String>();
                for (String id : ids) {
                    Integer count = matchHits.get(id);
                    if (count == null) count = 1;
                    else count++;
                    matchHits.put(id, count);
                }
            }
        }

        String bestId = null;
        Integer rank = null;
        for (Map.Entry<String, Integer> entry : matchHits.entrySet()) {
            String matchId = entry.getKey();
            int hits = entry.getValue();
            int r = actualRank(tuples, fingerprints.get(matchId));
            Log.i("Fingerprinter", "Matched " + matchId + " with " + (hits*100/tuples.size()) + "%, actual " + (r*100/tuples.size()) + "%");
            if (rank == null || rank < r) {
                rank = r;
                bestId = matchId;
            }
        }
        if (bestId == null) return null;
        if (rank*100/tuples.size() < 5) return null; // Ignore low matches

        return new Pair<String, String>(bestId, String.valueOf(rank*100/tuples.size()) + '%');
    }

    private static int actualRank(List<Pair<Long, Long>> lookup, List<Pair<Long, Long>> fingerprint) {
        final int slop = 5;
        Map<Long, List<Long>> hashTimes = new HashMap<Long, List<Long>>();
        Long startTime = null;
        for (Pair<Long, Long> tuple : lookup) {
            long hash = tuple.first;
            long time = tuple.second;
            List<Long> times = hashTimes.get(hash);
            if (times == null) times = new LinkedList<Long>();
            times.add(time);
            hashTimes.put(hash, times);
            if (startTime == null || time < startTime) startTime = time;
        }
        // Normalize times and bucket to slop
        for (Long hash : hashTimes.keySet()) {
            List<Long> times = hashTimes.get(hash);
            for (int i = 0; i<times.size(); i++) {
                times.set(i, (times.get(i) - startTime)/slop);
            }
        }

        // Generate histogram of min code distances
        Map<Integer, Integer> histogram = new HashMap<Integer, Integer>();
        for (Pair<Long, Long> tuple : fingerprint) {
            long hash = tuple.first;
            long hashTime = tuple.second/slop;

            List<Long> times = hashTimes.get(hash);
            if (times == null) {
                continue;
            }

            Long min = null;
            for (Long otherTime : times) {
                long diff = Math.abs(hashTime - otherTime);
                if (min == null || min > diff) min = diff;
            }
            if (min != null) {
                Integer count = histogram.get(min.intValue());
                if (count == null) count = 1;
                else count++;
                histogram.put(min.intValue(), count);
            }
        }

        Map<Integer, Integer> sortedHistogram = sortByValue(histogram, true);
        Integer first = null, second = null;
        for(Map.Entry<Integer, Integer> entry : sortedHistogram.entrySet()) {
            if (first == null) first = entry.getValue();
            else if (second == null) second = entry.getValue();
            else break;
        }

        if (second != null) return first + second;
        if (first != null) return first;
        return 0;
    }

    public static <K, V extends Comparable<? super V>> Map<K, V>
    sortByValue( final Map<K, V> map, final boolean reversed )
    {
        List<Map.Entry<K, V>> list =
                new LinkedList<Map.Entry<K, V>>( map.entrySet() );
        Collections.sort( list, new Comparator<Map.Entry<K, V>>()
        {
            public int compare( Map.Entry<K, V> o1, Map.Entry<K, V> o2 )
            {
                int cmp = (o1.getValue()).compareTo( o2.getValue() );
                if (reversed) return -cmp;
                else return cmp;
            }
        } );

        Map<K, V> result = new LinkedHashMap<K, V>();
        for (Map.Entry<K, V> entry : list)
        {
            result.put( entry.getKey(), entry.getValue() );
        }
        return result;
    }

    public String insertFingerprint(String id, String code) throws IOException {
        List<Pair<Long,Long>> tuples = decodeFingerprint(code);

        // Insert into db
        fingerprints.put(id, tuples);
        for (Pair<Long, Long> tuple : tuples) {
            long hash = tuple.first;
            List<String> ids = reverseIndex.get(hash);
            if (ids == null) ids = new LinkedList<String>();
            ids.add(id);
            reverseIndex.put(hash, ids);
        }

        return id;
    }

	private static String convertStreamToString(InputStream is) 
	{
	    /*
	     * To convert the InputStream to String we use the BufferedReader.readLine()
	     * method. We iterate until the BufferedReader return null which means
	     * there's no more data to read. Each line will appended to a StringBuilder
	     * and returned as String.
	     */
	    BufferedReader reader = new BufferedReader(new InputStreamReader(is));
	    StringBuilder sb = new StringBuilder();

	    String line = null;
	    try {
	        while ((line = reader.readLine()) != null) {
	            sb.append(line + "\n");
	        }
	    } catch (IOException e) {
	        e.printStackTrace();
	    } finally {
	        try {
	            is.close();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
	    }
	    return sb.toString();
	}
		
	private String messageForCode(int code)
	{
		try{
			String codes[] = {
					"NOT_ENOUGH_CODE", "CANNOT_DECODE", "SINGLE_BAD_MATCH", 
					"SINGLE_GOOD_MATCH", "NO_RESULTS", "MULTIPLE_GOOD_MATCH_HISTOGRAM_INCREASED",
					"MULTIPLE_GOOD_MATCH_HISTOGRAM_DECREASED", "MULTIPLE_BAD_HISTOGRAM_MATCH", "MULTIPLE_GOOD_MATCH"
					}; 
	
			return codes[code];
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			return "UNKNOWN";
		}
	}
	
	private void didFinishListening()
	{
		if(listener == null)
			return;
		
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.didFinishListening();
				}
			});
		}
		else
			listener.didFinishListening();
	}
	
	private void didFinishListeningPass()
	{
		if(listener == null)
			return;
		
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.didFinishListeningPass();
				}
			});
		}
		else
			listener.didFinishListeningPass();
	}
	
	private void willStartListening()
	{
		if(listener == null)
			return;
		
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.willStartListening();
				}
			});
		}
		else	
			listener.willStartListening();
	}

    private void didFinishCodegenPass()
    {
        if(listener == null)
            return;

        if(listener instanceof Activity)
        {
            Activity activity = (Activity) listener;
            activity.runOnUiThread(new Runnable()
            {
                public void run()
                {
                    listener.didFinishCodegenPass();
                }
            });
        }
        else
            listener.didFinishCodegenPass();
    }

    private void willStartCodegenPass()
    {
        if(listener == null)
            return;

        if(listener instanceof Activity)
        {
            Activity activity = (Activity) listener;
            activity.runOnUiThread(new Runnable()
            {
                public void run()
                {
                    listener.willStartCodegenPass();
                }
            });
        }
        else
            listener.willStartCodegenPass();
    }

    private void willStartListeningPass()
	{
		if(listener == null)
			return;
			
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.willStartListeningPass();
				}
			});
		}
		else
			listener.willStartListeningPass();
	}
	
	private void didGenerateFingerprintCode(final String code)
	{
		if(listener == null)
			return;
		
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.didGenerateFingerprintCode(code);
				}
			});
		}
		else
			listener.didGenerateFingerprintCode(code);
	}
	
	private void didFindMatchForCode(final Hashtable<String, String> table, final String code)
	{
		if(listener == null)
			return;
			
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.didFindMatchForCode(table, code);
				}
			});
		}
		else
			listener.didFindMatchForCode(table, code);
	}
	
	private void didNotFindMatchForCode(final String code)
	{
		if(listener == null)
			return;
		
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.didNotFindMatchForCode(code);
				}
			});
		}
		else
			listener.didNotFindMatchForCode(code);
	}
	
	private void didFailWithException(final Exception e)
	{
		if(listener == null)
			return;
			
		if(listener instanceof Activity)
		{
			Activity activity = (Activity) listener;
			activity.runOnUiThread(new Runnable() 
			{		
				public void run() 
				{
					listener.didFailWithException(e);
				}
			});
		}
		else
			listener.didFailWithException(e);
	}
		
	/**
	 * Interface for the fingerprinter listener<br>
	 * Contains the different delegate methods for the fingerprinting process
	 * @author Alex Restrepo
	 *
	 */
	public interface AudioFingerprinterListener
	{		
		/**
		 * Called when the fingerprinter process loop has finished
		 */
		public void didFinishListening();
		
		/**
		 * Called when a single fingerprinter pass has finished
		 */
		public void didFinishListeningPass();

        /**
         * Called when a single codegen pass has finished
         */
        public void didFinishCodegenPass();

        /**
         * Called when a single codegen pass is about to start
         */
        public void willStartCodegenPass();

        /**
		 * Called when the fingerprinter is about to start
		 */
		public void willStartListening();
		
		/**
		 * Called when a single listening pass is about to start
		 */
		public void willStartListeningPass();
		
		/**
		 * Called when the codegen libary generates a fingerprint code
		 * @param code the generated fingerprint as a zcompressed, base64 string
		 */
		public void didGenerateFingerprintCode(String code);
		
		/**
		 * Called if the server finds a match for the submitted fingerprint code 
		 * @param table a hashtable with the metadata returned from the server
		 * @param code the submited fingerprint code
		 */
		public void didFindMatchForCode(Hashtable<String, String> table, String code);
		
		/**
		 * Called if the server DOES NOT find a match for the submitted fingerprint code
		 * @param code the submited fingerprint code
		 */
		public void didNotFindMatchForCode(String code);
		
		/**
		 * Called if there is an error / exception in the fingerprinting process
		 * @param e an exception with the error
		 */
		public void didFailWithException(Exception e);
	}
}
