package com.raceyourself.platform.utils;

import java.text.DecimalFormat;

/**
 * Created by benlister on 02/07/2014.
 */
public class Format {

    private static DecimalFormat zeroDp = new DecimalFormat("###");
    private static DecimalFormat oneDp = new DecimalFormat("###.0");
    private static DecimalFormat twoDp = new DecimalFormat("###.00");
    private static DecimalFormat twoPad = new DecimalFormat("###.00");

    public static String zeroDp(double d) {
        return zeroDp.format(d);
    }

    public static String oneDp(double d) {
        return oneDp.format(d);
    }

    public static String twoDp(double d) {
        return twoDp.format(d);
    }

    public static String twoPad(double d) {
        return twoPad.format(d);
    }
}
