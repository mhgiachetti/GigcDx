// DIGuid.h: interface for the Guid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIGUID_H__C4231579_69A6_4323_822D_85664CFF32CB__INCLUDED_)
#define AFX_DIGUID_H__C4231579_69A6_4323_822D_85664CFF32CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../globalDefines.h"

namespace DirectInput
{
	class Guid  
	{
	public:
		unsigned int        _a;
        unsigned short      _b; 
        unsigned short      _c;
        unsigned char       _d;
        unsigned char       _e;
        unsigned char       _f; 
        unsigned char       _g;
        unsigned char       _h; 
        unsigned char       _i; 
        unsigned char       _j;
        unsigned char       _k; 


	public:
		Guid();
		Guid(const GUID &val);
		~Guid();

		operator GUID() const;
		operator GUID*() const;
		operator =(const GUID &val);

	};
}

#endif // !defined(AFX_DIGUID_H__C4231579_69A6_4323_822D_85664CFF32CB__INCLUDED_)
