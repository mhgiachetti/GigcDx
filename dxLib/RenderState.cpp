// RenderState.cpp: implementation of the RenderState class.
//
//////////////////////////////////////////////////////////////////////

#include "RenderState.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RenderState::RenderState()
{

}

RenderState::RenderState( LPD3DDEVICE device )
{
	SetDevice(device);
}

RenderState::~RenderState()
{

}

void RenderState::SetDevice( LPD3DDEVICE device )
{
	m_device = device;
}

void RenderState::SetLighting( bool enable )
{
	m_device->SetRenderState(D3DRS_LIGHTING, enable);
}

bool RenderState::GetLighting()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_LIGHTING,&val);
	return val > 0;
}

void RenderState::SetCullMode( Cull cullMode )
{
	m_device->SetRenderState(D3DRS_CULLMODE, cullMode);
}

Cull RenderState::GetCullMode()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_CULLMODE,&val);
	return (Cull)val;
}

void RenderState::SetZBufferEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_ZENABLE, enable);
}

bool RenderState::GetZBufferEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_ZENABLE,&val);
	return val > 0;
}

void RenderState::SetAlphaBlendEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, enable);
}

bool RenderState::GetAlphaBlendEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_ALPHABLENDENABLE,&val);
	return val > 0;
}

void RenderState::SetAmbient( UINT color )
{
	m_device->SetRenderState(D3DRS_AMBIENT, color);
}

UINT RenderState::GetAmbient()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_AMBIENT,&val);
	return val;	
}

void RenderState::SetNormalizeNormals( bool enable )
{
	m_device->SetRenderState(D3DRS_NORMALIZENORMALS, enable);
}

bool RenderState::GetNormalizeNormals()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_NORMALIZENORMALS,&val);
	return val > 0;
}

void RenderState::SetBlendOperation( BlendOperation blendOp )
{
	m_device->SetRenderState(D3DRS_BLENDOP, blendOp);
}

BlendOperation RenderState::GetBlendOperation()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_BLENDOP,&val);
	return (BlendOperation)val;
}

void RenderState::SetSourceBlend( Blend blend )
{
	m_device->SetRenderState(D3DRS_SRCBLEND, blend);
}

Blend RenderState::GetSourceBlend()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_SRCBLEND,&val);
	return (Blend)val;
}

void RenderState::SetDestinationBlend( Blend blend )
{
	m_device->SetRenderState(D3DRS_DESTBLEND, blend);
}

Blend RenderState::GetDestinationBlend()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_DESTBLEND,&val);
	return (Blend)val;
}

void RenderState::SetPointSize( float size )
{
	m_device->SetRenderState(D3DRS_POINTSIZE, *((DWORD*)&size));
}

float RenderState::GetPointSize()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_POINTSIZE,&val);
	return *((float*)&val);
}

void RenderState::SetFillMode( FillMode mode )
{
	m_device->SetRenderState(D3DRS_FILLMODE,mode);
}

FillMode RenderState::GetFillMode()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_FILLMODE,&val);
	return (FillMode)val;
}

void RenderState::SetSpecularEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_SPECULARENABLE, enable);
}

bool RenderState::GetSpecularEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_SPECULARENABLE,&val);
	return val > 0;
}

void RenderState::SetShadeMode( ShadeMode mode )
{
	m_device->SetRenderState(D3DRS_SHADEMODE,mode);
}

ShadeMode RenderState::GetShadeMode()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_SHADEMODE,&val);
	return (ShadeMode)val;
}

void RenderState::SetMultiSampleAntiAlias( bool enable )
{
	m_device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, enable);
}

bool RenderState::GetMultiSampleAntiAlias()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_MULTISAMPLEANTIALIAS,&val);
	return val > 0;
}

void RenderState::SetSlopeScaleDepthBias( float bias )
{
	m_device->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, *((DWORD*)&bias));
}

float RenderState::GetSlopeScaleDepthBias()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_SLOPESCALEDEPTHBIAS,&val);
	return *((float*)&val);
}

void RenderState::SetDepthBias( float bias )
{
	m_device->SetRenderState(D3DRS_DEPTHBIAS, *((DWORD*)&bias));
}

float RenderState::GetDepthBias()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_DEPTHBIAS,&val);
	return *((float*)&val);
}

void RenderState::SetColorVertex( bool enable )
{
	m_device->SetRenderState(D3DRS_COLORVERTEX, enable);
}

bool RenderState::GetColorVertex()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_COLORVERTEX,&val);
	return val > 0;	
}

void RenderState::SetFogEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_FOGENABLE, enable);
}

bool RenderState::GetFogEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_FOGENABLE,&val);
	return val > 0;
}

void RenderState::SetAlphaTestEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_ALPHATESTENABLE, enable);
}

bool RenderState::GetAlphaTestEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_ALPHATESTENABLE,&val);
	return val > 0;
}

void RenderState::SetReferenceAlpha( int value )
{
	m_device->SetRenderState(D3DRS_ALPHAREF, value);
}

int RenderState::GetReferenceAlpha()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_ALPHAREF,&val);
	return val;
}

void RenderState::SetAlphaFunction( Compare function )
{
	m_device->SetRenderState(D3DRS_ALPHAFUNC, function);
}

Compare RenderState::GetAlphaFunction()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_ALPHAFUNC,&val);
	return (Compare)val;
}

void RenderState::SetPointSpriteEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_POINTSPRITEENABLE, enable);
}

bool RenderState::GetPointSpriteEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_POINTSPRITEENABLE,&val);
	return val > 0;
}

void RenderState::SetPointScaleEnable( bool enable )
{
	m_device->SetRenderState(D3DRS_POINTSCALEENABLE, enable);
}

bool RenderState::GetPointScaleEnable()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_POINTSCALEENABLE,&val);
	return val > 0;
}

void RenderState::SetPointScaleA( float value )
{
	m_device->SetRenderState(D3DRS_POINTSCALE_A, *((DWORD*)&value));
}

float RenderState::GetPointScaleA()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_POINTSCALE_A,&val);
	return *((float*)&val);
}

void RenderState::SetPointScaleB( float value )
{
	m_device->SetRenderState(D3DRS_POINTSCALE_B, *((DWORD*)&value));
}

float RenderState::GetPointScaleB()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_POINTSCALE_B,&val);
	return *((float*)&val);
}

void RenderState::SetPointScaleC( float value )
{
	m_device->SetRenderState(D3DRS_POINTSCALE_C, *((DWORD*)&value));
}

float RenderState::GetPointScaleC()
{
	DWORD val;
	m_device->GetRenderState(D3DRS_POINTSCALE_C,&val);
	return *((float*)&val);
}
