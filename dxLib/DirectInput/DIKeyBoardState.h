// DIKeyBoardState.h: interface for the KeyBoardState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIKEYBOARDSTATE_H__3065C30C_A2A9_47AD_8C2B_E2B11CF35C9C__INCLUDED_)
#define AFX_DIKEYBOARDSTATE_H__3065C30C_A2A9_47AD_8C2B_E2B11CF35C9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../globalDefines.h"


namespace DirectInput
{
	struct KeyboardState  
	{
	public:
		bool keys[256];

		operator void*();
		bool operator [](Key key) const;
		bool operator [](int key) const;

	};
}

#endif // !defined(AFX_DIKEYBOARDSTATE_H__3065C30C_A2A9_47AD_8C2B_E2B11CF35C9C__INCLUDED_)
