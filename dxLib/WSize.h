// WSize.h: interface for the WSize class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIZE_H__5E5AF9E6_9FBF_4202_9F46_C72FC7777F87__INCLUDED_)
#define AFX_SIZE_H__5E5AF9E6_9FBF_4202_9F46_C72FC7777F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
class WSize : public SIZE 
{
public:
	WSize();
	WSize(int initCX, int initCY);
	WSize(SIZE initSize);
	WSize(POINT initPt);
	WSize(DWORD dwSize);
	
	BOOL operator==(SIZE size) const;
	BOOL operator!=(SIZE size) const;
	void operator+=(SIZE size);
	void operator-=(SIZE size);
	
	WSize operator+(SIZE size) const;
	WSize operator-(SIZE size) const;
	WSize operator-() const;
};

#endif // !defined(AFX_SIZE_H__5E5AF9E6_9FBF_4202_9F46_C72FC7777F87__INCLUDED_)
