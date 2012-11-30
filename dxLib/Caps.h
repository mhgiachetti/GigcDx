// Caps.h: interface for the Caps class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAPS_H__EDBE0F9E_5798_4D36_AE75_9384456B6C7D__INCLUDED_)
#define AFX_CAPS_H__EDBE0F9E_5798_4D36_AE75_9384456B6C7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"
#include "DeviceCaps.h"

class Caps 
{
public:
	/* Device Info */
    D3DDEVTYPE  DeviceType;
    UINT        AdapterOrdinal;
	
    /* Caps from DX7 Draw */
    DWORD   caps;
    DWORD   caps2;
    DWORD   caps3;
    DWORD   PresentationIntervals;
	
    /* Cursor Caps */
    DWORD   CursorCaps;
	
    /* 3D Device Caps */
    DeviceCaps   deviceCaps;
	
    DWORD   PrimitiveMiscCaps;
    DWORD   RasterCaps;
    DWORD   ZCmpCaps;
    DWORD   SrcBlendCaps;
    DWORD   DestBlendCaps;
    DWORD   AlphaCmpCaps;
    DWORD   ShadeCaps;
    DWORD   TextureCaps;
    DWORD   TextureFilterCaps;          // D3DPTFILTERCAPS for IDirect3DTexture9's
    DWORD   CubeTextureFilterCaps;      // D3DPTFILTERCAPS for IDirect3DCubeTexture9's
    DWORD   VolumeTextureFilterCaps;    // D3DPTFILTERCAPS for IDirect3DVolumeTexture9's
    DWORD   TextureAddressCaps;         // D3DPTADDRESSCAPS for IDirect3DTexture9's
    DWORD   VolumeTextureAddressCaps;   // D3DPTADDRESSCAPS for IDirect3DVolumeTexture9's
	
    DWORD   LineCaps;                   // D3DLINECAPS
	
    DWORD   MaxTextureWidth, MaxTextureHeight;
    DWORD   MaxVolumeExtent;
	
    DWORD   MaxTextureRepeat;
    DWORD   MaxTextureAspectRatio;
    DWORD   MaxAnisotropy;
    float   MaxVertexW;
	
    float   GuardBandLeft;
    float   GuardBandTop;
    float   GuardBandRight;
    float   GuardBandBottom;
	
    float   ExtentsAdjust;
    DWORD   StencilCaps;
	
    DWORD   FVFCaps;
    DWORD   TextureOpCaps;
    DWORD   MaxTextureBlendStages;
    DWORD   MaxSimultaneousTextures;
	
    DWORD   VertexProcessingCaps;
    DWORD   MaxActiveLights;
    DWORD   MaxUserClipPlanes;
    DWORD   MaxVertexBlendMatrices;
    DWORD   MaxVertexBlendMatrixIndex;
	
    float   MaxPointSize;
	
    DWORD   MaxPrimitiveCount;          // max number of primitives per DrawPrimitive call
    DWORD   MaxVertexIndex;
    DWORD   MaxStreams;
    DWORD   MaxStreamStride;            // max stride for SetStreamSource
	
    DWORD   VertexShaderVersion;
    DWORD   MaxVertexShaderConst;       // number of vertex shader constant registers
	
    DWORD   PixelShaderVersion;
    float   PixelShader1xMaxValue;      // max value storable in registers of ps.1.x shaders
	
    // Here are the DX9 specific ones
    DWORD   DevCaps2;
	
    float   MaxNpatchTessellationLevel;
    DWORD   Reserved5;
	
    UINT    MasterAdapterOrdinal;       // ordinal of master adaptor for adapter group
    UINT    AdapterOrdinalInGroup;      // ordinal inside the adapter group
    UINT    NumberOfAdaptersInGroup;    // number of adapters in this adapter group (only if master)
    DWORD   DeclTypes;                  // Data types, supported in vertex declarations
    DWORD   NumSimultaneousRTs;         // Will be at least 1
    DWORD   StretchRectFilterCaps;      // Filter caps supported by StretchRect
    D3DVSHADERCAPS2_0 VS20Caps;
    D3DPSHADERCAPS2_0 PS20Caps;
    DWORD   VertexTextureFilterCaps;    // D3DPTFILTERCAPS for IDirect3DTexture9's for texture, used in vertex shaders
    DWORD   MaxVShaderInstructionsExecuted; // maximum number of vertex shader instructions that can be executed
    DWORD   MaxPShaderInstructionsExecuted; // maximum number of pixel shader instructions that can be executed
    DWORD   MaxVertexShader30InstructionSlots; 
    DWORD   MaxPixelShader30InstructionSlots;

public:
	Caps();
	~Caps();

	operator D3DCAPS*()const;
	operator D3DCAPS()const;

};

#endif // !defined(AFX_CAPS_H__EDBE0F9E_5798_4D36_AE75_9384456B6C7D__INCLUDED_)
