// Texture.cpp: implementation of the Texture class.
//
//////////////////////////////////////////////////////////////////////

#include "Texture.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Texture::Texture()
{
	m_texture = NULL;
}

Texture::Texture( LPD3DTEXTURE texture )
{
	SetTexture(texture);
}

Texture::Texture( LPD3DDEVICE device, int width, int height, int numLevels, Usage usage, Format format, Pool pool )
{
	Create(device,width,height,numLevels,usage,format,pool);
}

Texture::~Texture()
{

}

LPD3DDEVICE Texture::GetDevice()
{
	LPD3DDEVICE device;
	m_texture->GetDevice(&device);
	return device;
}

DWORD Texture::SetPriority( DWORD PriorityNew )
{
	return m_texture->SetPriority(PriorityNew);
}

DWORD Texture::GetPriority()
{
	return m_texture->GetPriority();
}

void Texture::PreLoad()
{
	m_texture->PreLoad();
}

ResourceType Texture::GetType()
{
	return m_texture->GetType();

}

void * Texture::LockRectangle( int numLevel,LockFlags Flags, int &outPitch )
{
	D3DLOCKED_RECT lr = {0};
	m_texture->LockRect(numLevel,&lr,NULL, Flags);
	outPitch = lr.Pitch;
	return lr.pBits;
}

void Texture::UnlockRectangle(int numLevel)
{
	m_texture->UnlockRect(numLevel);
}

void Texture::Dispose()
{
	if(m_texture)
	{
		m_texture->Release();
		m_texture = NULL;
	}
}

void Texture::Create( LPD3DDEVICE device, int width, int height, int numLevels, Usage usage, Format format, Pool pool )
{
	D3DXCreateTexture(device, width,height, numLevels, usage,(D3DFORMAT)format,(D3DPOOL)pool,&m_texture);
}

void Texture::SetTexture( LPD3DTEXTURE texture )
{
	m_texture = texture;
}

Texture::operator LPD3DTEXTURE() const
{
	return m_texture;
}

Texture::operator LPD3DTEXTURE*() const
{
	return (LPD3DTEXTURE*)&m_texture;
}

Texture::operator LPD3DTEXTURE*()
{
	return (LPD3DTEXTURE*)&m_texture;
}

bool Texture::Disposed()
{
	return m_texture == NULL;
}




