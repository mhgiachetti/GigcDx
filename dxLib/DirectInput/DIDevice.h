// DIDevice.h: interface for the Device class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIDEVICE_H__0E1AC3C5_4F76_47A1_BD27_006B85748E30__INCLUDED_)
#define AFX_DIDEVICE_H__0E1AC3C5_4F76_47A1_BD27_006B85748E30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../globalDefines.h"

namespace DirectInput
{
	class Device  
	{
		LPDIRECTINPUT8 aa;
	public:
		Device();
		virtual ~Device();
		
	};
}

#endif // !defined(AFX_DIDEVICE_H__0E1AC3C5_4F76_47A1_BD27_006B85748E30__INCLUDED_)
