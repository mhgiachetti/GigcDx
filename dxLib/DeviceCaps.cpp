// DeviceCaps.cpp: implementation of the DeviceCaps class.
//
//////////////////////////////////////////////////////////////////////

#include "DeviceCaps.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DeviceCaps::DeviceCaps()
{
	m_cap = 0;
}

DeviceCaps::~DeviceCaps()
{

}

bool DeviceCaps::GetVertexElementScanSharesStreamOffset()
{
	return m_cap&D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET != 0;
}

bool DeviceCaps::GetCanStretchRectangleFromTextures()
{
	return m_cap&D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES != 0;
}

bool DeviceCaps::GetSupportsAdaptiveTessellateNPatch()
{
	return m_cap&D3DDEVCAPS2_ADAPTIVETESSNPATCH != 0;
}

bool DeviceCaps::GetSupportsAdaptiveTessellateRtPatch()
{
	return m_cap&D3DDEVCAPS2_ADAPTIVETESSRTPATCH != 0;
}

bool DeviceCaps::GetSupportsDMapNPatch()
{
	return m_cap&D3DDEVCAPS2_DMAPNPATCH != 0;
}

bool DeviceCaps::GetSupportsStreamOffset()
{
	return m_cap&D3DDEVCAPS2_STREAMOFFSET != 0;
}

bool DeviceCaps::GetSupportsPreSampledDMapNPatch()
{
	return m_cap&D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH != 0;
}

bool DeviceCaps::GetSupportsNPatches()
{
	return m_cap&D3DDEVCAPS_NPATCHES != 0;
}

bool DeviceCaps::GetSupportsRtPatchHandleZero()
{
	return m_cap&D3DDEVCAPS_RTPATCHHANDLEZERO != 0;
}

bool DeviceCaps::GetSupportsRtPatches()
{
	return m_cap&D3DDEVCAPS_RTPATCHES != 0;
}

bool DeviceCaps::GetSupportsQuinticRtPatches()
{
	return m_cap&D3DDEVCAPS_QUINTICRTPATCHES != 0;
}

bool DeviceCaps::GetSupportsPureDevice()
{
	return m_cap&D3DDEVCAPS_PUREDEVICE != 0;
}

bool DeviceCaps::GetSupportsHardwareRasterization()
{
	return m_cap&D3DDEVCAPS_HWRASTERIZATION != 0;
}

bool DeviceCaps::GetCanDrawSystemToNonLocal()
{
	return m_cap&D3DDEVCAPS_CANBLTSYSTONONLOCAL != 0;
}

bool DeviceCaps::GetSupportsHardwareTransformAndLight()
{
	return m_cap&D3DDEVCAPS_HWTRANSFORMANDLIGHT != 0;
}

bool DeviceCaps::GetSupportsDrawPrimitives2Ex()
{
	return m_cap&D3DDEVCAPS_DRAWPRIMITIVES2EX != 0;
}

bool DeviceCaps::GetSupportsSeparateTextureMemories()
{
	return m_cap&D3DDEVCAPS_SEPARATETEXTUREMEMORIES != 0;
}

bool DeviceCaps::GetSupportsDrawPrimitives2()
{
	return m_cap&D3DDEVCAPS_DRAWPRIMITIVES2 != 0;
}

bool DeviceCaps::GetSupportsTextureNonLocalVideoMemory()
{
	return m_cap&D3DDEVCAPS_TEXTURENONLOCALVIDMEM != 0;
}

bool DeviceCaps::GetCanRenderAfterFlip()
{
	return m_cap&D3DDEVCAPS_CANRENDERAFTERFLIP != 0;
}

bool DeviceCaps::GetSupportsDrawPrimitivesTransformedVertex()
{
	return m_cap&D3DDEVCAPS_DRAWPRIMTLVERTEX != 0;
}

bool DeviceCaps::GetSupportsTextureVideoMemory()
{
	return m_cap&D3DDEVCAPS_TEXTUREVIDEOMEMORY != 0;
}

bool DeviceCaps::GetSupportsTextureSystemMemory()
{
	return m_cap&D3DDEVCAPS_TEXTURESYSTEMMEMORY != 0;
}

bool DeviceCaps::GetSupportsTransformedVertexVideoMemory()
{
	return m_cap&D3DDEVCAPS_TLVERTEXVIDEOMEMORY != 0;
}

bool DeviceCaps::GetSupportsTransformedVertexSystemMemory()
{
	return m_cap&D3DDEVCAPS_TLVERTEXSYSTEMMEMORY != 0;
}

bool DeviceCaps::GetSupportsExecuteVideoMemory()
{
	return m_cap&D3DDEVCAPS_EXECUTEVIDEOMEMORY != 0;
}

bool DeviceCaps::GetSupportsExecuteSystemMemory()
{
	return m_cap&D3DDEVCAPS_EXECUTESYSTEMMEMORY != 0;
}
