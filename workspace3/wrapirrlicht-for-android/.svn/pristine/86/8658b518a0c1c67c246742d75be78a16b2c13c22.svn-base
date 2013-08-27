#ifndef _SRPIRRLICHTENGINEBASICMODULE_IRR
#define _SRPIRRLICHTENGINEBASICMODULE_IRR

#include "irrlicht.h"
using namespace irr;

extern void *SRPAPI IrrSceneNodeClass_GetIrrSceneManager(void *Object);

extern void IrrSceneNodeClass_ChangeParent(struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr);
extern void *IrrAnimatedMeshClass_GetMeshObject(VS_CHAR *FileName,VS_UUID *CreateObjectID,VS_INT32 *MeshNum);
extern scene::IMesh* IrrMeshClass_GetIrrMesh(void *MeshObject,VS_INT32 MeshNum);
extern void *IrrTextureClass_GetTexture(VS_CHAR *FileName,VS_UUID *DefaultObjectID);
extern void *IrrMaterialClass_GetObject(VS_CHAR *FileName,VS_UUID *DefaultObjectID);
extern void *IrrTriangleSelectorClass_GetSelector(VS_CHAR *SelectorName);

extern void LuaToSRP3DVector(VS_INT32 Index,struct StructOfSRP3DVector * Position);
extern void LuaPushSRP3DVector(struct StructOfSRP3DVector * Position);
extern void LuaToIRRLine3D(VS_INT32 Index,struct StructOfIRRLine3D * Item);
extern void LuaPushIRRLine3D(struct StructOfIRRLine3D * Item);
extern void LuaToIRRTriangle3D(VS_INT32 Index,struct StructOfIRRTriangle3D * Item);
extern void LuaPushIRRTriangle3D(struct StructOfIRRTriangle3D * Item);

extern void *IrrTerrainSceneNodeClass_GetTerrain(VS_CHAR *FileName,VS_UUID *DefaultObjectID);
extern VS_CHAR *SRPAPI IrrObjectClass_Load(void *Object,VS_INT8 * FileName,VS_BOOL *FileFlag,VS_ULONG *MemorySize);

extern void LuaToSRP3DPoint2(VS_INT32 Index,struct StructOfSRP3DPoint2 * Position);
extern void LuaPushSRP3DPoint2(struct StructOfSRP3DPoint2 * Position);

#endif