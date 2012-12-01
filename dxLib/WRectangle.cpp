// WRectangle.cpp: implementation of the WRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "WRectangle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WRectangle::WRectangle()
{
	SetRectEmpty();
}

WRectangle::WRectangle( int l, int t, int r, int b )
{
	left = l;
	right = r;
	top = t;
	bottom = b;
}

WRectangle::WRectangle( const RECT& srcRect )
{
	CopyRect(&srcRect);
}

WRectangle::WRectangle( LPCRECT lpSrcRect )
{
	CopyRect(lpSrcRect);
}

WRectangle::WRectangle( POINT point, SIZE size )
{
	WRectangle(point.x,point.y,point.x+size.cx,point.y+size.cy);
}

WRectangle::WRectangle( POINT topLeft, POINT bottomRight )
{
	WRectangle(topLeft.x,topLeft.y,bottomRight.x,bottomRight.y);
}

int WRectangle::Width() const
{
	return right - left;
}

int WRectangle::Height() const
{
	return bottom - top;
}

WSize WRectangle::Size() const
{
	return WSize(Width(),Height());
}

WPoint WRectangle::TopLeft()
{
	return WPoint(left,top);
}

const WPoint WRectangle::TopLeft() const
{
	return TopLeft();
}

WPoint WRectangle::BottomRight()
{
	return WPoint(right,bottom);
}

const WPoint WRectangle::BottomRight() const
{
	return BottomRight();
}

WPoint WRectangle::CenterPoint() const
{
	return WPoint((left+right)/2,(top+bottom)/2);
}

void WRectangle::SwapLeftRight()
{
	SwapLeftRight(this);
}

void WRectangle::SwapLeftRight( LPRECT lpRect )
{
	int aux = lpRect->left;
	lpRect->left = lpRect->right;
	lpRect->right = lpRect->left;
}

WRectangle::operator LPRECT()
{
	return (LPRECT)this;
}

WRectangle::operator LPCRECT() const
{
	return (LPCRECT)this;
}

BOOL WRectangle::IsRectEmpty() const
{
	return Size()==WSize();
}

BOOL WRectangle::IsRectNull() const
{
	return (*this)==WRectangle();
}

BOOL WRectangle::PtInRect( POINT point ) const
{
	return point.x >= left && point.x <= right && point.y >= top && point.y <= bottom;
}

void WRectangle::SetRect( int x1, int y1, int x2, int y2 )
{
	left = x1;
	top = y1;
	right = x2;
	bottom = y2;
}

void WRectangle::SetRect( POINT topLeft, POINT bottomRight )
{
	SetRect(topLeft.x,topLeft.y,bottomRight.x,bottomRight.y);
}

void WRectangle::SetRectEmpty()
{
	left = right = top = bottom = 0;
}

void WRectangle::CopyRect( LPCRECT lpSrcRect )
{
	left = lpSrcRect->left;
	right = lpSrcRect->right;
	top = lpSrcRect->top;
	bottom = lpSrcRect->bottom;
}

BOOL WRectangle::EqualRect( LPCRECT lpRect ) const
{
	return left == lpRect->left && right == lpRect->right && top == lpRect->top && bottom == lpRect->bottom;
}

void WRectangle::InflateRect( int x, int y )
{
	right += x;
	bottom += y;
}

void WRectangle::InflateRect( SIZE size )
{
	InflateRect(size.cx,size.cy);
}

void WRectangle::InflateRect( LPCRECT lpRect )
{
	//TODO:
}

void WRectangle::InflateRect( int l, int t, int r, int b )
{
	//TODO:
}

void WRectangle::DeflateRect( int x, int y )
{
	//TODO:
}

void WRectangle::DeflateRect( SIZE size )
{
	//TODO:
}

void WRectangle::DeflateRect( LPCRECT lpRect )
{
	//TODO:
}

void WRectangle::DeflateRect( int l, int t, int r, int b )
{
	//TODO:
}

void WRectangle::OffsetRect( int x, int y )
{
	WSize s = Size();
	left = x;
	right = x + s.cx;
	top = y;
	bottom = y + s.cy;
}

void WRectangle::OffsetRect( SIZE size )
{
	OffsetRect(size.cx,size.cy);
}

void WRectangle::OffsetRect( POINT point )
{
	OffsetRect(point.x,point.y);
}

void WRectangle::NormalizeRect()
{
	int aux;
	if(right < left)
	{
		aux = left;
		left = right;
		right = aux;
	}
	if(bottom< top)
	{
		aux = top;
		top = bottom;
		bottom= top;
	}
}

BOOL WRectangle::IntersectRect( LPCRECT lpRect1, LPCRECT lpRect2 )
{
	int x1 = max(lpRect1->left, lpRect2->left);
	int x2 = min(lpRect1->right, lpRect2->right); 
	int y1 = max(lpRect1->top, lpRect2->top);
	int y2 = min(lpRect1->bottom, lpRect2->bottom); 
	
	if (x2 >= x1 && y2 >= y1)
	{ 
		SetRect(x1,x2,y1,y2);
	}

	SetRectEmpty();
	return false;
}

BOOL WRectangle::UnionRect( LPCRECT lpRect1, LPCRECT lpRect2 )
{
	int x1 = min(lpRect1->left, lpRect2->left);
	int x2 = max(lpRect1->right, lpRect2->right); 
	int y1 = min(lpRect1->top, lpRect2->top);
	int y2 = max(lpRect1->bottom, lpRect2->bottom);

	SetRect(x1,x2,y1,y2);

	return true;
}

BOOL WRectangle::SubtractRect( LPCRECT lpRect1, LPCRECT lpRect2 )
{
	int x1 = max(lpRect1->left, lpRect2->left);
	int x2 = min(lpRect1->right, lpRect2->right); 
	int y1 = max(lpRect1->top, lpRect2->top);
	int y2 = min(lpRect1->bottom, lpRect2->bottom);
	
	SetRect(x1,x2,y1,y2);
	return TRUE;
}

void WRectangle::operator=( const RECT& srcRect )
{
	CopyRect(&srcRect);
}

BOOL WRectangle::operator==( const RECT& rect ) const
{
	return EqualRect(&rect);
}

BOOL WRectangle::operator!=( const RECT& rect ) const
{
	return !EqualRect(&rect);
}

void WRectangle::operator+=( LPCRECT lpRect )
{
	//TODO
}

void WRectangle::operator-=( LPCRECT lpRect )
{
	//TODO
}

void WRectangle::operator&=( const RECT& rect )
{
	//TODO
}

void WRectangle::operator|=( const RECT& rect )
{
	//TODO
}

WRectangle WRectangle::operator+( LPCRECT lpRect ) const
{
	//TODO
	return WRectangle();
}

WRectangle WRectangle::operator-( LPCRECT lpRect ) const
{
	//TODO
	return WRectangle();
}

WRectangle WRectangle::operator&( const RECT& rect2 ) const
{
	//TODO
	return WRectangle();
}

WRectangle WRectangle::operator|( const RECT& rect2 ) const
{
	//TODO
	return WRectangle();
}

WRectangle WRectangle::MulDiv( int nMultiplier, int nDivisor ) const
{
	//TODO
	return WRectangle();
}

void WRectangle::SetSize( int width,int height )
{
	right = left + width;
	bottom = top + height;
}

void WRectangle::SetSize( SIZE size )
{
	SetSize(size.cx,size.cy);
}

