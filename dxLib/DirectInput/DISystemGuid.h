// DISystemGuid.h: interface for the SystemGuid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISYSTEMGUID_H__4D75DCF3_BBD0_42B8_8B70_BDA04C65254F__INCLUDED_)
#define AFX_DISYSTEMGUID_H__4D75DCF3_BBD0_42B8_8B70_BDA04C65254F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../globalDefines.h"
#include "DIGuid.h"

namespace DirectInput
{
	class SystemGuid  
	{
	public:
		static const Guid Mouse;
        static const Guid Keyboard;
	public:
		SystemGuid();
		~SystemGuid();

	};
}

#endif // !defined(AFX_DISYSTEMGUID_H__4D75DCF3_BBD0_42B8_8B70_BDA04C65254F__INCLUDED_)
