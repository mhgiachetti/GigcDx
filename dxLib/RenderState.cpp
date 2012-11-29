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
