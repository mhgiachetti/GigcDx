// Device.cpp: implementation of the Device class.
//
//////////////////////////////////////////////////////////////////////

#include "Device.h"
#include "Manager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Device::Device()
{

}

Device::Device(LPD3DDEVICE device)
{
	SetDevice(device);
}

Device::Device( int adapter, DeviceType deviceType, HWND renderWindow, CreateFlags behaviorFlags, const PresentParameters &presentationParameters )
{
	Manager::GetInterface()->CreateDevice(adapter,(D3DDEVTYPE)deviceType,renderWindow, behaviorFlags, presentationParameters, &m_device);
}

Device::~Device()
{

}

Device::operator LPD3DDEVICE( void ) const
{
	return m_device;
}

Device::operator LPD3DDEVICE( void )
{
	return m_device;
}

void Device::BeginScene()
{
	m_device->BeginScene();
}

void Device::EndScene()
{
	m_device->EndScene();
}

void Device::Clear(ClearFlags flags, int color, float zdepth, DWORD stencil )
{
	m_device->Clear(0,NULL,flags,color,zdepth,stencil);
}

void Device::SetVertexFormat( VertexFormat format )
{
	m_device->SetFVF(format);
}

VertexFormat Device::GetVertexFormat()
{
	unsigned long format;
	m_device->GetFVF(&format);
	return (VertexFormat)format;
}

void Device::SetStreamSource( int streamNumber, LPD3DVERTEXBUFFER vb, int offset, int stride )
{
	m_device->SetStreamSource(streamNumber, vb, offset,stride);
}

void Device::SetDevice( LPD3DDEVICE device )
{
	m_device = device;
	Transform.SetDevice(device);
	RenderState.SetDevice(device);
}

void Device::Dispose()
{
	m_device->Release();
}

void Device::Present()
{
	m_device->Present(NULL,NULL,NULL,NULL);
}

void Device::DrawPrimitives( PrimitiveType pt, int startVertex, int primitiveCount )
{
	m_device->DrawPrimitive((D3DPRIMITIVETYPE)pt,startVertex,primitiveCount);
}

void Device::DrawIndexedPrimitives( PrimitiveType primitiveType, int baseVertex, int minVertexIndex, int numVertices, int startIndex, int primCount )
{
	m_device->DrawIndexedPrimitive((D3DPRIMITIVETYPE)primitiveType,baseVertex,minVertexIndex,numVertices,startIndex,primCount);
}

void Device::SetLight( int index, const Light &light )
{
	m_device->SetLight(index, light);
}

void Device::LightEnable( int index, bool enable )
{
	m_device->LightEnable(index,enable);
}

void Device::Setmaterial( const Material &mat )
{
	m_device->SetMaterial(mat);
}

void Device::DrawUserPrimitives( PrimitiveType pt, int primitiveCount,const void * pVertices, int stride )
{
	m_device->DrawPrimitiveUP((D3DPRIMITIVETYPE)pt, primitiveCount, pVertices, stride);
}

void Device::SetTexture( int stage, const Texture &texture )
{
	m_device->SetTexture(stage, texture);
}

void Device::SetSamplerState( int stage, SamplerStageStates state, int value )
{
	m_device->SetSamplerState(stage,(D3DSAMPLERSTATETYPE)state,value);
}

Device::operator LPD3DDEVICE*( void ) const
{
	return (LPD3DDEVICE*)&m_device;
	
}

Viewport Device::Getviewport()
{
	Viewport v;
	m_device->GetViewport(v);
	return v;
}

void Device::Setviewport( Viewport viewport )
{
	m_device->SetViewport(viewport);
}

Material Device::Getmaterial()
{
	Material mat;
	m_device->GetMaterial(mat);
	return mat;
}

IndexBuffer Device::GetIndices()
{
	IndexBuffer ib;
	m_device->GetIndices(ib);
	return ib;
}

void Device::SetIndices( const IndexBuffer &ib )
{
	m_device->SetIndices(ib);
}

