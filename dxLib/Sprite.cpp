// Sprite.cpp: implementation of the Sprite class.
//
//////////////////////////////////////////////////////////////////////

#include "Sprite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Sprite::Sprite()
{
	m_sprite = NULL;
}

Sprite::Sprite( LPD3DXSPRITE sprite )
{
	m_sprite = sprite;
}

Sprite::~Sprite()
{

}

Sprite::operator LPD3DXSPRITE() const
{
	return m_sprite;
}

Sprite::operator LPD3DXSPRITE*() const
{
	return (LPD3DXSPRITE*)&m_sprite;
}
