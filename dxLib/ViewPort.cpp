// Viewport.cpp: implementation of the Viewport class.
//
//////////////////////////////////////////////////////////////////////

#include "Viewport.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Viewport::Viewport()
{

}

Viewport::~Viewport()
{

}

Viewport::operator D3DVIEWPORT() const
{
	return *((D3DVIEWPORT*)this);
}

Viewport::operator D3DVIEWPORT*() const
{
	return (D3DVIEWPORT*)this;
}
