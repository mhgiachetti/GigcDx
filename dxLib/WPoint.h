// WPoint.h: interface for the WPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT_H__DF9D9D24_E8A9_4F81_8F07_AA846CBC3834__INCLUDED_)
#define AFX_POINT_H__DF9D9D24_E8A9_4F81_8F07_AA846CBC3834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"

class WPoint : public POINT
{
public:
	WPoint();
	WPoint(int initX, int initY);
	WPoint(POINT initPt);
	WPoint(SIZE initSize);
	WPoint(DWORD dwPoint);
	
	void Offset(int xOffset, int yOffset);
	void Offset(POINT point);
	void Offset(SIZE size);
	
	BOOL operator==(POINT point) const;
	BOOL operator!=(POINT point) const;
	void operator+=(POINT point);
	void operator-=(POINT point);
	
	WPoint operator-() const;
	WPoint operator+(POINT point) const;
	
	WPoint operator-(POINT point) const;
};

#endif // !defined(AFX_POINT_H__DF9D9D24_E8A9_4F81_8F07_AA846CBC3834__INCLUDED_)
