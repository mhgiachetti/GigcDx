// Texture.h: interface for the Texture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTURE_H__2A47D640_7509_482E_AC44_A5564CB4CD96__INCLUDED_)
#define AFX_TEXTURE_H__2A47D640_7509_482E_AC44_A5564CB4CD96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"

class Texture  
{
public:
	LPD3DTEXTURE m_texture;

public:
	Texture();
	Texture(LPD3DTEXTURE texture);
	Texture(LPD3DDEVICE device, int width, int height, int numLevels, Usage usage, Format format, Pool pool);
	virtual ~Texture();

	virtual LPD3DDEVICE GetDevice();
    virtual DWORD SetPriority(DWORD PriorityNew);
    virtual DWORD GetPriority();
    virtual void PreLoad();
    virtual ResourceType GetType();
    virtual void * LockRectangle(int numLevel,LockFlags Flags, int &outPitch);
    virtual void UnlockRectangle(int numLevel);
	virtual void Dispose();
	virtual bool Disposed();
	virtual void Create(LPD3DDEVICE device, int width, int height, int numLevels, Usage usage, Format format, Pool pool);
	
	void SetTexture(LPD3DTEXTURE texture);

	operator LPD3DTEXTURE() const;
	operator LPD3DTEXTURE*() const;
	operator LPD3DTEXTURE*();

};

#endif // !defined(AFX_TEXTURE_H__2A47D640_7509_482E_AC44_A5564CB4CD96__INCLUDED_)
