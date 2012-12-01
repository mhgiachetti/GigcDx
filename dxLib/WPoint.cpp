// WPoint.cpp: implementation of the WPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "WPoint.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WPoint::WPoint()
{
	x = 0;
	y = 0;
}

WPoint::WPoint( int initX, int initY )
{
	x = initX;
	y = initY;
}

WPoint::WPoint( POINT initPt )
{
	x = initPt.x;
	y = initPt.y;
}

WPoint::WPoint( SIZE initSize )
{
	x = initSize.cx;
	y = initSize.cy;
}

WPoint::WPoint( DWORD dwPoint )
{
	x = dwPoint;
	y = dwPoint;
}

void WPoint::Offset( int xOffset, int yOffset )
{
	x += xOffset;
	y += yOffset;
}

void WPoint::Offset( POINT point )
{
	x += point.x;
	y += point.y;
}

void WPoint::Offset( SIZE size )
{
	Offset(size.cx,size.cy);
}

BOOL WPoint::operator==( POINT point ) const
{
	return x == point.x && y == point.y;
}

BOOL WPoint::operator!=( POINT point ) const
{
	return !((*this)==point);
}

void WPoint::operator+=( POINT point )
{
	x+= point.x;
	y+= point.y;
}

void WPoint::operator-=( POINT point )
{
	x-= point.x;
	y-= point.y;
}

WPoint WPoint::operator-() const
{
	return WPoint(-x,-y);
}

WPoint WPoint::operator+( POINT point ) const
{
	return WPoint(x+point.x,y+point.y);
}

WPoint WPoint::operator-( POINT point ) const
{
	return WPoint(x-point.x,y-point.y);
}

