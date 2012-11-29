// Light.h: interface for the Light class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGLIGHT_H__E7C7711F_C492_408F_B566_1F1FD1F9C851__INCLUDED_)
#define AFX_MGLIGHT_H__E7C7711F_C492_408F_B566_1F1FD1F9C851__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
#include "Vector3.h"
#include "ColorValue.h"

struct Light
{
public:
	LightType		Type;            /* Type of light source */
    ColorValue	Diffuse;         /* Diffuse color of light */
    ColorValue	Specular;        /* Specular color of light */
    ColorValue	Ambient;         /* Ambient color of light */
    Vector3       Position;         /* Position in world space */
    Vector3       Direction;        /* Direction in world space */
    float           Range;            /* Cutoff range */
    float           Falloff;          /* Falloff */
    float           Attenuation0;     /* Constant attenuation */
    float           Attenuation1;     /* Linear attenuation */
    float           Attenuation2;     /* Quadratic attenuation */
    float           Theta;            /* Inner angle of spotlight cone */
    float           Phi; 

public:
	Light();
	~Light();

	operator D3DLIGHT()const;
	operator const D3DLIGHT*()const;
		

};

#endif // !defined(AFX_MGLIGHT_H__E7C7711F_C492_408F_B566_1F1FD1F9C851__INCLUDED_)
