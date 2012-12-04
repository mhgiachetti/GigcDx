// DeviceCaps.h: interface for the DeviceCaps class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEVICECAPS_H__9764D408_9B75_482D_8CF1_64791E1B46E3__INCLUDED_)
#define AFX_DEVICECAPS_H__9764D408_9B75_482D_8CF1_64791E1B46E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"

class DeviceCaps  
{
protected:
	DWORD m_cap;

public:
	DeviceCaps();
	~DeviceCaps();
	bool GetVertexElementScanSharesStreamOffset();
	bool GetCanStretchRectangleFromTextures();
	bool GetSupportsAdaptiveTessellateNPatch();
	bool GetSupportsAdaptiveTessellateRtPatch();
	bool GetSupportsDMapNPatch();
	bool GetSupportsStreamOffset();
	bool GetSupportsPreSampledDMapNPatch();
	bool GetSupportsNPatches();
	bool GetSupportsRtPatchHandleZero();
	bool GetSupportsRtPatches();
	bool GetSupportsQuinticRtPatches();
	bool GetSupportsPureDevice();
	bool GetSupportsHardwareRasterization();
	bool GetCanDrawSystemToNonLocal();
	bool GetSupportsHardwareTransformAndLight();
	bool GetSupportsDrawPrimitives2Ex();
	bool GetSupportsSeparateTextureMemories();
	bool GetSupportsDrawPrimitives2();
	bool GetSupportsTextureNonLocalVideoMemory();
	bool GetCanRenderAfterFlip();
	bool GetSupportsDrawPrimitivesTransformedVertex();
	bool GetSupportsTextureVideoMemory();
	bool GetSupportsTextureSystemMemory();
	bool GetSupportsTransformedVertexVideoMemory();
	bool GetSupportsTransformedVertexSystemMemory();
	bool GetSupportsExecuteVideoMemory();
    bool GetSupportsExecuteSystemMemory();

	PROPERTYGET(bool,VertexElementScanSharesStreamOffset);
	PROPERTYGET(bool,CanStretchRectangleFromTextures);
	PROPERTYGET(bool,SupportsAdaptiveTessellateNPatch);
	PROPERTYGET(bool,SupportsAdaptiveTessellateRtPatch);
	PROPERTYGET(bool,SupportsDMapNPatch);
	PROPERTYGET(bool,SupportsStreamOffset);
	PROPERTYGET(bool,SupportsNPatches);
	PROPERTYGET(bool,SupportsRtPatchHandleZero);
	PROPERTYGET(bool,SupportsRtPatches);
	PROPERTYGET(bool,SupportsQuinticRtPatches);
	PROPERTYGET(bool,SupportsPureDevice);
	PROPERTYGET(bool,SupportsHardwareRasterization);
	PROPERTYGET(bool,CanDrawSystemToNonLocal);
	PROPERTYGET(bool,SupportsHardwareTransformAndLight);
	PROPERTYGET(bool,SupportsDrawPrimitives2Ex);
	PROPERTYGET(bool,SupportsSeparateTextureMemories);
	PROPERTYGET(bool,SupportsDrawPrimitives2);
	PROPERTYGET(bool,SupportsTextureNonLocalVideoMemory);
	PROPERTYGET(bool,CanRenderAfterFlip);
	PROPERTYGET(bool,SupportsDrawPrimitivesTransformedVertex);
	PROPERTYGET(bool,SupportsTextureVideoMemory);
	PROPERTYGET(bool,SupportsTextureSystemMemory);
	PROPERTYGET(bool,SupportsTransformedVertexVideoMemory);
	PROPERTYGET(bool,SupportsTransformedVertexSystemMemory);
	PROPERTYGET(bool,SupportsExecuteVideoMemory);
	PROPERTYGET(bool,SupportsExecuteSystemMemory);

};

#endif // !defined(AFX_DEVICECAPS_H__9764D408_9B75_482D_8CF1_64791E1B46E3__INCLUDED_)
