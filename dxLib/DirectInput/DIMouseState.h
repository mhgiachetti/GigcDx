// DIMouseState.h: interface for the MouseState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIMOUSESTATE_H__AF986DB6_CEF0_475E_AC2B_67DCFF11852D__INCLUDED_)
#define AFX_DIMOUSESTATE_H__AF986DB6_CEF0_475E_AC2B_67DCFF11852D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../globalDefines.h"
namespace DirectInput
{
	struct MouseState  
	{
		int Z;
        int Y;
        int X;
        BYTE mouseButtons[4];
	public:
		BYTE * GetMouseButtons(){return mouseButtons;}
		operator void *()const;

	};
}

#endif // !defined(AFX_DIMOUSESTATE_H__AF986DB6_CEF0_475E_AC2B_67DCFF11852D__INCLUDED_)
