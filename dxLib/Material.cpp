// Material.cpp: implementation of the Material class.
//
//////////////////////////////////////////////////////////////////////

#include "Material.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Material::Material()
{
	ZeroMemory(&Diffuse,((int)&Power - (int)&Diffuse) + sizeof(float));
}

Material::~Material()
{
}

Material::operator D3DMATERIAL() const
{
	return (D3DMATERIAL)(*this);
}

Material::operator const D3DMATERIAL*() const
{
	return (const D3DMATERIAL *)this;
}
