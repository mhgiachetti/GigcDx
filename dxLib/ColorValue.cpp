// ColorValue.cpp: implementation of the ColorValue class.
//
//////////////////////////////////////////////////////////////////////

#include "ColorValue.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ColorValue::ColorValue()
{

}

ColorValue::ColorValue( float r, float g, float b, float a )
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

ColorValue::~ColorValue()
{

}

ColorValue::operator D3DCOLORVALUE() const
{
	return (D3DCOLORVALUE)(*this);
}
