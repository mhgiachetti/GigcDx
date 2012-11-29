// SimpleDeviceWindow.h: interface for the SimpleDeviceWindow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMPLEDEVICEWINDOW_H__25891924_99DB_4942_A8A3_50A0845271E8__INCLUDED_)
#define AFX_SIMPLEDEVICEWINDOW_H__25891924_99DB_4942_A8A3_50A0845271E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#include "Device.h"
#include "HighTimer.h"

class SimpleDeviceWindow  
{

	//atributos
public:
	HWND m_hWnd;
	WNDCLASSEX m_wndclassex;
	Device m_d3ddevice;
	D3DPRESENT_PARAMETERS m_present_parameters;
	LPD3D m_d3d;
	int m_SDKVersion;
	D3DDEVTYPE m_d3ddevice_type;
	DWORD m_behavior_flags;
	bool m_exit;
	DWORD m_window_style;
	int m_window_pos_x;
	int m_window_pos_y;
	HINSTANCE m_hInstance;
	HighTimer m_timer;
	float m_aspect_ratio;


public:
	SimpleDeviceWindow(HINSTANCE hinstance, int width = 800, int height = 600, bool fullscreen = false);
	virtual ~SimpleDeviceWindow();

	virtual void DefaultParameters(int width = 800, int height = 600, bool fullscreen = false);
	virtual void Play();
	virtual void CreateNativeWindow();
	virtual void CreateInterface();
	virtual void CreateDevice();
	virtual void Init3D();
	virtual void MessageLoop();
	virtual void Render(double elapsed);
	virtual void Dispose();

};

#endif // !defined(AFX_SIMPLEDEVICEWINDOW_H__25891924_99DB_4942_A8A3_50A0845271E8__INCLUDED_)
