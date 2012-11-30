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

bool DeviceCaps::VertexElementScanSharesStreamOffset()
{
	return m_cap&D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET != 0;
}

bool DeviceCaps::CanStretchRectangleFromTextures()
{
	return m_cap&D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES != 0;
}

bool DeviceCaps::SupportsAdaptiveTessellateNPatch()
{
	return m_cap&D3DDEVCAPS2_ADAPTIVETESSNPATCH != 0;
}

bool DeviceCaps::SupportsAdaptiveTessellateRtPatch()
{
	return m_cap&D3DDEVCAPS2_ADAPTIVETESSRTPATCH != 0;
}

bool DeviceCaps::SupportsDMapNPatch()
{
	return m_cap&D3DDEVCAPS2_DMAPNPATCH != 0;
}

bool DeviceCaps::SupportsStreamOffset()
{
	return m_cap&D3DDEVCAPS2_STREAMOFFSET != 0;
}

bool DeviceCaps::SupportsPreSampledDMapNPatch()
{
	return m_cap&D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH != 0;
}

bool DeviceCaps::SupportsNPatches()
{
	return m_cap&D3DDEVCAPS_NPATCHES != 0;
}

bool DeviceCaps::SupportsRtPatchHandleZero()
{
	return m_cap&D3DDEVCAPS_RTPATCHHANDLEZERO != 0;
}

bool DeviceCaps::SupportsRtPatches()
{
	return m_cap&D3DDEVCAPS_RTPATCHES != 0;
}

bool DeviceCaps::SupportsQuinticRtPatches()
{
	return m_cap&D3DDEVCAPS_QUINTICRTPATCHES != 0;
}

bool DeviceCaps::SupportsPureDevice()
{
	return m_cap&D3DDEVCAPS_PUREDEVICE != 0;
}

bool DeviceCaps::SupportsHardwareRasterization()
{
	return m_cap&D3DDEVCAPS_HWRASTERIZATION != 0;
}

bool DeviceCaps::CanDrawSystemToNonLocal()
{
	return m_cap&D3DDEVCAPS_CANBLTSYSTONONLOCAL != 0;
}

bool DeviceCaps::SupportsHardwareTransformAndLight()
{
	return m_cap&D3DDEVCAPS_HWTRANSFORMANDLIGHT != 0;
}

bool DeviceCaps::SupportsDrawPrimitives2Ex()
{
	return m_cap&D3DDEVCAPS_DRAWPRIMITIVES2EX != 0;
}

bool DeviceCaps::SupportsSeparateTextureMemories()
{
	return m_cap&D3DDEVCAPS_SEPARATETEXTUREMEMORIES != 0;
}

bool DeviceCaps::SupportsDrawPrimitives2()
{
	return m_cap&D3DDEVCAPS_DRAWPRIMITIVES2 != 0;
}

bool DeviceCaps::SupportsTextureNonLocalVideoMemory()
{
	return m_cap&D3DDEVCAPS_TEXTURENONLOCALVIDMEM != 0;
}

bool DeviceCaps::CanRenderAfterFlip()
{
	return m_cap&D3DDEVCAPS_CANRENDERAFTERFLIP != 0;
}

bool DeviceCaps::SupportsDrawPrimitivesTransformedVertex()
{
	return m_cap&D3DDEVCAPS_DRAWPRIMTLVERTEX != 0;
}

bool DeviceCaps::SupportsTextureVideoMemory()
{
	return m_cap&D3DDEVCAPS_TEXTUREVIDEOMEMORY != 0;
}

bool DeviceCaps::SupportsTextureSystemMemory()
{
	return m_cap&D3DDEVCAPS_TEXTURESYSTEMMEMORY != 0;
}

bool DeviceCaps::SupportsTransformedVertexVideoMemory()
{
	return m_cap&D3DDEVCAPS_TLVERTEXVIDEOMEMORY != 0;
}

bool DeviceCaps::SupportsTransformedVertexSystemMemory()
{
	return m_cap&D3DDEVCAPS_TLVERTEXSYSTEMMEMORY != 0;
}

bool DeviceCaps::SupportsExecuteVideoMemory()
{
	return m_cap&D3DDEVCAPS_EXECUTEVIDEOMEMORY != 0;
}

bool DeviceCaps::SupportsExecuteSystemMemory()
{
	return m_cap&D3DDEVCAPS_EXECUTESYSTEMMEMORY != 0;
}
