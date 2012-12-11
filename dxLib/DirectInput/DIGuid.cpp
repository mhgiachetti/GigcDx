// DIGuid.cpp: implementation of the Guid class.
//
//////////////////////////////////////////////////////////////////////

#include "DIGuid.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace DirectInput;

Guid::Guid()
{

}

Guid::~Guid()
{

}

Guid::operator GUID() const
{
	return *((GUID*)this);
}

Guid::operator GUID*() const
{
	return (GUID*)this;
}

Guid::operator=(const GUID &val )
{
	*(this) = *((Guid*)&val);
}

Guid::Guid( const GUID &val )
{
	*(this) = *((Guid*)&val);
}
