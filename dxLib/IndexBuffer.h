// IndexBuffer.h: interface for the IndexBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INDEXBUFFER_H__C1E43635_3472_48AE_998A_31A13DF69A8F__INCLUDED_)
#define AFX_INDEXBUFFER_H__C1E43635_3472_48AE_998A_31A13DF69A8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"

class IndexBuffer  
{
public:

	LPD3DINDEXBUFFER m_iBuffer;

public:
	virtual ~IndexBuffer();

	IndexBuffer();
	IndexBuffer(LPD3DINDEXBUFFER indexBuffer);
	IndexBuffer(LPD3DDEVICE device, UINT sizeOfBufferInBytes, Usage Usage, Pool Pool, bool sixteenBitIndices);
	
	
	
	
	//STDMETHOD_(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
    //STDMETHOD_(ULONG,AddRef)(THIS);
    //STDMETHOD_(ULONG,Release)(THIS);
	
    /*** IDirect3DResource9 methods ***/
	virtual LPD3DDEVICE GetDevice();
    virtual DWORD SetPriority(DWORD PriorityNew);
    virtual DWORD GetPriority();
    virtual void PreLoad();
    virtual ResourceType GetType();
    virtual void * Lock(UINT OffsetToLock,UINT SizeToLock,LockFlags Flags);
    virtual void Unlock();
    //virtual VertexBufferDescription GetDesc();
	virtual void Release();
	virtual void Create(LPD3DDEVICE device, UINT sizeOfBufferInBytes, Usage Usage, Pool Pool, bool sixteenBitIndices);
	virtual void SetData(void * pData,int dataSize, LockFlags Flags);
	
	operator LPD3DINDEXBUFFER(void);
	operator LPD3DINDEXBUFFER*(void);

};

#endif // !defined(AFX_INDEXBUFFER_H__C1E43635_3472_48AE_998A_31A13DF69A8F__INCLUDED_)
