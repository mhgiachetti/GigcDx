// VertexBuffer.h: interface for the VertexBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VERTEXBUFFER_H__629EB999_FDEC_4072_8BB9_AB235A7B3285__INCLUDED_)
#define AFX_VERTEXBUFFER_H__629EB999_FDEC_4072_8BB9_AB235A7B3285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"



class VertexBuffer
{
public:
	
	VertexBuffer();
	VertexBuffer(LPD3DVERTEXBUFFER vertexBuffer);
	VertexBuffer(LPD3DDEVICE device, UINT Length, Usage Usage, VertexFormat vertexFormat,Pool Pool);

	virtual ~VertexBuffer();

	LPD3DVERTEXBUFFER m_vBuffer;

	//STDMETHOD_(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
    //STDMETHOD_(ULONG,AddRef)(THIS);
    //STDMETHOD_(ULONG,Release)(THIS);
	
    /*** IDirect3DResource9 methods ***/
	virtual LPD3DDEVICE GetDevice();
    virtual void SetPrivateData(const void* pData,DWORD SizeOfData,DWORD Flags);
    virtual void GetPrivateData(void* pData,DWORD* pSizeOfData);
    virtual void FreePrivateData();
    virtual DWORD SetPriority(DWORD PriorityNew);
    virtual DWORD GetPriority();
    virtual void PreLoad();
    virtual ResourceType GetType();
    virtual void * Lock(UINT OffsetToLock,UINT SizeToLock,LockFlags Flags);
    virtual void Unlock();
    virtual VertexBufferDescription GetDesc();
	virtual void Release();
	virtual void Create(LPD3DDEVICE device, UINT Length, Usage Usage, VertexFormat vertexFormat,Pool Pool);
	virtual void SetData(void * pData,int dataSize, LockFlags Flags);

	operator LPD3DVERTEXBUFFER(void);
	operator LPD3DVERTEXBUFFER*(void);
};

#endif // !defined(AFX_VERTEXBUFFER_H__629EB999_FDEC_4072_8BB9_AB235A7B3285__INCLUDED_)
