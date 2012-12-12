// DIDevice.cpp: implementation of the Device class.
//
//////////////////////////////////////////////////////////////////////

#include "DIDevice.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace DirectInput;

Device::Device()
{
	m_device = NULL;
	m_dinput = NULL;
	m_formatSeted=false;

}

Device::~Device()
{

}


Device::Device( LPDINPUTDEVICE device )
{
	m_device = device;
}

DirectInput::Device::Device( Guid deviceGuid )
{
	DirectInputCreate(GetModuleHandle(NULL),DIRECTINPUT_VERSION,IID_IDirectInput8, (void**)&m_dinput,NULL);
	m_dinput->CreateDevice(deviceGuid,&m_device,NULL);
	m_formatSeted = false;
}

void Device::SetCooperativeLevel( HWND hwnd, CooperativeLevelFlags flags )
{
	m_device->SetCooperativeLevel(hwnd,flags);
}

void DirectInput::Device::Acquire()
{
	m_device->Acquire();
}

void DirectInput::Device::Unacquire()
{
	m_device->Unacquire();
}


void DirectInput::Device::Dispose()
{
	m_device->Release();
}

DirectInput::KeyboardState& DirectInput::Device::GetCurrentKeyboardState()
{
	if(!m_formatSeted)
	{
		m_device->SetDataFormat(&c_dfDIKeyboard);
		Acquire();
		m_formatSeted = true;
	}
	
	m_device->GetDeviceState(256,m_keyboardstate);
	return m_keyboardstate;
}

MouseState & DirectInput::Device::GetCurrentMouseState()
{
	if(!m_formatSeted)
	{
		m_device->SetDataFormat(&c_dfDIMouse);
		Acquire();
		m_formatSeted = true;
	}
	m_device->GetDeviceState(sizeof(DirectInput::MouseState),m_mousestate);
	return m_mousestate;
}
