// Material.h: interface for the Material class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGMATERIAL_H__B537C7DA_A30E_4DF3_8848_FD97A7D36541__INCLUDED_)
#define AFX_MGMATERIAL_H__B537C7DA_A30E_4DF3_8848_FD97A7D36541__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ColorValue.h"
#include "globalDefines.h"

struct Material  
{
public:
	ColorValue   Diffuse;        /* Diffuse color RGBA */
    ColorValue   Ambient;        /* Ambient color RGB */
    ColorValue   Specular;       /* Specular 'shininess' */
    ColorValue   Emissive;       /* Emissive color RGB */
    float          Power;          /* Sharpness if specular highlight */

public:
	Material();
	~Material();

	operator D3DMATERIAL()const;
	operator const D3DMATERIAL*()const;
	operator D3DMATERIAL*();

};

#endif // !defined(AFX_MGMATERIAL_H__B537C7DA_A30E_4DF3_8848_FD97A7D36541__INCLUDED_)
