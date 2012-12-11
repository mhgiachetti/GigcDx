// DIDevice.h: interface for the Device class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIDEVICE_H__0E1AC3C5_4F76_47A1_BD27_006B85748E30__INCLUDED_)
#define AFX_DIDEVICE_H__0E1AC3C5_4F76_47A1_BD27_006B85748E30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../globalDefines.h"
#include "DIGuid.h"
#include "DIKeyBoardState.h"
#include "DIMouseState.h"


namespace DirectInput
{
	class Device  
	{
		LPDINPUT m_dinput;
		LPDINPUTDEVICE m_device;
	public:
		union{
			KeyboardState m_keyboardstate;
			MouseState m_mousestate;
		};
		Device();
		Device(LPDINPUTDEVICE device);
		Device(Guid deviceGuid);
		virtual ~Device();

		void SetCooperativeLevel(HWND hwnd, CooperativeLevelFlags flags);
		void Acquire();
        void Unacquire();
		void Dispose();
		KeyboardState &GetCurrentKeyboardState();
		MouseState &GetCurrentMouseState();

		PROPERTYGETF(MouseState&,CurrentMouseState,GetCurrentMouseState);
		
	};
}

#endif // !defined(AFX_DIDEVICE_H__0E1AC3C5_4F76_47A1_BD27_006B85748E30__INCLUDED_)
