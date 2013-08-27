// Copyright (C) 2009-2010 Amundis
// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt
// and OpenGL ES driver implemented by Christian Stehno
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Irrlicht.h
#include "IrrCompileConfig.h"
#ifdef _IRR_COMPILE_WITH_OGLES2_

#include "COGLES2NormalMapRenderer.h"
#include "IGPUProgrammingServices.h"
#include "IShaderConstantSetCallBack.h"
#include "IVideoDriver.h"
#include "os.h"
#include "COGLES2Driver.h"
#include "COGLES2Utils.h"

#define MAX_LIGHTS 2

namespace irr
{
    namespace video
    {

        const char* const COGLES2NormalMapRenderer::sBuiltInShaderUniformNames[] =
        {
            "uMvpMatrix",
            "uLightPos",
            "uLightColor",
            "texture0",
            "texture1",
            0
        };

// Irrlicht Engine OGLES2 render path normal map vertex shader
        const c8 VertexShaderFile[] = "/mnt/sdcard/Irrlicht/COGLES2NormalMap.vsh";
        const c8 FragmentShaderFile[] = "/mnt/sdcard/Irrlicht/COGLES2NormalMap.fsh";
        
        const c8 VertexShaderBuf[] = 
"// Copyright (C) 2009-2010 Amundis\n"
"// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt\n"
"// and OpenGL ES driver implemented by Christian Stehno\n"
"// This file is part of the \"Irrlicht Engine\".\n"
"// For conditions of distribution and use, see copyright notice in Irrlicht.h\n"
"#define MAX_LIGHTS 2\n"
"\n"
"attribute vec4 inVertexPosition;\n"
"attribute vec4 inVertexColor;\n"
"attribute vec4 inTexCoord0;\n"
"attribute vec3 inVertexNormal;\n"
"attribute vec3 inVertexTangent;\n"
"attribute vec3 inVertexBinormal;\n"
"\n"
"uniform mat4 uMvpMatrix;\n"
"uniform vec4 uLightPos[MAX_LIGHTS];\n"
"uniform vec4 uLightColor[MAX_LIGHTS];\n"
"\n"
"varying vec4 varTexCoord;\n"
"varying vec3 varLightVector[MAX_LIGHTS];\n"
"varying vec4 varLightColor[MAX_LIGHTS];\n"
"\n"
"varying vec4 debug;\n"
"\n"
"void main(void)\n"
"{\n"
"	debug = vec4(inVertexNormal, 1.0);\n"
"	// transform position to clip space\n"
"	gl_Position = uMvpMatrix * inVertexPosition;\n"
"	\n"
"	// vertex - lightpositions\n"
"	vec4 tempLightVector0 = uLightPos[0] - inVertexPosition;\n"
"	vec4 tempLightVector1 = uLightPos[1] - inVertexPosition;\n"
"	\n"
"	// transform the light vector 1 with U, V, W\n"
"	varLightVector[0].x = dot(inVertexTangent,  tempLightVector0.xyz);\n"
"	varLightVector[0].y = dot(inVertexBinormal, tempLightVector0.xyz);\n"
"	varLightVector[0].z = dot(inVertexNormal,   tempLightVector0.xyz);\n"
"\n"
"	\n"
"	// transform the light vector 2 with U, V, W\n"
"	varLightVector[1].x = dot(inVertexTangent,  tempLightVector1.xyz);\n"
"	varLightVector[1].y = dot(inVertexBinormal, tempLightVector1.xyz);\n"
"	varLightVector[1].z = dot(inVertexNormal,   tempLightVector1.xyz);\n"
"\n"
"	// calculate attenuation of light 0\n"
"	varLightColor[0].w = 0.0;\n"
"	varLightColor[0].x = dot(tempLightVector0, tempLightVector0);\n"
"	varLightColor[0].x *= uLightColor[0].w;\n"
"	varLightColor[0] = vec4(inversesqrt(varLightColor[0].x));\n"
"	varLightColor[0] *= uLightColor[0];\n"
"	\n"
"	// normalize light vector 0\n"
"	varLightVector[0] = normalize(varLightVector[0]);\n"
"	\n"
"	// calculate attenuation of light 1\n"
"	varLightColor[1].w = 0.0;\n"
"	varLightColor[1].x = dot(tempLightVector1, tempLightVector1);\n"
"	varLightColor[1].x *= uLightColor[1].w;\n"
"	varLightColor[1] = vec4(inversesqrt(varLightColor[1].x));\n"
"	varLightColor[1] *= uLightColor[1];\n"
"	\n"
"	// normalize light vector 1\n"
"	varLightVector[1] = normalize(varLightVector[1]);\n"
"	\n"
"	// move out texture coordinates and original alpha value\n"
"	varTexCoord = inTexCoord0;\n"
"	varLightColor[0].a = inVertexColor.a;\n"
"}        \n";
    const c8 FragmentShaderBuf[] = 
"// Copyright (C) 2009-2010 Amundis\n"
"// Heavily based on the OpenGL driver implemented by Nikolaus Gebhardt\n"
"// and OpenGL ES driver implemented by Christian Stehno\n"
"// This file is part of the \"Irrlicht Engine\".\n"
"// For conditions of distribution and use, see copyright notice in Irrlicht.h\n"
"#define MAX_LIGHTS 2\n"
"\n"
"precision highp float;\n"
"precision highp int;\n"
"\n"
"uniform sampler2D texture0;\n"
"uniform sampler2D texture1;\n"
"\n"
"varying vec4 varTexCoord;\n"
"varying vec3 varLightVector[MAX_LIGHTS];\n"
"varying vec4 varLightColor[MAX_LIGHTS];\n"
"\n"
"varying vec4 debug;\n"
"\n"
"void main(void)\n"
"{\n"
"	// fetch color and normal map\n"
"	vec4 normalMap = texture2D(texture1, varTexCoord.xy) *  2.0 - 1.0;\n"
"	vec4 colorMap  = texture2D(texture0, varTexCoord.xy);\n"
"	\n"
"	// calculate color of light 0\n"
"	vec4 color = clamp(varLightColor[0], 0.0, 1.0) * dot(normalMap.xyz, normalize(varLightVector[0].xyz));\n"
"	\n"
"	// calculate color of light 1\n"
"	color += clamp(varLightColor[1], 0.0, 1.0) * dot(normalMap.xyz, normalize(varLightVector[1].xyz));\n"
"\n"
"	//luminance * base color\n"
"	color *= colorMap;\n"
"	color.a = varLightColor[0].a;\n"
"	\n"
"	gl_FragColor = color;\n"
"}\n";


//! Constructor
        COGLES2NormalMapRenderer::COGLES2NormalMapRenderer( video::COGLES2Driver* driver,
                                                            io::IFileSystem* fs, s32& outMaterialTypeNr, IMaterialRenderer* baseMaterial )
                : COGLES2SLMaterialRenderer( driver, fs, 0, baseMaterial, sBuiltInShaderUniformNames, UNIFORM_COUNT ), CompiledShaders( true )
        {

#ifdef _DEBUG
            setDebugName( "COGLES2NormalMapRenderer" );
#endif

            // set this as callback. We could have done this in
            // the initialization list, but some compilers don't like it.

            CallBack = this;

            // check if already compiled normal map shaders are there.

            video::IMaterialRenderer* renderer = driver->getMaterialRenderer( EMT_NORMAL_MAP_SOLID );

            if ( renderer )
            {
                // use the already compiled shaders
                video::COGLES2NormalMapRenderer* nmr = reinterpret_cast<video::COGLES2NormalMapRenderer*>( renderer );
                CompiledShaders = false;

                Program = nmr->Program;

                UniformInfo   = nmr->UniformInfo;
                AttributeInfo = nmr->AttributeInfo;

                outMaterialTypeNr = driver->addMaterialRenderer( this );
            }
            else
            {
                // compile shaders on our own
				io::IReadFile* file = 0;
				file = FileSystem->createAndOpenFile( VertexShaderFile );
				if ( !file )
					init( outMaterialTypeNr, VertexShaderBuf, FragmentShaderBuf );
				else{
					file ->drop();
                    initFromFiles( outMaterialTypeNr, VertexShaderFile, FragmentShaderFile );
				}
                useProgram();
                int dummy = 0;
                setUniform( TEXTURE_UNIT0, &dummy );
                dummy = 1;
                setUniform( TEXTURE_UNIT1, &dummy );
            }

            // fallback if compilation has failed
            if ( -1 == outMaterialTypeNr )
                outMaterialTypeNr = driver->addMaterialRenderer( this );
        }

        COGLES2NormalMapRenderer::~COGLES2NormalMapRenderer()
        {
            if ( CallBack == this )
                CallBack = 0;
            if ( !CompiledShaders )
            {
                // prevent this from deleting shaders we did not create
                Program = 0;
            }
        }

//! Returns the render capability of the material.
        s32 COGLES2NormalMapRenderer::getRenderCapability() const
        {
            if ( Driver->queryFeature( video::EVDF_ARB_FRAGMENT_PROGRAM_1 ) &&
                 Driver->queryFeature( video::EVDF_ARB_VERTEX_PROGRAM_1 ) )
                return 0;

            return 1;
        }


//! Called by the engine when the vertex and/or pixel shader constants for an
//! material renderer should be set.
        void COGLES2NormalMapRenderer::OnSetConstants( IMaterialRendererServices* services, s32 userData )
        {
            video::IVideoDriver* driver = services->getVideoDriver();

            // set transposed worldViewProj matrix
            core::matrix4 worldViewProj( driver->getTransform( video::ETS_PROJECTION ) );
            worldViewProj *= driver->getTransform( video::ETS_VIEW );
            worldViewProj *= driver->getTransform( video::ETS_WORLD );
            setUniform( MVP_MATRIX, worldViewProj.pointer() );

            // here we fetch the fixed function lights from the driver
            // and set them as constants

            u32 cnt = driver->getDynamicLightCount();

            // Load the inverse world matrix.
            core::matrix4 invWorldMat;
            driver->getTransform( video::ETS_WORLD ).getInverse( invWorldMat );

            float lightPosition[4*MAX_LIGHTS];
            float lightColor[4*MAX_LIGHTS];

            for ( u32 i = 0; i < MAX_LIGHTS; ++i )
            {
                video::SLight light;

                if ( i < cnt )
                    light = driver->getDynamicLight( i );
                else
                {
                    light.DiffuseColor.set( 0, 0, 0 ); // make light dark
                    light.Radius = 1.0f;
                }

                light.DiffuseColor.a = 1.0f / ( light.Radius * light.Radius ); // set attenuation

                // Transform the light by the inverse world matrix to get it into object space.
                invWorldMat.transformVect( light.Position );

                memcpy( lightPosition + i*4, &light.Position, sizeof( float )*4 );
                memcpy( lightColor + i*4, &light.DiffuseColor, sizeof( float )*4 );
            }
            setUniform( LIGHT_POSITION, lightPosition, MAX_LIGHTS );
            setUniform( LIGHT_COLOR, lightColor, MAX_LIGHTS );
        }


    } // end namespace video
} // end namespace irr


#endif

