// DeviceTest.h: interface for the DeviceTest class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEVICETEST_H__D2C9A3B9_9301_4BAD_953E_743F12DC9970__INCLUDED_)
#define AFX_DEVICETEST_H__D2C9A3B9_9301_4BAD_953E_743F12DC9970__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../dxLib/dxLib.h"

class DeviceTest : public SimpleDeviceWindow  
{
public:
	DeviceTest();
	virtual ~DeviceTest();

	virtual void Init3D();
	virtual void Render(double elapsed);
	virtual void Dispose();
	void init_light();

};

#endif // !defined(AFX_DEVICETEST_H__D2C9A3B9_9301_4BAD_953E_743F12DC9970__INCLUDED_)
