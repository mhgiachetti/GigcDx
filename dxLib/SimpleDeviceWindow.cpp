// SimpleDeviceWindow.cpp: implementation of the SimpleDeviceWindow class.
//
//////////////////////////////////////////////////////////////////////

#include "SimpleDeviceWindow.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LRESULT CALLBACK __DefaultWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


SimpleDeviceWindow::SimpleDeviceWindow(HINSTANCE hInstance, int width /*= 800*/, int height /*= 600*/, bool fullscreen /*= false*/ )
{
	m_hInstance = hInstance;
	DefaultParameters(width,height,fullscreen);
}

SimpleDeviceWindow::~SimpleDeviceWindow()
{

}

void SimpleDeviceWindow::DefaultParameters( int width /*= 800*/, int height /*= 600*/, bool fullscreen /*= false*/ )
{
	m_exit = false;
	m_hWnd = NULL;
	ZeroMemory(&m_wndclassex, sizeof(m_wndclassex));
	ZeroMemory(&m_present_parameters,sizeof(m_present_parameters));
	m_d3d = NULL;
	m_SDKVersion = D3D_SDK_VERSION;
	m_d3ddevice_type = D3DDEVTYPE_HAL;
	m_behavior_flags = D3DCREATE_HARDWARE_VERTEXPROCESSING;

	m_present_parameters.Windowed = !fullscreen;//d3dpp.Windowed = TRUE;
	m_present_parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_present_parameters.hDeviceWindow = NULL;
	m_present_parameters.BackBufferFormat = D3DFMT_X8R8G8B8;
	m_present_parameters.BackBufferWidth = width;
	m_present_parameters.BackBufferHeight = height;
	m_present_parameters.EnableAutoDepthStencil = TRUE;
	m_present_parameters.AutoDepthStencilFormat = D3DFMT_D24S8;

	m_wndclassex.cbSize = sizeof(WNDCLASSEX);
    m_wndclassex.style = CS_HREDRAW | CS_VREDRAW;
    m_wndclassex.lpfnWndProc = __DefaultWindowProc;
    m_wndclassex.hInstance = m_hInstance;
    m_wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
    m_wndclassex.hbrBackground = (HBRUSH)COLOR_WINDOW;
    m_wndclassex.lpszClassName = "WindowClass1";

	m_window_style = fullscreen?WS_EX_TOPMOST | WS_POPUP:WS_OVERLAPPEDWINDOW;
	m_window_pos_x = fullscreen?0 : 0;
	m_window_pos_y = fullscreen?0 : 0;
}

void SimpleDeviceWindow::Play()
{
	CreateNativeWindow();
	CreateInterface();
	CreateDevice();
	Init3D();
	m_timer.Reset();	
	while(!m_exit)
	{
		m_timer.Set();
		MessageLoop();
		Render(m_timer.m_elapsed);
	}
	Dispose();
}

void SimpleDeviceWindow::CreateNativeWindow()
{
	m_aspect_ratio = (float)m_present_parameters.BackBufferWidth/(float)m_present_parameters.BackBufferHeight;
	if(m_hInstance == NULL)
		//el hwnd se setea a mano
		return;
	RegisterClassEx(&m_wndclassex);

	m_hWnd = CreateWindowEx(NULL,
		"WindowClass1",
		"LibExample",
		m_window_style,
		m_window_pos_x,
		m_window_pos_y,
		m_present_parameters.BackBufferWidth,
		m_present_parameters.BackBufferHeight,
		NULL,
		NULL,
		m_hInstance,
		NULL);

	ShowWindow(m_hWnd, SW_SHOWDEFAULT );
	
}

void SimpleDeviceWindow::CreateInterface()
{
	m_d3d = Direct3DCreate(m_SDKVersion);
}

void SimpleDeviceWindow::CreateDevice()
{
	m_present_parameters.hDeviceWindow = m_hWnd;

	LPD3DDEVICE device;

	m_d3d->CreateDevice(D3DADAPTER_DEFAULT,
		m_d3ddevice_type,
		m_hWnd,
		m_behavior_flags,
		&m_present_parameters,
		&device);

	m_d3ddevice.SetDevice(device);

	m_d3ddevice.SetSamplerState( 0, SamplerStageStates_MinFilter, TextureFilter_Anisotropic );
	m_d3ddevice.SetSamplerState( 0, SamplerStageStates_MagFilter, TextureFilter_Anisotropic );
	m_d3ddevice.SetSamplerState( 0, SamplerStageStates_MipFilter, TextureFilter_Anisotropic );
}

void SimpleDeviceWindow::MessageLoop()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		
		DispatchMessage(&msg);
	}
	if (msg.message == WM_QUIT)
		m_exit = true;
}

void SimpleDeviceWindow::Init3D()
{
	
}

void SimpleDeviceWindow::Render( double elapsed )
{
	//esta funcion debe ser sobrecargada con lo necesario
	m_d3ddevice.Clear(ClearFlags_Target, D3DCOLOR_XRGB(0,40,100), 1.0,0);
	m_d3ddevice.BeginScene();

	m_d3ddevice.EndScene();

	m_d3ddevice.Present();
}



void SimpleDeviceWindow::Dispose()
{
	m_d3ddevice.Dispose();
	m_d3d->Release();
}


LRESULT CALLBACK __DefaultWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}break;
	}
	
	return DefWindowProc(hWnd,message,wParam,lParam);
	
}

