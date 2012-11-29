// IndexBuffer.cpp: implementation of the IndexBuffer class.
//
//////////////////////////////////////////////////////////////////////

#include "IndexBuffer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IndexBuffer::IndexBuffer()
{

}

IndexBuffer::IndexBuffer( LPD3DINDEXBUFFER indexBuffer )
{
	m_iBuffer = indexBuffer;
}

IndexBuffer::IndexBuffer( LPD3DDEVICE device, UINT sizeOfBufferInBytes, Usage Usage, Pool Pool, bool sixteenBitIndices )
{
	Create(device,sizeOfBufferInBytes,Usage,Pool,sixteenBitIndices);
}

IndexBuffer::~IndexBuffer()
{

}

void IndexBuffer::Create( LPD3DDEVICE device, UINT sizeOfBufferInBytes, Usage Usage, Pool Pool, bool sixteenBitIndices )
{
	device->CreateIndexBuffer(sizeOfBufferInBytes,Usage,sixteenBitIndices?D3DFMT_INDEX16:D3DFMT_INDEX32,(D3DPOOL)Pool,&m_iBuffer,NULL);
}

void * IndexBuffer::Lock( UINT OffsetToLock,UINT SizeToLock,LockFlags Flags )
{
	void * data;
	
	m_iBuffer->Lock(OffsetToLock,SizeToLock,&data,Flags);
	return data;
}

void IndexBuffer::Unlock()
{
	m_iBuffer->Unlock();
}

void IndexBuffer::SetData( void * pData,int dataSize, LockFlags Flags )
{
	void * vbdata = Lock(0,0,Flags);
	
	memcpy(vbdata, pData, dataSize);
	
	Unlock();
}

DWORD IndexBuffer::SetPriority( DWORD PriorityNew )
{
	return m_iBuffer->SetPriority(PriorityNew);
}

DWORD IndexBuffer::GetPriority()
{
	return m_iBuffer->GetPriority();
}

void IndexBuffer::PreLoad()
{
	m_iBuffer->PreLoad();
}

ResourceType IndexBuffer::GetType()
{
	return m_iBuffer->GetType();
}

void IndexBuffer::Dispose()
{
	m_iBuffer->Release();
}

LPD3DDEVICE IndexBuffer::GetDevice()
{
	LPD3DDEVICE device;
	m_iBuffer->GetDevice(&device);
	return device;
}


IndexBuffer::operator LPD3DINDEXBUFFER( void )
{
	return m_iBuffer;
}

IndexBuffer::operator LPD3DINDEXBUFFER*( void )
{
	return &m_iBuffer;
}
