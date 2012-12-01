// WRectangle.h: interface for the WRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__4CB3C13F_DF5B_4C49_BAFB_D4469E23ABC9__INCLUDED_)
#define AFX_RECTANGLE_H__4CB3C13F_DF5B_4C49_BAFB_D4469E23ABC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"
#include "WSize.h"
#include "WPoint.h"

class WRectangle : public RECT
{
public:

	// uninitialized rectangle
	WRectangle();
	// from left, top, right, and bottom
	WRectangle(int l, int t, int r, int b);
	// copy constructor
	WRectangle(const RECT& srcRect);
	// from a pointer to another rect
	WRectangle(LPCRECT lpSrcRect);
	// from a point and size
	WRectangle(POINT point, SIZE size);
	// from two points
	WRectangle(POINT topLeft, POINT bottomRight);

	// retrieves the width
	int Width() const;
	// returns the height
	int Height() const;
	// returns the size
	WSize Size() const;
	void SetSize(int width,int height);
	void SetSize(SIZE size);
	// reference to the top-left point
	WPoint TopLeft();
	// reference to the bottom-right point
	WPoint BottomRight();
	// const reference to the top-left point
	const WPoint TopLeft() const;
	// const reference to the bottom-right point
	const WPoint BottomRight() const;
	// the geometric center point of the rectangle
	WPoint CenterPoint() const;
	// swap the left and right
	void SwapLeftRight();
	static void SwapLeftRight(LPRECT lpRect);

	// convert between CRect and LPRECT/LPCRECT (no need for &)
	operator LPRECT();
	operator LPCRECT() const;

	// returns TRUE if rectangle has no area
	BOOL IsRectEmpty() const;
	// returns TRUE if rectangle is at (0,0) and has no area
	BOOL IsRectNull() const;
	// returns TRUE if point is within rectangle
	BOOL PtInRect(POINT point) const;

// Operations

	// set rectangle from left, top, right, and bottom
	void SetRect(int x1, int y1, int x2, int y2);
	void SetRect(POINT topLeft, POINT bottomRight);
	// empty the rectangle
	void SetRectEmpty();
	// copy from another rectangle
	void CopyRect(LPCRECT lpSrcRect);
	// TRUE if exactly the same as another rectangle
	BOOL EqualRect(LPCRECT lpRect) const;

	// inflate rectangle's width and height without
	// moving its top or left
	void InflateRect(int x, int y);
	void InflateRect(SIZE size);
	void InflateRect(LPCRECT lpRect);
	void InflateRect(int l, int t, int r, int b);
	// deflate the rectangle's width and height without
	// moving its top or left
	void DeflateRect(int x, int y);
	void DeflateRect(SIZE size);
	void DeflateRect(LPCRECT lpRect);
	void DeflateRect(int l, int t, int r, int b);

	// translate the rectangle by moving its top and left
	void OffsetRect(int x, int y);
	void OffsetRect(SIZE size);
	void OffsetRect(POINT point);
	void NormalizeRect();

	// set this rectangle to intersection of two others
	BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2);

	// set this rectangle to bounding union of two others
	BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2);

	// set this rectangle to minimum of two others
	BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2);

// Additional Operations
	void operator=(const RECT& srcRect);
	BOOL operator==(const RECT& rect) const;
	BOOL operator!=(const RECT& rect) const;
	void operator+=(LPCRECT lpRect);
	void operator-=(LPCRECT lpRect);
	void operator&=(const RECT& rect);
	void operator|=(const RECT& rect);

// Operators returning CRect values
	WRectangle operator+(LPCRECT lpRect) const;
	WRectangle operator-(LPCRECT lpRect) const;
	WRectangle operator&(const RECT& rect2) const;
	WRectangle operator|(const RECT& rect2) const;
	WRectangle MulDiv(int nMultiplier, int nDivisor) const;
};

#endif // !defined(AFX_RECTANGLE_H__4CB3C13F_DF5B_4C49_BAFB_D4469E23ABC9__INCLUDED_)
