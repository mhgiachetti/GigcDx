// WSize.cpp: implementation of the WSize class.
//
//////////////////////////////////////////////////////////////////////

#include "WSize.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WSize::WSize()
{
	this->cx = 0;
	this->cy = 0;
}

WSize::WSize( int initCX, int initCY )
{
	cx = initCX;
	cy = initCY;
}

WSize::WSize( SIZE initSize )
{
	cx = initSize.cx;
	cy = initSize.cy;
}

WSize::WSize( POINT initPt )
{
	cx = initPt.x;
	cy = initPt.y;
}

WSize::WSize( DWORD dwSize )
{
	cx = dwSize;
	cy = dwSize;
}

BOOL WSize::operator==( SIZE size ) const
{
	return cx == size.cx && cy == size.cy;
}

BOOL WSize::operator!=( SIZE size ) const
{
	return !((*this) == size);
}

void WSize::operator+=( SIZE size )
{
	cx+=size.cx;
	cy+=size.cy;
}

void WSize::operator-=( SIZE size )
{
	cx-=size.cx;
	cy-=size.cy;
}

WSize WSize::operator+( SIZE size ) const
{
	return WSize(cx+size.cx,cy+size.cy);
}

WSize WSize::operator-( SIZE size ) const
{
	return WSize(cx-size.cx,cy-size.cy);
}

WSize WSize::operator-() const
{
	return WSize(-cx,-cy);
}
