// ColorValue.h: interface for the ColorValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGCOLORVALUE_H__321EABE7_A78D_4C28_8D43_FCE1222BD6AB__INCLUDED_)
#define AFX_MGCOLORVALUE_H__321EABE7_A78D_4C28_8D43_FCE1222BD6AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"


struct ColorValue  
{
public:
	float r, g, b, a;
public:
	ColorValue();
	ColorValue( float r, float g, float b, float a );
	~ColorValue();

	operator D3DCOLORVALUE() const;

};

#endif // !defined(AFX_MGCOLORVALUE_H__321EABE7_A78D_4C28_8D43_FCE1222BD6AB__INCLUDED_)
