// Copyright (C) 2009-2010 Amundis
// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt
// and OpenGL ES driver implemented by Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Irrlicht.h
#include "COGLES2FixedPipelineShader.h"

#ifdef _IRR_COMPILE_WITH_OGLES2_

#include "COGLES2SLMaterialRenderer.h"
#include "COGLES2Utils.h"

#ifdef _IRR_COMPILE_WITH_ANDROID_DEVICE_
#include <android/log.h>
#endif

namespace irr
{
    namespace video
    {

        const char* const COGLES2FixedPipelineShader::sBuiltInShaderUniformNames[] =
        {
            "uRenderMode",
			"uRenderModeF",
            "uMvpMatrix",
            "uWorldMatrix",
            "uNormalize",
            "uEyePos",
            "uUseLight",
            "uLightPosition",
            "uLightAmbient",
            "uLightDiffuse",
            "uLightSpecular",
            "uLightDirection",
            "uLightAttenuation",
            "uLightExponent",
            "uLightCutoff",
            "uAmbientColor",
            "uLighting",
            "uMaterialAmbient",
            "uMaterialEmission",
            "uMaterialDiffuse",
            "uMaterialSpecular",
            "uMaterialShininess",
            "uColorMaterial",
            "uUseTexture",
            "uTextureMatrix",
            "uUseTexMatrix",
            "uClip",
            "uClipPlane",
            "uAlphaTest",
            "uAlphaValue",
            "uFog",
            "uFogType",
            "uFogColor",
            "uFogStart",
            "uFogEnd",
            "uFogDensity",
            "uTextureUnit0",
            "uTextureUnit1",
			"uUseTextureF",
            0
        };

        const c8 VertexShaderFile[] = "/mnt/sdcard/Irrlicht/COGLES2FixedPipeline.vsh";
        const c8 FragmentShaderFile[] = "/mnt/sdcard/Irrlicht/COGLES2FixedPipeline.fsh";
        
        const c8 VertexShaderBuf[] = 
"// Copyright (C) 2009-2010 Amundis\n"
"// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt\n"
"// and OpenGL ES driver implemented by Christian Stehno\n"
"// This file is part of the \"Irrlicht Engine\".\n"
"// For conditions of distribution and use, see copyright notice in Irrlicht.h\n"
"#define MAX_TEXTURE_UNITS 4\n"
"#define MAX_LIGHTS 8\n"
"\n"
"#define SphereMap        10\n"
"#define Reflection2Layer 11\n"
"\n"
"const vec4 red   = vec4(1.0, 0.0, 0.0, 1.0);\n"
"const vec4 green = vec4(0.0, 1.0, 0.0, 1.0);\n"
"const vec4 blue  = vec4(0.0, 0.0, 1.0, 1.0);\n"
"const vec4 white = vec4(1.0);\n"
"const vec4 black = vec4(0.0);\n"
"\n"
"/* Vertex Attributes */\n"
" \n"
"attribute vec4 inVertexPosition;\n"
"attribute vec4 inVertexColor;\n"
"attribute vec4 inTexCoord0;\n"
"attribute vec4 inTexCoord1;\n"
"attribute vec3 inVertexNormal;\n"
"\n"
"uniform int uRenderMode;\n"
"\n"
"/* Matrix Uniforms */\n"
"\n"
"uniform mat4 uMvpMatrix;\n"
"uniform mat4 uWorldMatrix;\n"
"\n"
"uniform int uNormalize;\n"
"uniform vec3 uEyePos;\n"
"\n"
"/* Light Uniforms */\n"
"\n"
"uniform int   uUseLight         [MAX_LIGHTS];\n"
"uniform vec4  uLightPosition    [MAX_LIGHTS];\n"
"uniform vec4  uLightAmbient     [MAX_LIGHTS];\n"
"uniform vec4  uLightDiffuse     [MAX_LIGHTS];\n"
"#ifdef USE_SPECULAR\n"
"uniform vec4  uLightSpecular    [MAX_LIGHTS];\n"
"#endif\n"
"#ifdef USE_LIGHT_CUTOFF\n"
"uniform vec3  uLightDirection   [MAX_LIGHTS];\n"
"uniform float uLightCutoff      [MAX_LIGHTS];\n"
"uniform float uLightExponent    [MAX_LIGHTS];\n"
"#endif\n"
"uniform vec3  uLightAttenuation [MAX_LIGHTS];\n"
"uniform vec4  uAmbientColor;\n"
"uniform int  uLighting;\n"
"\n"
"/* Material Uniforms */\n"
"uniform vec4  uMaterialAmbient;\n"
"uniform vec4  uMaterialEmission;\n"
"uniform vec4  uMaterialDiffuse;\n"
"uniform vec4  uMaterialSpecular;\n"
"uniform float uMaterialShininess;\n"
"uniform int   uColorMaterial;\n"
"\n"
"#define ECM_NONE     0\n"
"#define ECM_DIFFUSE  1\n"
"#define ECM_AMBIENT  2\n"
"#define ECM_EMISSIVE 3\n"
"#define ECM_SPECULAR 4\n"
"#define ECM_DIFFUSE_AND_AMBIENT 5\n"
"\n"
"/* Texture Uniforms */\n"
"uniform int uUseTexture    [MAX_TEXTURE_UNITS];\n"
"uniform mat4 uTextureMatrix [MAX_TEXTURE_UNITS];\n"
"uniform int uUseTexMatrix  [MAX_TEXTURE_UNITS];\n"
"\n"
"/* Clip Plane Uniforms */\n"
"uniform int uClip;\n"
"uniform vec4 uClipPlane;\n"
"varying float varClipDist;\n"
"\n"
"/* Varyings */\n"
"\n"
"varying vec4 varTexCoord[MAX_TEXTURE_UNITS];\n"
"varying vec4 varVertexColor;\n"
"varying float eyeDist;\n"
"\n"
"/* shader variables */\n"
"\n"
"vec3 gNormal;\n"
"vec3 gWorldPos;\n"
"vec4 gColor;\n"
"\n"
"struct material {\n"
"   vec4    Ambient;\n"
"   vec4    Diffuse;\n"
"   vec4    Specular;\n"
"   vec4    Emission;\n"
"   float   Shininess;\n"
"} ;\n"
"\n"
"material gMaterial;\n"
"\n"
"vec4 lightEquation(int lidx)\n"
"{		\n"
"	vec4 color = vec4(0.0);\n"
"	\n"
"	float att = 1.0;\n"
"	vec3 lightDir;\n"
"	\n"
"	\n"
"	if( uLightPosition[lidx].w == 0.0) // Directional light\n"
"	{\n"
"		lightDir = -uLightPosition[lidx].xyz;\n"
"	}\n"
"	else\n"
"	{\n"
"		lightDir = uLightPosition[lidx].xyz - inVertexPosition.xyz;\n"
"		att = 1.0 / (uLightAttenuation[lidx].y * length(lightDir));\n"
"		lightDir = normalize(lightDir);\n"
"		\n"
"#ifdef USE_LIGHT_CUTOFF\n"
"		if(uLightCutoff[lidx] < 180.0)\n"
"		{\n"
"			// compute spot factor\n"
"			float spotEffect = dot(-lightDir, uLightDirection[lidx]);\n"
"			if( spotEffect >= cos( radians( uLightCutoff[lidx])))\n"
"				spotEffect = pow( spotEffect, uLightExponent[lidx]);\n"
"			else\n"
"				spotEffect = 0.0;\n"
"			att *= spotEffect;\n"
"		}\n"
"#endif\n"
"	}\n"
"	\n"
"	if(att >= 0.0 )\n"
"	{\n"
"		color += uLightAmbient[lidx] * gMaterial.Ambient;\n"
"		\n"
"		//Compute cos(Light, Normal)\n"
"		float NdotL = max(dot(normalize(gNormal), lightDir), 0.0);\n"
"		color += NdotL * uLightDiffuse[lidx] * gMaterial.Diffuse;\n"
"		\n"
"		//Compute cos(hvec, Normal)\n"
"#ifdef USE_SPECULAR\n"
"		vec3 hvec = normalize(lightDir + vec3(0.0, 0.0, 1.0));\n"
"		float NdotH = dot(gNormal, hvec);\n"
"		if(NdotH > 0.0)\n"
"		{\n"
"			color += pow(NdotH, uMaterialShininess) * uLightSpecular[lidx] * gMaterial.Specular;\n"
"		}\n"
"#endif\n"
"		color *= att;\n"
"	}\n"
"	return color;\n"
"}\n"
"\n"
"vec4 computeLighting(void)\n"
"{\n"
"	vec4 color = gMaterial.Emission + gMaterial.Ambient * uAmbientColor;\n"
"\n"
"	for ( int i = 0 ; i < MAX_LIGHTS; ++i)\n"
"	{\n"
"		if ( uUseLight[i] != 0)\n"
"		{\n"
"			color += lightEquation(i) ;\n"
"		}\n"
"	}\n"
"	color.a = gMaterial.Diffuse.a;\n"
"	return color;\n"
"}\n"
"\n"
"void ReplaceColorMaterial(void)\n"
"{\n"
"	gMaterial.Ambient = uMaterialAmbient;\n"
"	gMaterial.Diffuse = uMaterialDiffuse;\n"
"	gMaterial.Emission = uMaterialEmission;\n"
"	gMaterial.Specular = uMaterialSpecular;\n"
"	gMaterial.Shininess = uMaterialShininess;\n"
"\n"
"	if(uColorMaterial == ECM_DIFFUSE)\n"
"		gMaterial.Diffuse = gColor;\n"
"	else if(uColorMaterial == ECM_AMBIENT)\n"
"		gMaterial.Ambient = gColor;\n"
"	else if(uColorMaterial == ECM_DIFFUSE_AND_AMBIENT)\n"
"	{\n"
"		gMaterial.Diffuse = gColor;\n"
"		gMaterial.Ambient = gColor;\n"
"	}	\n"
"	else if(uColorMaterial == ECM_EMISSIVE)\n"
"		gMaterial.Emission = gColor;\n"
"	else if(uColorMaterial == ECM_SPECULAR)\n"
"		gMaterial.Specular = gColor;\n"
"}\n"
"\n"
"void main(void)\n"
"{\n"
"	gl_Position = uMvpMatrix * inVertexPosition;\n"
"	\n"
"	gWorldPos = (uWorldMatrix * inVertexPosition).xyz;\n"
"	\n"
"	gColor = inVertexColor.bgra;\n"
"	\n"
"	gNormal = inVertexNormal.xyz;\n"
"	if(uNormalize != 0)\n"
"		gNormal = normalize(gNormal);\n"
"	\n"
"	ReplaceColorMaterial();\n"
"	if(uLighting != 0)\n"
"		varVertexColor = computeLighting();\n"
"	else\n"
"		varVertexColor = gColor;\n"
"	\n"
"	for(int i = 0; i < MAX_TEXTURE_UNITS; ++i)\n"
"		varTexCoord[i] = vec4(0.0);\n"
"	\n"
"	if( uUseTexture[0] != 0)\n"
"	{\n"
"		if(uRenderMode == SphereMap || uRenderMode == Reflection2Layer)\n"
"		{\n"
"			vec3 eyeDir = normalize(inVertexPosition.xyz - uEyePos);\n"
"			vec3 reflection = reflect(eyeDir, gNormal);\n"
"			float m = 2.0 * sqrt(reflection.x * reflection.x +\n"
"								 reflection.y * reflection.y +\n"
"								 (reflection.z + 1.0) * (reflection.z + 1.0));\n"
"			varTexCoord[0] = vec4((reflection.x / m + 0.5), (reflection.y / m + 0.5), 0.0, 0.0); \n"
"		}\n"
"		else\n"
"		{\n"
"			varTexCoord[0] = inTexCoord0;\n"
"			if(uUseTexMatrix[0] != 0)\n"
"				varTexCoord[0] *= uTextureMatrix[0];\n"
"		}\n"
"	}\n"
"	if(uUseTexture[1] != 0)\n"
"	{\n"
"		varTexCoord[1] = inTexCoord1;\n"
"		if(uUseTexMatrix[1] != 0)\n"
"			varTexCoord[1] *= uTextureMatrix[1];\n"
"	}\n"
"	\n"
"	eyeDist = length(uEyePos);\n"
"	\n"
"	varClipDist = uClip != 0 ? dot(gWorldPos, uClipPlane.xyz)-uClipPlane.w : 0.0;\n"
"	\n"
"	varVertexColor.rgb  = clamp(varVertexColor.rgb, 0.0, 1.0);\n"
"	varVertexColor.a = gColor.a;\n"
"}\n";

	const c8 FragmentShaderBuf[] = 
//"#ifdef GL_ES\n"
"	precision mediump float;\n"
"	precision mediump int;\n"
//"#endif\n"
"\n"
"// Copyright (C) 2009-2010 Amundis\n"
"// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt\n"
"// and OpenGL ES driver implemented by Christian Stehno\n"
"// This file is part of the \"Irrlicht Engine\".\n"
"// For conditions of distribution and use, see copyright notice in Irrlicht.h\n"
"#define MAX_TEXTURE_UNITS 4\n"
"#define FOG_EXP 1\n"
"#define FOG_LINEAR 2\n"
"\n"
"#define TwoD             24\n"
"#define Solid            0\n"
"#define Solid2Layer      1\n"
"#define LightMap         2\n"
"#define DetailMap		 9\n"
"#define SphereMap		 10\n"
"#define Reflection2Layer 11\n"
"#define TransparentAlphaChannel 13\n"
"#define TransparentVertexAlpha 15\n"
"\n"
"vec4 red   = vec4(1.0, 0.0, 0.0, 1.0);\n"
"vec4 green = vec4(0.0, 1.0, 0.0, 1.0);\n"
"vec4 blue  = vec4(0.0, 0.0, 1.0, 1.0);\n"
"\n"
"\n"
"/* Varyings */\n"
"\n"
"varying vec4 varTexCoord[MAX_TEXTURE_UNITS];\n"
"varying vec4 varVertexColor;\n"
"varying float eyeDist;\n"
"varying float varClipDist;\n"
"\n"
"/* Uniforms */\n"
"\n"
"uniform int uRenderModeF;\n"
"\n"
"uniform int  uAlphaTest;\n"
"uniform float uAlphaValue;\n"
"\n"
"/* Fog Uniforms */\n"
"\n"
"uniform int   uFog;\n"
"uniform int   uFogType;\n"
"uniform vec4  uFogColor;\n"
"uniform float uFogStart;\n"
"uniform float uFogEnd;\n"
"uniform float uFogDensity;\n"
"\n"
"/* Texture Uniforms */\n"
"\n"
"uniform sampler2D uTextureUnit0;\n"
"uniform sampler2D uTextureUnit1;\n"
"uniform int      uUseTextureF[MAX_TEXTURE_UNITS];\n"
"\n"
"vec4 render2D(void)\n"
"{\n"
"	vec4 color = varVertexColor;\n"
"	vec4 texel = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	if(uUseTextureF[0] != 0)\n"
"	{\n"
"		color *= texel;\n"
"	}\n"
"	return color;\n"
"}\n"
"\n"
"vec4 renderSolid(void)\n"
"{\n"
"	vec4 color = varVertexColor;\n"
"	vec4 texel = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	if(uUseTextureF[0] != 0)\n"
"		color *= texel;\n"
"	return color;\n"
"}\n"
"\n"
"vec4 renderTransparentVertexAlpha(void)\n"
"{\n"
"	vec4 color = renderSolid();\n"
"	color.a = varVertexColor.a;\n"
"	return color;\n"
"}\n"
"\n"
"vec4 renderTransparentAlphaChannel(void)\n"
"{\n"
"	vec4 texel = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	vec4 color = texel * varVertexColor;\n"
"	color.a = texel.a;\n"
"	return color;\n"
"}\n"
"\n"
"vec4 render2LayerSolid(void)\n"
"{\n"
"	float blendFactor = varVertexColor.a;\n"
"	vec4 texel0 = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	vec4 texel1 = texture2D(uTextureUnit1, varTexCoord[1].xy);\n"
"	vec4 color = texel0 * blendFactor + texel1 * ( 1.0 - blendFactor );\n"
"	return color;\n"
"}\n"
"\n"
"vec4 renderLightMap(void)\n"
"{\n"
"	vec4 texel0  = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	vec4 texel1  = texture2D(uTextureUnit1, varTexCoord[1].xy);\n"
"	vec4 color   = texel0 * texel1 * 4.0;\n"
"	color.a = texel0.a * texel0.a;\n"
"	return color;\n"
"}\n"
"\n"
"vec4 renderDetailMap(void)\n"
"{\n"
"	vec4 texel0  = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	vec4 texel1  = texture2D(uTextureUnit1, varTexCoord[1].xy);\n"
"	vec4 color   = texel0;\n"
"	color += texel1 - 0.5;\n"
"	return color;\n"
"}\n"
"\n"
"vec4 renderReflection2Layer(void)\n"
"{\n"
"	vec4 color = varVertexColor;\n"
"	vec4 texel0 = texture2D(uTextureUnit0, varTexCoord[0].xy);\n"
"	vec4 texel1 = texture2D(uTextureUnit1, varTexCoord[1].xy);\n"
"	color *=  texel0 * texel1;\n"
"	return color;\n"
"}\n"
"\n"
"float ComputeFog()\n"
"{\n"
"	float factor = 1.0;\n"
"	if(uFogType == FOG_LINEAR)\n"
"	{\n"
"		factor = (uFogEnd - eyeDist) / (uFogEnd - uFogStart);\n"
"	}\n"
"	else if(uFogType == FOG_EXP)\n"
"	{\n"
"		 factor = exp(-(eyeDist * uFogDensity));\n"
"	}\n"
"	else //uFogType == FOG_EXP2\n"
"	{\n"
"		factor = eyeDist * uFogDensity;\n"
"		factor = exp(-(factor * factor)) ;\n"
"	}\n"
"	factor = clamp(factor, 0.0, 1.0);\n"
"	return factor;\n"
"}\n"
"\n"
"void main (void)\n"
"{\n"
"	if(varClipDist < 0.0)\n"
"		discard;\n"
"	\n"
"	if( uRenderModeF == TwoD)\n"
"	    gl_FragColor = render2D();\n"
"	else if( uRenderModeF == Solid)\n"
"	    gl_FragColor = renderSolid();\n"
"	else if(uRenderModeF == LightMap)\n"
"		gl_FragColor = renderLightMap();\n"
"	else if(uRenderModeF == DetailMap)\n"
"		gl_FragColor = renderDetailMap();\n"
"	else if(uRenderModeF == SphereMap)\n"
"		gl_FragColor = renderSolid();\n"
"	else if(uRenderModeF == Reflection2Layer)\n"
"		gl_FragColor = renderReflection2Layer();\n"
"	else if(uRenderModeF == TransparentVertexAlpha)\n"
"		gl_FragColor = renderTransparentVertexAlpha();\n"
"	else if(uRenderModeF == TransparentAlphaChannel)\n"
"		gl_FragColor = renderTransparentAlphaChannel();\n"
"	else\n"
"		gl_FragColor = vec4(0.0, 1.0, 1.0, 1.0);\n"
"		\n"
"	//gl_FragColor = varVertexColor;\n"
"\n"
"	if(uFog != 0)\n"
"	{\n"
"		float fogFactor = ComputeFog();\n"
"		gl_FragColor = gl_FragColor * fogFactor + uFogColor * (1.0 - fogFactor);\n"
"	}\n"
"			\n"
"	if(uAlphaTest != 0 && uAlphaValue > gl_FragColor.a)\n"
"		discard;\n"
"	\n"
"}\n";
        

        COGLES2FixedPipelineShader::COGLES2FixedPipelineShader( video::COGLES2Driver *driver, io::IFileSystem* fs )
                : COGLES2SLMaterialRenderer( driver, fs, 0, 0, sBuiltInShaderUniformNames, UNIFORM_COUNT ), Normalize( 0 ), AlphaTest( 0 ), AlphaValue( 0.f ),
                AlphaFunction( ALPHA_GREATER ), Lighting( 0 ), Fog( 0 ), FogType( 0 ), FogStart( 0.f ), FogEnd( 0.f ), FogDensity( 0.f ),
                ColorMaterial( 0 ), MaterialShininess( 0.f ), RenderMode( EMT_SOLID )
        {
            s32 dummy;
			io::IReadFile* file = 0;
			file = FileSystem->createAndOpenFile( VertexShaderFile );
			if ( !file )
				init( dummy, VertexShaderBuf, FragmentShaderBuf, false );
			else{
				file ->drop();
#ifdef _IRR_COMPILE_WITH_ANDROID_DEVICE_
				__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "load fixed pipeline shader from /sdcard/Irrlicht");
#endif
	            initFromFiles( dummy, VertexShaderFile, FragmentShaderFile, false );
			}
            initData();
        };

        void COGLES2FixedPipelineShader::reload()
        {
            reloadFromFiles( VertexShaderFile, FragmentShaderFile );
            //initData();
        }

        void COGLES2FixedPipelineShader::initData()
        {
            for ( size_t i = 0; i < MAX_TEXTURE_UNITS; ++i )
                TextureUnits[i] = i;
            memset( UseTexture, 0, sizeof( UseTexture ) );
            memset( UseTexMatrix, 0, sizeof( UseTexMatrix ) );
            memset( UseLight, 0, sizeof( UseLight ) );
            memset( LightPosition, 0, sizeof( LightPosition ) );
            memset( LightAmbient, 0, sizeof( LightAmbient ) );
            memset( LightDiffuse, 0, sizeof( LightDiffuse ) );
            memset( LightSpecular, 0, sizeof( LightSpecular ) );
            memset( LightDirection, 0, sizeof( LightDirection ) );
            memset( LightAttenuation, 0, sizeof( LightAttenuation ) );
            memset( LightExponent, 0, sizeof( LightExponent ) );
            memset( LightCutoff, 0, sizeof( LightCutoff ) );
            memset( &AmbientColor, 0, sizeof( AmbientColor ) );
            memset( FogColor, 0, sizeof( FogColor ) );
            memset( &ClipPlane, 0, sizeof( ClipPlane ) );
            memset( &MaterialAmbient, 0, sizeof( MaterialAmbient ) );
            memset( &MaterialEmission, 0, sizeof( MaterialEmission ) );
            memset( &MaterialDiffuse, 0, sizeof( MaterialDiffuse ) );
            memset( &MaterialSpecular, 0, sizeof( MaterialSpecular ) );
        }

        bool COGLES2FixedPipelineShader::OnRender( IMaterialRendererServices* service, E_VERTEX_TYPE vtxtype )
        {
            Driver->testGLError();
            bool statusOk = true;

            /* Matrices Upload */
            core::matrix4 world = Driver->getTransform( ETS_WORLD );
            //statusOk &= setVertexShaderConstant( "uWorldMatrix", world.pointer(), 16 );
            //glUniformMatrix4fv(locWorldMatrix, 1, false, world.pointer() );
            setUniform( WORLD_MATRIX, world.pointer() );

            core::matrix4 worldViewProj = Driver->getTransform( video::ETS_PROJECTION );
            worldViewProj *= Driver->getTransform( video::ETS_VIEW );
            worldViewProj *= Driver->getTransform( ETS_WORLD );
            //statusOk &= setVertexShaderConstant( "uMvpMatrix", worldViewProj.pointer(), 16 );
            //glUniformMatrix4fv(locMvpMatrix, 1, false, worldViewProj.pointer());
            setUniform( MVP_MATRIX, worldViewProj.pointer() );

            /* Textures Upload */
            //statusOk &= setVertexShaderConstant("uTextureUnit", (f32*)TextureUnits, MAX_TEXTURE_UNITS);
            //statusOk &= setVertexShaderConstant( "uTextureUnit0", ( f32* ) & TextureUnits[0], 1 );
            setUniform( TEXTURE_UNIT0, &TextureUnits[0] );
            //statusOk &= setVertexShaderConstant( "uTextureUnit1", ( f32* ) & TextureUnits[1], 1 );
            setUniform( TEXTURE_UNIT1, &TextureUnits[1] );

            //statusOk &= setVertexShaderConstant( "uUseTexture", ( f32* )UseTexture, MAX_TEXTURE_UNITS );
            setUniform( USE_TEXTURE, UseTexture, MAX_TEXTURE_UNITS );
			setUniform( USE_TEXTUREF, UseTexture, MAX_TEXTURE_UNITS );
            //statusOk &= setVertexShaderConstant( "uUseTexMatrix", ( f32* )UseTexMatrix, MAX_TEXTURE_UNITS );
            setUniform( USE_TEXTURE_MATRIX, UseTexMatrix, MAX_TEXTURE_UNITS );
            //statusOk &= setVertexShaderConstant( "uTextureMatrix", ( f32* )TextureMatrix, MAX_TEXTURE_UNITS * 16 );
            setUniform( TEXTURE_MATRIX, TextureMatrix, MAX_TEXTURE_UNITS );
            core::matrix4 invWorld;

            /* Lights (in Object Space) Upload */
            if ( Lighting )
            {
                u32 cnt = Driver->getDynamicLightCount();
                Driver->getTransform( ETS_WORLD ).getInverse( invWorld );
                for ( size_t i = 0; i < MAX_LIGHTS; ++i )
                {

                    if ( i < cnt )
                    {
                        UseLight[i] = 1;
                        video::SLight light;
                        light = Driver->getDynamicLight( i );

                        switch ( light.Type )
                        {
                            case ELT_DIRECTIONAL:
                                invWorld.rotateVect(( f32* )&LightPosition[i], light.Direction );
                                LightPosition[i].data[4] = 0.0;
                                break;
                            case ELT_SPOT:
                                invWorld.rotateVect( LightDirection[i], light.Direction );
                                LightExponent[i] = light.Falloff;
                                LightCutoff[i]   = light.OuterCone;
                                //no break on purpose !
                            case ELT_POINT:
                                invWorld.transformVect(( f32* )&LightPosition[i], light.Position );
                                LightPosition[i].data[4] = 1.0;
                                LightAttenuation[i] = light.Attenuation;
                                break;

                            default:
                                UseLight[i] = 0;
                                break;
                        }

                        LightAmbient[i]  = light.AmbientColor;
                        LightDiffuse[i]  = light.DiffuseColor;
                        LightSpecular[i] = light.SpecularColor;
                        LightAttenuation[i] = light.Attenuation;
                    }
                    else
                    {
                        UseLight[i] = 0;
                    }
                }
                //statusOk &= setVertexShaderConstant( "uLighting", ( f32* ) & Lighting, 1 );
                //statusOk &= setVertexShaderConstant( "uUseLight", ( f32* )UseLight, MAX_LIGHTS );
                setUniform( USE_LIGHT, UseLight, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightPosition", ( f32* )LightPosition,    MAX_LIGHTS * 4 );
                setUniform( LIGHT_POSITION, LightPosition, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightDirection", ( f32* )LightDirection,   MAX_LIGHTS * 3 );
                setUniform( LIGHT_DIRECTION, LightDirection, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightAmbient", ( f32* )LightAmbient,     MAX_LIGHTS * 4 );
                setUniform( LIGHT_AMBIENT, LightAmbient, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightDiffuse", ( f32* )LightDiffuse,     MAX_LIGHTS * 4 );
                setUniform( LIGHT_DIFFUSE, LightDiffuse, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightSpecular", ( f32* )LightSpecular,    MAX_LIGHTS * 4 );
                setUniform( LIGHT_SPECULAR, LightSpecular, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightAttenuation", ( f32* )LightAttenuation, MAX_LIGHTS * 3 );
                setUniform( LIGHT_ATTENUATION, LightAttenuation, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightExponent", LightExponent, MAX_LIGHTS );
                setUniform( LIGHT_EXPONENT, LightExponent, MAX_LIGHTS );
                //statusOk &= setVertexShaderConstant( "uLightCutoff",   LightCutoff,   MAX_LIGHTS );
                setUniform( LIGHT_CUTOFF, LightCutoff, MAX_LIGHTS );

                AmbientColor = Driver->getAmbientLight();
                setUniform( LIGHT_AMBIENT, &AmbientColor );
            }

            /* Fog */
            /* statusOk &= setVertexShaderConstant( "uFog", ( f32* ) & Fog, 1 );
             statusOk &= setVertexShaderConstant( "uFogType", ( f32* ) & FogType, 1 );
             statusOk &= setVertexShaderConstant( "uFogColor", FogColor, 4 );
             statusOk &= setVertexShaderConstant( "uFogStart", &FogStart, 1 );
             statusOk &= setVertexShaderConstant( "uFogEnd", &FogEnd, 1 );
             statusOk &= setVertexShaderConstant( "uFogDensity", &FogDensity, 1 );*/

            /* Clip Plane */
            u32 cnt = Driver->getClipPlaneCount();
            if ( cnt > 0 )
            {
                Clip = 1;
                ClipPlane = Driver->getClipPlane( 0 );
            }
            else
            {
                Clip = 0;
            }

            /* Eye/Camera Position in ObjectSpace */
            if ( Clip || RenderMode == 10 || RenderMode == 11 ) // Need clipping or reflection
            {
                if ( !Lighting )
                    Driver->getTransform( ETS_WORLD ).getInverse( invWorld );
                core::vector3df viewPos( 0.0f, 0.0f, 0.0f );
                core::matrix4 inverseView;
                Driver->getTransform( video::ETS_VIEW ).getInverse( inverseView );
                inverseView.transformVect( viewPos );
                invWorld.transformVect( viewPos );
                //setVertexShaderConstant( "uEyePos", &viewPos.X, 3 );
                setUniform( EYE_POSITION, &viewPos.X );
            }

            //statusOk &= setVertexShaderConstant( "uClip", ( f32* ) & Clip );
            setUniform( CLIP, &Clip );
            //statusOk &= setVertexShaderConstant( "uClipPlane", ( f32* ) & ClipPlane );
            setUniform( CLIP_PLANE, &ClipPlane );
            //statusOk &= setVertexShaderConstant( "uRenderMode", ( f32* ) & RenderMode );
            setUniform( RENDER_MODE, &RenderMode );
			setUniform( RENDER_MODEF, &RenderMode );
            //statusOk &= setVertexShaderConstant( "uNormalize", ( f32* ) & Normalize, 1 );

            return statusOk ;
        };

        void COGLES2FixedPipelineShader::setMaterial( const SMaterial &material )
        {
            if (Fog != static_cast<int>(material.FogEnable))
            {
                Fog = material.FogEnable;
                setUniform( FOG, &Fog );
            }
            if (Lighting != static_cast<int>(material.Lighting))
            {
                Lighting  = material.Lighting;
                setUniform( LIGHTING, &Lighting );
#ifdef _IRR_COMPILE_WITH_ANDROID_DEVICE_
				char Buf1[128];
				sprintf(Buf1,"set lighting  %d",Lighting);
				__android_log_print(ANDROID_LOG_INFO, "Irrlicht", Buf1);
#endif
            }

            if (Normalize != static_cast<float>(material.NormalizeNormals))
            {
                Normalize = material.NormalizeNormals;
                setUniform( NORMALIZE, &Normalize );
            }

            for ( size_t i = 0; i < MAX_TEXTURE_UNITS; ++i )
            {
                UseTexture[i] = material.getTexture( i ) != 0;
                if ( UseTexture[i] )
                {
                    UseTexMatrix[i] = false;
                    core::matrix4 texMat = material.getTextureMatrix( i );
                    if ( !texMat.isIdentity() )
                    {
                        UseTexMatrix[i] = true;
                        memcpy( &TextureMatrix[i], texMat.pointer(), sizeof( mat4 ) );
                    }
                }
            }


            if ( ColorMaterial != material.ColorMaterial )
            {
                ColorMaterial = material.ColorMaterial;
                setUniform( COLOR_MATERIAL, &ColorMaterial );

            }
            if ( MaterialAmbient != material.AmbientColor )
            {
                MaterialAmbient   = material.AmbientColor;
                setUniform( MATERIAL_AMBIENT, &MaterialAmbient );
            }
            if ( MaterialEmission != material.EmissiveColor )
            {
                MaterialEmission  = material.EmissiveColor;
                setUniform( MATERIAL_EMISSION, &MaterialEmission );
            }
            if ( MaterialDiffuse != material.DiffuseColor )
            {
                MaterialDiffuse   = material.DiffuseColor;
                setUniform( MATERIAL_DIFFUSE, &MaterialDiffuse );
            }
            if ( MaterialSpecular != material.SpecularColor )
            {
                MaterialSpecular  = material.SpecularColor;
                setUniform( MATERIAL_SPECULAR, &MaterialSpecular );
            }
            if ( MaterialShininess != material.Shininess )
            {
                MaterialShininess = material.Shininess;
                setUniform( MATERIAL_SHININESS, &MaterialShininess );
            }
        }

    }
}

#endif //_IRR_COMPILE_WITH_OGLES2_
