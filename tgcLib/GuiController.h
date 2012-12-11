// GuiController.h: interface for the GuiController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GUICONTROLLER_H__0E48FCC6_A5B1_48B4_8AA0_9E01B9BA6FDE__INCLUDED_)
#define AFX_GUICONTROLLER_H__0E48FCC6_A5B1_48B4_8AA0_9E01B9BA6FDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "..\dxLib\dxLib.h"
#include "TgcD3dDevice.h"

class GuiController  
{
public:
	

public:
	static GuiController Instance;
	
	GuiController();
	virtual ~GuiController();

//protected:
public:	
	static void newInstance();

public:
	Device m_device;
	PROPERTYGETF(Device,D3dDevice,GetD3dDevice);
	/// <summary>
	/// Direct3D Device
	/// </summary>
	Device GetD3dDevice();
	void stopCurrentExample();

};

#endif // !defined(AFX_GUICONTROLLER_H__0E48FCC6_A5B1_48B4_8AA0_9E01B9BA6FDE__INCLUDED_)
