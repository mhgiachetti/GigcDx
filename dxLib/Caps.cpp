// Caps.cpp: implementation of the Caps class.
//
//////////////////////////////////////////////////////////////////////

#include "Caps.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Caps::Caps()
{

}

Caps::~Caps()
{

}

Caps::operator D3DCAPS() const
{
	return *((D3DCAPS*)this);
}

Caps::operator D3DCAPS*() const
{
	return (D3DCAPS*)this;
}
