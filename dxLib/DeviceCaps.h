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
	bool VertexElementScanSharesStreamOffset();
	bool CanStretchRectangleFromTextures();
	bool SupportsAdaptiveTessellateNPatch();
	bool SupportsAdaptiveTessellateRtPatch();
	bool SupportsDMapNPatch();
	bool SupportsStreamOffset();
	bool SupportsPreSampledDMapNPatch();
	bool SupportsNPatches();
	bool SupportsRtPatchHandleZero();
	bool SupportsRtPatches();
	bool SupportsQuinticRtPatches();
	bool SupportsPureDevice();
	bool SupportsHardwareRasterization();
	bool CanDrawSystemToNonLocal();
	bool SupportsHardwareTransformAndLight();
	bool SupportsDrawPrimitives2Ex();
	bool SupportsSeparateTextureMemories();
	bool SupportsDrawPrimitives2();
	bool SupportsTextureNonLocalVideoMemory();
	bool CanRenderAfterFlip();
	bool SupportsDrawPrimitivesTransformedVertex();
	bool SupportsTextureVideoMemory();
	bool SupportsTextureSystemMemory();
	bool SupportsTransformedVertexVideoMemory();
	bool SupportsTransformedVertexSystemMemory();
	bool SupportsExecuteVideoMemory();
    bool SupportsExecuteSystemMemory();

};

#endif // !defined(AFX_DEVICECAPS_H__9764D408_9B75_482D_8CF1_64791E1B46E3__INCLUDED_)
