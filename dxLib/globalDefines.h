// globalDefines.h: interface for the globalDefines class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLOBALDEFINES_H__5E38DA35_59BB_45B6_8C48_31D491EDCA96__INCLUDED_)
#define AFX_GLOBALDEFINES_H__5E38DA35_59BB_45B6_8C48_31D491EDCA96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//Accesors en c++
//macros para accesors
#define PROPERTYGETSETF(t,n,g,s) __declspec( property ( put = s, get = g) ) t n;
#define PROPERTYGETSET(t,n) PROPERTYGETSETF(t,n,Get##n,Set##n)
#define PROPERTYGETF(t,n,g) __declspec( property ( get = g) ) t n;
#define PROPERTYGET(t,n) PROPERTYGETF(t,n,Get##n)
#define PROPERTYSETF(t,n,s) __declspec( property ( put = s) ) t n;
#define PROPERTYSET(t,n) PROPERTYSETF(t,n,Set##n)
#define PROPERTYSIMPLGETSET(t,n,var) PROPERTYGETSET(t,n)\
	t Get##n(){return var;}\
	void Set##n(const t &value){var = value;}
#define PROPERTYSIMPLGET(t,n,var) PROPERTYGET(t,n)\
	t Get##n(){return var;}
#define PROPERTYSIMPLSET(t,n,var) PROPERTYSET(t,n)\
	void Set##n(const t &value){var = value;}

#define DIRECTINPUT_VERSION 0x0800

#include <d3d9.h>
#include <d3dx9math.h>
#include <../../Microsoft DirectX SDK (June 2010)/Include/dinput.h>

#define LPD3DVERTEXBUFFER LPDIRECT3DVERTEXBUFFER9
#define LPD3DINDEXBUFFER LPDIRECT3DINDEXBUFFER9
#define LPD3DTEXTURE LPDIRECT3DTEXTURE9
#define LPD3D LPDIRECT3D9
#define ID3DDevice IDirect3DDevice9
#define LPD3DDEVICE LPDIRECT3DDEVICE9
#define Direct3DCreate Direct3DCreate9
#define D3DLIGHT D3DLIGHT9
#define D3DMATERIAL D3DMATERIAL9
#define D3DCAPS D3DCAPS9
#define D3DVIEWPORT D3DVIEWPORT9
#define LPDINPUT LPDIRECTINPUT8
#define LPDINPUTDEVICE LPDIRECTINPUTDEVICE8
#define DirectInputCreate DirectInput8Create

//redefiniciones
#define VertexBufferDescription D3DVERTEXBUFFER_DESC
#define ResourceType D3DRESOURCETYPE


//enums
/*enum ClearFlags{	CLEAR_STENCIL = D3DCLEAR_STENCIL,
					CLEAR_TARGET = D3DCLEAR_TARGET,
					CLEAR_ZBUFFER = D3DCLEAR_ZBUFFER,
					CLEAR_STENTAR = D3DCLEAR_STENCIL|D3DCLEAR_TARGET,
					CLEAR_STENZBUF = D3DCLEAR_STENCIL|D3DCLEAR_ZBUFFER,
					CLEAR_TARZBUF = D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,
					CLEAR_STENTARZBUF = D3DCLEAR_STENCIL|D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER};*/

enum ClearFlags
{
    ClearFlags_Stencil= D3DCLEAR_STENCIL,
	ClearFlags_Target = D3DCLEAR_TARGET,
	ClearFlags_ZBuffer = D3DCLEAR_ZBUFFER,
};
inline ClearFlags operator|(ClearFlags a, ClearFlags b)
{return (ClearFlags)((int)a | (int)b);}


enum Pool
{
    Pool_Default = D3DPOOL_DEFAULT,
	Pool_Managed = D3DPOOL_MANAGED,
	Pool_SystemMemory = D3DPOOL_SYSTEMMEM,
	Pool_Scratch = D3DPOOL_SCRATCH
};

enum VertexFormat
{
	VertexFormat_None = 0,
    VertexFormat_Texture0 = 0,
    VertexFormat_Position = D3DFVF_XYZ,
    VertexFormat_Transformed = D3DFVF_XYZRHW,
    VertexFormat_PositionBlend1 = D3DFVF_XYZB1,
    VertexFormat_PositionBlend2 = D3DFVF_XYZB2,
    VertexFormat_TextureCountShift = D3DFVF_XYZB2,
    VertexFormat_PositionBlend3 = D3DFVF_XYZB3,
    VertexFormat_PositionBlend4 = D3DFVF_XYZB4,
    VertexFormat_PositionBlend5 = D3DFVF_XYZB5,
    VertexFormat_Normal = D3DFVF_NORMAL,
    VertexFormat_PositionNormal = D3DFVF_XYZ | D3DFVF_NORMAL,
    VertexFormat_PointSize = D3DFVF_PSIZE,
    VertexFormat_Diffuse = D3DFVF_DIFFUSE,
    VertexFormat_Specular = D3DFVF_SPECULAR,
    VertexFormat_Texture1 = D3DFVF_TEX1,
    VertexFormat_Texture2 = D3DFVF_TEX2,
    VertexFormat_Texture3 = D3DFVF_TEX3,
    VertexFormat_Texture4 = D3DFVF_TEX4,
    VertexFormat_Texture5 = D3DFVF_TEX5,
    VertexFormat_Texture6 = D3DFVF_TEX6,
    VertexFormat_Texture7 = D3DFVF_TEX7,
    VertexFormat_Texture8 = D3DFVF_TEX8,
    VertexFormat_TextureCountMask = D3DFVF_TEXCOUNT_MASK,
    VertexFormat_LastBetaUByte4 = D3DFVF_LASTBETA_UBYTE4,
    VertexFormat_PositionW = D3DFVF_XYZW,
    VertexFormat_PositionMask = D3DFVF_POSITION_MASK,
    VertexFormat_LastBetaD3DColor = D3DFVF_LASTBETA_D3DCOLOR,
};
inline VertexFormat operator|(VertexFormat a, VertexFormat b)
{return (VertexFormat)((int)a | (int)b);}


enum Usage
{
	Usage_None = 0,
	Usage_RenderTarget = D3DUSAGE_RENDERTARGET,
	Usage_DepthStencil = D3DUSAGE_DEPTHSTENCIL,
	Usage_WriteOnly = D3DUSAGE_WRITEONLY,
	Usage_SoftwareProcessing = D3DUSAGE_SOFTWAREPROCESSING,
	Usage_DoNotClip = D3DUSAGE_DONOTCLIP,
	Usage_Points = D3DUSAGE_POINTS,
	Usage_RTPatches = D3DUSAGE_RTPATCHES,
	Usage_NPatches = D3DUSAGE_NPATCHES,
	Usage_Dynamic = D3DUSAGE_DYNAMIC,
	Usage_AutoGenerateMipMap = D3DUSAGE_AUTOGENMIPMAP,
	Usage_QueryDisplacementMap = D3DUSAGE_DMAP,
	Usage_QueryLegacyBumpMap = D3DUSAGE_QUERY_LEGACYBUMPMAP,
	Usage_QuerySrgbRead = D3DUSAGE_QUERY_SRGBREAD,
	Usage_QueryFilter = D3DUSAGE_QUERY_FILTER,
	Usage_QuerySrgbWrite = D3DUSAGE_QUERY_SRGBWRITE,
	Usage_QueryPostPixelShaderBlending = D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING,
	Usage_QueryVertexTexture = D3DUSAGE_QUERY_VERTEXTEXTURE,
	Usage_QueryWrapAndMip = D3DUSAGE_QUERY_WRAPANDMIP,
};
inline Usage operator|(Usage a, Usage b)
{return (Usage)((int)a | (int)b);}


enum LockFlags
{
	LockFlags_None = 0,
	LockFlags_ReadOnly = D3DLOCK_READONLY,
	LockFlags_NoSystemLock = D3DLOCK_NOSYSLOCK,
	LockFlags_NoOverwrite = D3DLOCK_NOOVERWRITE,
	LockFlags_Discard = D3DLOCK_DISCARD,
	LockFlags_DoNotWait = D3DLOCK_DONOTWAIT,
	LockFlags_NoDirtyUpdate = D3DLOCK_NO_DIRTY_UPDATE,
};
inline LockFlags operator|(LockFlags a, LockFlags b)
{return (LockFlags)((int)a | (int)b);}

enum PrimitiveType
{
	PrimitiveType_PointList = D3DPT_POINTLIST,
	PrimitiveType_LineList = D3DPT_LINELIST,
	PrimitiveType_LineStrip = D3DPT_LINESTRIP,
	PrimitiveType_TriangleList = D3DPT_TRIANGLELIST,
	PrimitiveType_TriangleStrip = D3DPT_TRIANGLESTRIP,
	PrimitiveType_TriangleFan = D3DPT_TRIANGLEFAN,
};

enum Cull
{
	Cull_None = D3DCULL_NONE,
	Cull_Clockwise = D3DCULL_CW,
	Cull_CounterClockwise = D3DCULL_CCW,
};

enum LightType
{
	LightType_Point = D3DLIGHT_POINT,
	LightType_Spot = D3DLIGHT_SPOT,
	LightType_Directional = D3DLIGHT_DIRECTIONAL,
};

enum BlendOperation
{
	BlendOperation_Add = D3DBLENDOP_ADD,
	BlendOperation_Subtract = D3DBLENDOP_SUBTRACT,
	BlendOperation_RevSubtract = D3DBLENDOP_REVSUBTRACT,
	BlendOperation_Min = D3DBLENDOP_MIN,
	BlendOperation_Max = D3DBLENDOP_MAX,
};

enum Blend
{
	Blend_Zero = D3DBLEND_ZERO,
	Blend_One = D3DBLEND_ONE,
	Blend_SourceColor = D3DBLEND_SRCCOLOR,
	Blend_InvSourceColor = D3DBLEND_INVSRCCOLOR,
	Blend_SourceAlpha = D3DBLEND_SRCALPHA,
	Blend_InvSourceAlpha = D3DBLEND_INVSRCALPHA,
	Blend_DestinationAlpha = D3DBLEND_DESTALPHA,
	Blend_InvDestinationAlpha = D3DBLEND_INVDESTALPHA,
	Blend_DestinationColor = D3DBLEND_DESTCOLOR,
	Blend_InvDestinationColor = D3DBLEND_INVDESTCOLOR,
	Blend_SourceAlphaSat = D3DBLEND_SRCALPHASAT,
	Blend_BothSourceAlpha = D3DBLEND_BOTHSRCALPHA,
	Blend_BothInvSourceAlpha = D3DBLEND_BOTHINVSRCALPHA,
	Blend_BlendFactor = D3DBLEND_BLENDFACTOR,
	Blend_InvBlendFactor = D3DBLEND_INVBLENDFACTOR,
};

enum Format
{
	Format_Unknown = 0,
	Format_R8G8B8 = 20,
	Format_A8R8G8B8 = 21,
	Format_X8R8G8B8 = 22,
	Format_R5G6B5 = 23,
	Format_X1R5G5B5 = 24,
	Format_A1R5G5B5 = 25,
	Format_A4R4G4B4 = 26,
	Format_R3G3B2 = 27,
	Format_A8 = 28,
	Format_A8R3G3B2 = 29,
	Format_X4R4G4B4 = 30,
	Format_A2B10G10R10 = 31,
	Format_A8B8G8R8 = 32,
	Format_X8B8G8R8 = 33,
	Format_G16R16 = 34,
	Format_A2R10G10B10 = 35,
	Format_A16B16G16R16 = 36,
	Format_A8P8 = 40,
	Format_P8 = 41,
	Format_L8 = 50,
	Format_A8L8 = 51,
	Format_A4L4 = 52,
	Format_V8U8 = 60,
	Format_L6V5U5 = 61,
	Format_X8L8V8U8 = 62,
	Format_Q8W8V8U8 = 63,
	Format_V16U16 = 64,
	Format_A2W10V10U10 = 67,
	Format_D16Lockable = 70,
	Format_D32 = 71,
	Format_D15S1 = 73,
	Format_D24S8 = 75,
	Format_D24X8 = 77,
	Format_D24X4S4 = 79,
	Format_D16 = 80,
	Format_L16 = 81,
	Format_D32SingleLockable = 82,
	Format_D24SingleS8 = 83,
	Format_VertexData = 100,
	Format_Q16W16V16U16 = 110,
	Format_R16F = 111,
	Format_G16R16F = 112,
	Format_A16B16G16R16F = 113,
	Format_R32F = 114,
	Format_G32R32F = 115,
	Format_A32B32G32R32F = 116,
	Format_CxV8U8 = 117,
	Format_Multi2Argb8 = 827606349,
	Format_Dxt1 = 827611204,
	Format_Dxt2 = 844388420,
	Format_Yuy2 = 844715353,
	Format_Dxt3 = 861165636,
	Format_Dxt4 = 877942852,
	Format_Dxt5 = 894720068,
	Format_G8R8G8B8 = 1111970375,
	Format_R8G8B8G8 = 1195525970,
	Format_Uyvy = 1498831189,
};

enum ImageFileFormat
{
	ImageFileFormat_Bmp = D3DXIFF_BMP,
	ImageFileFormat_Jpg = D3DXIFF_JPG,
	ImageFileFormat_Tga = D3DXIFF_TGA,
	ImageFileFormat_Png = D3DXIFF_PNG,
	ImageFileFormat_Dds = D3DXIFF_DDS,
	ImageFileFormat_Ppm = D3DXIFF_PPM,
	ImageFileFormat_Dib = D3DXIFF_DIB,
	ImageFileFormat_Hdr = D3DXIFF_HDR,
	ImageFileFormat_Pfm = D3DXIFF_PFM,
};

enum MeshFlags
{
	MeshFlags_SimplifyVertex = 1,
	MeshFlags_Use32Bit = MeshFlags_SimplifyVertex,
	MeshFlags_DoNotClip = 2,
	MeshFlags_SimplifyFace = MeshFlags_DoNotClip,
	MeshFlags_Points = 4,
	MeshFlags_RtPatches = 8,
	MeshFlags_VbSystemMem = 16,
	MeshFlags_VbManaged = 32,
	MeshFlags_VbWriteOnly = 64,
	MeshFlags_VbDynamic = 128,
	MeshFlags_IbSystemMem = 256,
	MeshFlags_SystemMemory = MeshFlags_IbSystemMem | MeshFlags_VbSystemMem,
	MeshFlags_IbManaged = 512,
	MeshFlags_Managed = MeshFlags_IbManaged | MeshFlags_VbManaged,
	MeshFlags_IbWriteOnly = 1024,
	MeshFlags_WriteOnly = MeshFlags_IbWriteOnly | MeshFlags_VbWriteOnly,
	MeshFlags_IbDynamic = 2048,
	MeshFlags_Dynamic = MeshFlags_IbDynamic | MeshFlags_VbDynamic,
	MeshFlags_VbShare = 4096,
	MeshFlags_UseHardwareOnly = 8192,
	MeshFlags_NPatches = 16384,
	MeshFlags_VbSoftwareProcessing = 32768,
	MeshFlags_IbSoftwareProcessing = 65536,
	MeshFlags_SoftwareProcessing = MeshFlags_IbSoftwareProcessing | MeshFlags_VbSoftwareProcessing,
	MeshFlags_OptimizeDeviceIndependent = 4194304,
	MeshFlags_OptimizeCompact = 16777216,
	MeshFlags_OptimizeAttributeSort = 33554432,
	MeshFlags_OptimizeVertexCache = 67108864,
	MeshFlags_OptimizeStripeReorder = 134217728,
	MeshFlags_OptimizeIgnoreVerts = 268435456,
	MeshFlags_OptimizeDoNotSplit = 536870912,
};
inline MeshFlags operator|(MeshFlags a, MeshFlags b)
{return (MeshFlags)((int)a | (int)b);}

enum ShaderFlags
{
	ShaderFlags_None = 0,
	ShaderFlags_Debug = 1,
	ShaderFlags_SkipValidation = 2,
	ShaderFlags_SkipOptimization = 4,
	ShaderFlags_PackMatrixRowMajor = 8,
	ShaderFlags_PackMatrixColumnMajor = 16,
	ShaderFlags_PartialPrecision = 32,
	ShaderFlags_ForceVertexShaderSoftwareNoOptimizations = 64,
	ShaderFlags_ForcePixelShaderSoftwareNoOptimizations = 128,
	ShaderFlags_NoPreShader = 256,
	ShaderFlags_AvoidFlowControl = 512,
	ShaderFlags_PreferFlowControl = 1024,
	ShaderFlags_NotCloneable = 2048,
};
inline ShaderFlags operator|(ShaderFlags a, ShaderFlags b)
{return (ShaderFlags)((int)a | (int)b);}

enum FX
{
	FX_None = 0,
	FX_DoNotSaveState = 1,
	FX_DoNotSaveShaderState = 2,
	FX_DoNotSaveSamplerState = 4,
};
inline FX operator|(FX a, FX b)
{return (FX)((int)a | (int)b);}

enum FillMode
{
	FillMode_Point = 1,
	FillMode_WireFrame = 2,
	FillMode_Solid = 3,
};

enum Filter
{
	Filter_None = 1,
	Filter_Point = 2,
	Filter_Linear = 3,
	Filter_Triangle = 4,
	Filter_Box = 5,
	Filter_MirrorU = 65536,
	Filter_MirrorV = 131072,
	Filter_MirrorW = 262144,
	Filter_Mirror = 458752,
	Filter_Dither = 524288,
	Filter_DitherDiffusion = 1048576,
	Filter_SrgbIn = 2097152,
	Filter_SrgbOut = 4194304,
	Filter_Srgb = 6291456,
};

enum MultiSampleType
{
	MultiSampleType_None,
	MultiSampleType_NonMaskable,
	MultiSampleType_TwoSamples,
	MultiSampleType_ThreeSamples,
	MultiSampleType_FourSamples,
	MultiSampleType_FiveSamples,
	MultiSampleType_SixSamples,
	MultiSampleType_SevenSamples,
	MultiSampleType_EightSamples,
	MultiSampleType_NineSamples,
	MultiSampleType_TenSamples,
	MultiSampleType_ElevenSamples,
	MultiSampleType_TwelveSamples,
	MultiSampleType_ThirteenSamples,
	MultiSampleType_FourteenSamples,
	MultiSampleType_FifteenSamples,
	MultiSampleType_SixteenSamples,
};

enum ShadeMode
{
	ShadeMode_Flat = 1,
	ShadeMode_Gouraud = 2,
	ShadeMode_Phong = 3,
};

enum Compare
{
	Compare_Never = 1,
	Compare_Less = 2,
	Compare_Equal = 3,
	Compare_LessEqual = 4,
	Compare_Greater = 5,
	Compare_NotEqual = 6,
	Compare_GreaterEqual = 7,
	Compare_Always = 8,
};

enum SamplerStageStates
{
	SamplerStageStates_AddressU = 1,
	SamplerStageStates_AddressV = 2,
	SamplerStageStates_AddressW = 3,
	SamplerStageStates_BorderColor = 4,
	SamplerStageStates_MagFilter = 5,
	SamplerStageStates_MinFilter = 6,
	SamplerStageStates_MipFilter = 7,
	SamplerStageStates_MipMapLevelOfDetailBias = 8,
	SamplerStageStates_MaxMipLevel = 9,
	SamplerStageStates_MaxAnisotropy = 10,
	SamplerStageStates_SrgbTexture = 11,
	SamplerStageStates_ElementIndex = 12,
	SamplerStageStates_DMapOffset = 13,
};

enum TextureFilter
{
	TextureFilter_None = 0,
	TextureFilter_Point = 1,
	TextureFilter_Linear = 2,
	TextureFilter_Anisotropic = 3,
	TextureFilter_PyramidalQuad = 6,
	TextureFilter_GaussianQuad = 7,
};

enum CreateFlags
{
	CreateFlags_FpuPreserve = 2,
	CreateFlags_MultiThreaded = 4,
	CreateFlags_PureDevice = 16,
	CreateFlags_SoftwareVertexProcessing = 32,
	CreateFlags_HardwareVertexProcessing = 64,
	CreateFlags_MixedVertexProcessing = 128,
	CreateFlags_DisableDriverManagement = 256,
	CreateFlags_AdapterGroupDevice = 512,
	CreateFlags_DisableDriverManagementEx = 1024,
	CreateFlags_NoWindowChanges = 2048,
};
inline CreateFlags operator|(CreateFlags a, CreateFlags b)
{return (CreateFlags)((int)a | (int)b);}

enum SwapEffect
{
	SwapEffect_Discard = 1,
	SwapEffect_Flip = 2,
	SwapEffect_Copy = 3,
};

enum PresentInterval
{
	PresentInterval_Immediate = D3DPRESENT_INTERVAL_IMMEDIATE,
	PresentInterval_Default = 0,
	PresentInterval_One = 1,
	PresentInterval_Two = 2,
	PresentInterval_Three = 4,
	PresentInterval_Four = 8,
};

enum DepthFormat
{
	DepthFormat_Unknown = 0,
	DepthFormat_D16Lockable = 70,
	DepthFormat_D32 = 71,
	DepthFormat_D15S1 = 73,
	DepthFormat_D24S8 = 75,
	DepthFormat_D24X8 = 77,
	DepthFormat_D24X4S4 = 79,
	DepthFormat_D16 = 80,
	DepthFormat_L16 = 81,
	DepthFormat_D32SingleLockable = 82,
	DepthFormat_D24SingleS8 = 83,
};

enum PresentFlag
{
	PresentFlag_None = 0,
	PresentFlag_LockableBackBuffer = 1,
	PresentFlag_DiscardDepthStencil = 2,
	PresentFlag_DeviceClip = 4,
	PresentFlag_Video = 16,
};
inline PresentFlag operator|(PresentFlag a, PresentFlag b)
{return (PresentFlag)((int)a | (int)b);}

enum DeviceType
{
	DeviceType_Hardware = 1,
	DeviceType_Reference = 2,
	DeviceType_Software = 3,
	DeviceType_NullReference = 4,
};

enum DrawTextFormat
{
	DrawTextFormat_Left = 0,
	DrawTextFormat_None = 0,
	DrawTextFormat_Top = 0,
	DrawTextFormat_Center = 1,
	DrawTextFormat_Right = 2,
	DrawTextFormat_VerticalCenter = 4,
	DrawTextFormat_Bottom = 8,
	DrawTextFormat_WordBreak = 16,
	DrawTextFormat_SingleLine = 32,
	DrawTextFormat_ExpandTabs = 64,
	DrawTextFormat_NoClip = 256,
	DrawTextFormat_RightToLeftReading = 131072,
};
inline DrawTextFormat operator|(DrawTextFormat a, DrawTextFormat b)
{return (DrawTextFormat)((int)a | (int)b);}

enum SpriteFlags
{
	SpriteFlags_None = 0,
	SpriteFlags_DoNotSaveState = 1,
	SpriteFlags_DoNotModifyRenderState = 2,
	SpriteFlags_ObjectSpace = 4,
	SpriteFlags_Billboard = 8,
	SpriteFlags_AlphaBlend = 16,
	SpriteFlags_SortTexture = 32,
	SpriteFlags_SortDepthFrontToBack = 64,
	SpriteFlags_SortDepthBackToFront = 128,
};
inline SpriteFlags operator|(SpriteFlags a, SpriteFlags b)
{return (SpriteFlags)((int)a | (int)b);}

enum PitchAndFamily
{
	PitchAndFamily_DefaultPitch = 0,
	PitchAndFamily_FamilyDoNotCare = 0,
	PitchAndFamily_FixedPitch = 1,
	PitchAndFamily_VariablePitch = 2,
	PitchAndFamily_MonoFont = 8,
	PitchAndFamily_FamilyRoman = 16,
	PitchAndFamily_FamilySwiss = 32,
	PitchAndFamily_FamilyModern = 48,
	PitchAndFamily_FamilyScript = 64,
	PitchAndFamily_FamilyDecorative = 80,
};
inline PitchAndFamily operator|(PitchAndFamily a, PitchAndFamily b)
{return (PitchAndFamily)((int)a | (int)b);}

enum FontQuality
{
	FontQuality_Default,
	FontQuality_Draft,
	FontQuality_Proof,
	FontQuality_NonAntiAliased,
	FontQuality_AntiAliased,
	FontQuality_ClearType,
	FontQuality_ClearTypeNatural,
};

enum Precision
{
	Precision_Default,
	Precision_String,
	Precision_Character,
	Precision_Stroke,
	Precision_Tt,
	Precision_Device,
	Precision_Raster,
	Precision_TtOnly,
	Precision_Outline,
	Precision_ScreenOutline,
	Precision_PsOnly,
};

enum CharacterSet
{
	CharacterSet_Ansi = 0,
	CharacterSet_Default = 1,
	CharacterSet_Symbol = 2,
	CharacterSet_Mac = 77,
	CharacterSet_ShiftJIS = 128,
	CharacterSet_Hangeul = 129,
	CharacterSet_Hangul = 129,
	CharacterSet_Johab = 130,
	CharacterSet_GB2312 = 134,
	CharacterSet_ChineseBig5 = 136,
	CharacterSet_Greek = 161,
	CharacterSet_Turkish = 162,
	CharacterSet_Vietnamese = 163,
	CharacterSet_Hebrew = 177,
	CharacterSet_Arabic = 178,
	CharacterSet_Baltic = 186,
	CharacterSet_Russian = 204,
	CharacterSet_Thai = 222,
	CharacterSet_EastEurope = 238,
	CharacterSet_Oem = 255,
};

enum FontWeight
{
	FontWeight_DoNotCare = 0,
	FontWeight_Thin = 100,
	FontWeight_ExtraLight = 200,
	FontWeight_UltraLight = 200,
	FontWeight_Light = 300,
	FontWeight_Normal = 400,
	FontWeight_Regular = 400,
	FontWeight_Medium = 500,
	FontWeight_DemiBold = 600,
	FontWeight_SemiBold = 600,
	FontWeight_Bold = 700,
	FontWeight_ExtraBold = 800,
	FontWeight_UltraBold = 800,
	FontWeight_Black = 900,
	FontWeight_Heavy = 900,
};

enum CooperativeLevelFlags
{
	CooperativeLevelFlags_Exclusive = 1,
	CooperativeLevelFlags_NonExclusive = 2,
	CooperativeLevelFlags_Foreground = 4,
	CooperativeLevelFlags_Background = 8,
	CooperativeLevelFlags_NoWindowsKey = 16,
};
inline CooperativeLevelFlags operator|(CooperativeLevelFlags a, CooperativeLevelFlags b)
{return (CooperativeLevelFlags)((int)a | (int)b);}

 enum Key
 {
	Key_Escape = 1,
	Key_D1 = 2,
	Key_D2 = 3,
	Key_D3 = 4,
	Key_D4 = 5,
	Key_D5 = 6,
	Key_D6 = 7,
	Key_D7 = 8,
	Key_D8 = 9,
	Key_D9 = 10,
	Key_D0 = 11,
	Key_Minus = 12,
	Key_Equals = 13,
	Key_Back = 14,
	Key_BackSpace = 14,
	Key_Tab = 15,
	Key_Q = 16,
	Key_W = 17,
	Key_E = 18,
	Key_R = 19,
	Key_T = 20,
	Key_Y = 21,
	Key_U = 22,
	Key_I = 23,
	Key_O = 24,
	Key_P = 25,
	Key_LeftBracket = 26,
	Key_RightBracket = 27,
	Key_Return = 28,
	Key_LeftControl = 29,
	Key_A = 30,
	Key_S = 31,
	Key_D = 32,
	Key_F = 33,
	Key_G = 34,
	Key_H = 35,
	Key_J = 36,
	Key_K = 37,
	Key_L = 38,
	Key_SemiColon = 39,
	Key_Apostrophe = 40,
	Key_Grave = 41,
	Key_LeftShift = 42,
	Key_BackSlash = 43,
	Key_Z = 44,
	Key_X = 45,
	Key_C = 46,
	Key_V = 47,
	Key_B = 48,
	Key_N = 49,
	Key_M = 50,
	Key_Comma = 51,
	Key_Period = 52,
	Key_Slash = 53,
	Key_RightShift = 54,
	Key_Multiply = 55,
	Key_NumPadStar = 55,
	Key_LeftAlt = 56,
	Key_LeftMenu = 56,
	Key_Space = 57,
	Key_Capital = 58,
	Key_CapsLock = 58,
	Key_F1 = 59,
	Key_F2 = 60,
	Key_F3 = 61,
	Key_F4 = 62,
	Key_F5 = 63,
	Key_F6 = 64,
	Key_F7 = 65,
	Key_F8 = 66,
	Key_F9 = 67,
	Key_F10 = 68,
	Key_Numlock = 69,
	Key_Scroll = 70,
	Key_NumPad7 = 71,
	Key_NumPad8 = 72,
	Key_NumPad9 = 73,
	Key_NumPadMinus = 74,
	Key_Subtract = 74,
	Key_NumPad4 = 75,
	Key_NumPad5 = 76,
	Key_NumPad6 = 77,
	Key_Add = 78,
	Key_NumPadPlus = 78,
	Key_NumPad1 = 79,
	Key_NumPad2 = 80,
	Key_NumPad3 = 81,
	Key_NumPad0 = 82,
	Key_Decimal = 83,
	Key_NumPadPeriod = 83,
	Key_OEM102 = 86,
	Key_F11 = 87,
	Key_F12 = 88,
	Key_F13 = 100,
	Key_F14 = 101,
	Key_F15 = 102,
	Key_Kana = 112,
	Key_AbntC1 = 115,
	Key_Convert = 121,
	Key_NoConvert = 123,
	Key_Yen = 125,
	Key_AbntC2 = 126,
	Key_NumPadEquals = 141,
	Key_Circumflex = 144,
	Key_PrevTrack = 144,
	Key_At = 145,
	Key_Colon = 146,
	Key_Underline = 147,
	Key_Kanji = 148,
	Key_Stop = 149,
	Key_AX = 150,
	Key_Unlabeled = 151,
	Key_NextTrack = 153,
	Key_NumPadEnter = 156,
	Key_RightControl = 157,
	Key_Mute = 160,
	Key_Calculator = 161,
	Key_PlayPause = 162,
	Key_MediaStop = 164,
	Key_VolumeDown = 174,
	Key_VolumeUp = 176,
	Key_WebHome = 178,
	Key_NumPadComma = 179,
	Key_Divide = 181,
	Key_NumPadSlash = 181,
	Key_SysRq = 183,
	Key_RightAlt = 184,
	Key_RightMenu = 184,
	Key_Pause = 197,
	Key_Home = 199,
	Key_Up = 200,
	Key_UpArrow = 200,
	Key_PageUp = 201,
	Key_Prior = 201,
	Key_Left = 203,
	Key_LeftArrow = 203,
	Key_Right = 205,
	Key_RightArrow = 205,
	Key_End = 207,
	Key_Down = 208,
	Key_DownArrow = 208,
	Key_Next = 209,
	Key_PageDown = 209,
	Key_Insert = 210,
	Key_Delete = 211,
	Key_LeftWindows = 219,
	Key_RightWindows = 220,
	Key_Apps = 221,
	Key_Power = 222,
	Key_Sleep = 223,
	Key_Wake = 227,
	Key_WebSearch = 229,
	Key_WebFavorites = 230,
	Key_WebRefresh = 231,
	Key_WebStop = 232,
	Key_WebForward = 233,
	Key_WebBack = 234,
	Key_MyComputer = 235,
	Key_Mail = 236,
	Key_MediaSelect = 237,
};

#endif // !defined(AFX_GLOBALDEFINES_H__5E38DA35_59BB_45B6_8C48_31D491EDCA96__INCLUDED_)
