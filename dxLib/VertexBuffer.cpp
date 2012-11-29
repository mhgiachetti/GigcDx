// VertexBuffer.cpp: implementation of the VertexBuffer class.
//
//////////////////////////////////////////////////////////////////////

#include "VertexBuffer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


VertexBuffer::VertexBuffer()
{
	
}

VertexBuffer::VertexBuffer(LPD3DVERTEXBUFFER vertexBuffer)
{
	m_vBuffer = vertexBuffer;
}

VertexBuffer::VertexBuffer(LPD3DDEVICE device, UINT Length, Usage Usage, VertexFormat vertexFormat,Pool Pool)
{
	Create(device, Length,Usage,vertexFormat,Pool);
}

VertexBuffer::~VertexBuffer()
{

}

LPD3DDEVICE VertexBuffer::GetDevice()
{
	LPD3DDEVICE device;
	m_vBuffer->GetDevice(&device);
	return device;
}

void VertexBuffer::SetPrivateData( const void* pData,DWORD SizeOfData,DWORD Flags )
{
	//TODO:
}

void VertexBuffer::GetPrivateData( void* pData,DWORD* pSizeOfData )
{
	//TODO:	
}

void VertexBuffer::FreePrivateData()
{
	//TODO:
}

DWORD VertexBuffer::SetPriority( DWORD PriorityNew )
{
	return m_vBuffer->SetPriority(PriorityNew);
}

DWORD VertexBuffer::GetPriority()
{
	return m_vBuffer->GetPriority();
}

void VertexBuffer::PreLoad()
{
	m_vBuffer->PreLoad();
}

ResourceType VertexBuffer::GetType()
{
	return m_vBuffer->GetType();
}

void * VertexBuffer::Lock( UINT OffsetToLock,UINT SizeToLock,LockFlags Flags )
{
	void * data;

	m_vBuffer->Lock(OffsetToLock,SizeToLock,&data,Flags);
	return data;
}

void VertexBuffer::Unlock()
{
	m_vBuffer->Unlock();
}

VertexBufferDescription VertexBuffer::GetDesc()
{
	VertexBufferDescription desc;
	ZeroMemory(&desc,sizeof(VertexBufferDescription));
	m_vBuffer->GetDesc(&desc);

	return desc;
}

void VertexBuffer::Release()
{
	m_vBuffer->Release();
}

VertexBuffer::operator LPD3DVERTEXBUFFER( void )
{
	return m_vBuffer;
}

VertexBuffer::operator LPD3DVERTEXBUFFER*( void )
{
	return &m_vBuffer;
}

void VertexBuffer::Create( LPD3DDEVICE device, UINT Length, Usage Usage, VertexFormat vertexFormat,Pool Pool )
{
	device->CreateVertexBuffer(Length,Usage,vertexFormat,(D3DPOOL)Pool,&m_vBuffer,NULL);
}

void VertexBuffer::SetData( void * pData,int dataSize, LockFlags Flags )
{
	void * vbdata = Lock(0,0,Flags);

	memcpy(vbdata, pData, dataSize);

	Unlock();
}
