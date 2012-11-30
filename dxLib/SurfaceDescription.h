// SurfaceDescription.h: interface for the SurfaceDescription class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SURFACEDESCRIPTION_H__AAFE73B9_7B5C_4EBD_8BD2_AEDEE233EE9E__INCLUDED_)
#define AFX_SURFACEDESCRIPTION_H__AAFE73B9_7B5C_4EBD_8BD2_AEDEE233EE9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"

struct SurfaceDescription  
{
public:
	Format Format;
	ResourceType Type;
	Usage Usage;
	Pool Pool;
	MultiSampleType MultiSampleType;
	int MultiSampleQuality;
	int Width;
	int Height;

public:
	SurfaceDescription();
	~SurfaceDescription();

	operator D3DSURFACE_DESC*();
	operator D3DSURFACE_DESC();

};

#endif // !defined(AFX_SURFACEDESCRIPTION_H__AAFE73B9_7B5C_4EBD_8BD2_AEDEE233EE9E__INCLUDED_)
