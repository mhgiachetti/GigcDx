// ExtendedMaterial.h: interface for the ExtendedMaterial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGEXTENDEDMATERIAL_H__BF43F3EC_4CD3_4582_9CCF_7255E5721113__INCLUDED_)
#define AFX_MGEXTENDEDMATERIAL_H__BF43F3EC_4CD3_4582_9CCF_7255E5721113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Material.h"
#include <string>
using namespace std;

struct ExtendedMaterial  
{

public:
	Material  Material3D;
	string		TextureFilename;

public:
	ExtendedMaterial();
	~ExtendedMaterial();

};

#endif // !defined(AFX_MGEXTENDEDMATERIAL_H__BF43F3EC_4CD3_4582_9CCF_7255E5721113__INCLUDED_)
