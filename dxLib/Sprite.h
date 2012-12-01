// Sprite.h: interface for the Sprite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITE_H__44B94723_48A7_48C8_8402_8FBE453FF4CC__INCLUDED_)
#define AFX_SPRITE_H__44B94723_48A7_48C8_8402_8FBE453FF4CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
class Sprite  
{
public:
	LPD3DXSPRITE m_sprite;
public:
	Sprite();
	Sprite(LPD3DXSPRITE sprite);
	virtual ~Sprite();

	operator LPD3DXSPRITE()const;
	operator LPD3DXSPRITE*()const;

};

#endif // !defined(AFX_SPRITE_H__44B94723_48A7_48C8_8402_8FBE453FF4CC__INCLUDED_)
