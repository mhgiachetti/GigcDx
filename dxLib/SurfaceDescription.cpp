// SurfaceDescription.cpp: implementation of the SurfaceDescription class.
//
//////////////////////////////////////////////////////////////////////

#include "SurfaceDescription.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SurfaceDescription::SurfaceDescription()
{

}

SurfaceDescription::~SurfaceDescription()
{

}

SurfaceDescription::operator D3DSURFACE_DESC()
{
	return *((D3DSURFACE_DESC*)this);
	
}

SurfaceDescription::operator D3DSURFACE_DESC*()
{
	return (D3DSURFACE_DESC*)this;
}
