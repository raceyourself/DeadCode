// Copyright (C) 2009-2010 Amundis
// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt
// and OpenGL ES driver implemented by Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Irrlicht.h
#include "COGLES2Renderer2D.h"

#ifdef _IRR_COMPILE_WITH_OGLES2_
#include "IGPUProgrammingServices.h"
#include "IShaderConstantSetCallBack.h"
#include "IVideoDriver.h"
#include "os.h"
#include "COGLES2Driver.h"
#include "COGLES2Utils.h"

namespace irr
{
	namespace video
	{

		const char* const COGLES2Renderer2d::sBuiltInShaderUniformNames[] =
		{
			"uOrthoMatrix",
			"uUseTexture",
			"uTextureUnit",
			"uAlphaTest",
			"uAlphaValue",
			0
		};

		static const char* vertexShaderFile   = "/mnt/sdcard/Irrlicht/COGLES2Renderer2D.vsh";
		static const char* fragmentShaderFile = "/mnt/sdcard/Irrlicht/COGLES2Renderer2D.fsh";

		static const char vertexShaderBuf[] = 
			"// Copyright (C) 2009-2010 Amundis\n"
			"// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt\n"
			"// and OpenGL ES driver implemented by Christian Stehno\n"
			"// This file is part of the \"Irrlicht Engine\".\n"
			"// For conditions of distribution and use, see copyright notice in Irrlicht.h\n"
			"attribute vec4 inVertexPosition;\n"
			"attribute vec4 inVertexColor;\n"
			"attribute vec4 inTexCoord0;\n"
			"\n"
			"uniform mat4 uOrthoMatrix;\n"
			"\n"
			"varying vec4 varVertexColor;\n"
			"varying vec4 varTexCoord;\n"
			"\n"
			"void main(void)\n"
			"{\n"
			"	gl_Position    = uOrthoMatrix * inVertexPosition;\n"
			"	varVertexColor = inVertexColor.bgra;\n"
			"	varTexCoord    = inTexCoord0;\n"
			"}\n";
		static const char fragmentShaderBuf[] = 
			"// Copyright (C) 2009-2010 Amundis\n"
			"// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt\n"
			"// and OpenGL ES driver implemented by Christian Stehno\n"
			"// This file is part of the \"Irrlicht Engine\".\n"
			"// For conditions of distribution and use, see copyright notice in Irrlicht.h\n"
			"precision highp float;\n"
			"precision highp int;\n"
			"\n"
			"uniform int uUseTexture;\n"
			"uniform sampler2D uTextureUnit;\n"
			"uniform int uAlphaTest;\n"
			"uniform float uAlphaValue;\n"
			"\n"
			"varying vec4 varVertexColor;\n"
			"varying vec4 varTexCoord;\n"
			"\n"
			"void main(void)\n"
			"{\n"
			"	vec4 color = varVertexColor;\n"
			"	vec4 texel = texture2D(uTextureUnit, varTexCoord.xy);\n"
			"	if(uUseTexture != 0)\n"
			"	{\n"
			"		color *= texel;\n"
			"	}\n"
			"	\n"
			"	if(uAlphaTest != 0 && !(color.a > uAlphaValue))\n"
			"		discard;\n"
			"	\n"
			"	gl_FragColor = color;\n"
			"}\n";


		COGLES2Renderer2d::COGLES2Renderer2d( irr::video::COGLES2Driver *driver, irr::io::IFileSystem *fs )
			: COGLES2SLMaterialRenderer( driver, fs, 0, 0, sBuiltInShaderUniformNames, UNIFORM_COUNT )
		{
#ifdef _DEBUG
			setDebugName( "COGLES2Renderer2d" );
#endif
			s32 dummy = -1;
			io::IReadFile* file = 0;
			file = FileSystem->createAndOpenFile( vertexShaderFile );
			if ( !file )
				init( dummy, vertexShaderBuf, fragmentShaderBuf, false );
			else{
				file ->drop();
				initFromFiles( dummy, vertexShaderFile, fragmentShaderFile, false );
			}
			useProgram();
			int texUnit = 0;
			setUniform( TEXTURE_UNIT, &texUnit );
		}

		void COGLES2Renderer2d::useTexture( bool param )
		{
			if ( param != UseTexture )
			{
				UseTexture = param;
				int dummy = param ? 1 : 0;
				setUniform( USE_TEXTURE, &dummy );
			}
		}

		void COGLES2Renderer2d::useAlphaTest( bool param )
		{
			if ( param != UseAlphaTest )
			{
				UseAlphaTest = param;
				int dummy = param ? 1 : 0;
				setUniform( ALPHA_TEST, &dummy );
			}
		}

		void COGLES2Renderer2d::setAlphaTestValue( float value )
		{
			if ( value != AlphaTestValue )
			{
				AlphaTestValue = value;
				setUniform( ALPHA_VALUE, &AlphaTestValue );
			}
		}

		void COGLES2Renderer2d::setOrthoMatrix( const core::matrix4 &matrix )
		{
			if ( matrix != OrthoMatrix )
			{
				OrthoMatrix = matrix;
				setUniform( ORTHO_MATRIX, OrthoMatrix.pointer() );
			}
		}
	}
}
#endif
