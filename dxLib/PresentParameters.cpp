// PresentParameters.cpp: implementation of the PresentParameters class.
//
//////////////////////////////////////////////////////////////////////

#include "PresentParameters.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PresentParameters::PresentParameters()
{
	ZeroMemory(this, sizeof(PresentParameters));
}

PresentParameters::~PresentParameters()
{

}

PresentParameters::operator D3DPRESENT_PARAMETERS() const
{
	return *((D3DPRESENT_PARAMETERS*)this);
}

PresentParameters::operator D3DPRESENT_PARAMETERS*() const
{
	return (D3DPRESENT_PARAMETERS*)this;
}
