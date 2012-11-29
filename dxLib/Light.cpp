// Light.cpp: implementation of the Light class.
//
//////////////////////////////////////////////////////////////////////

#include "Light.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Light::Light()
{
	//limpio todas las variables.
	ZeroMemory(&Type, ((int)&Phi - (int)&Type) + sizeof(float));
}

Light::~Light()
{

}

Light::operator D3DLIGHT() const
{
	return (D3DLIGHT)(*this);
}

Light::operator const D3DLIGHT*() const
{
	return (const D3DLIGHT*)this;
}
