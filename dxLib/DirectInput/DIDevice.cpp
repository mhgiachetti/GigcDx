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

}

Device::~Device()
{

}


Device::Device( LPDINPUTDEVICE device )
{
	m_device = device;
}

Device::Device( Guid deviceGuid )
{
	DirectInputCreate(NULL,DIRECTINPUT_VERSION,IID_IDirectInput8, (void**)&m_dinput,NULL);
	m_dinput->CreateDevice(deviceGuid,&m_device,NULL);
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
	m_device->GetDeviceState(sizeof(KeyboardState),m_keyboardstate);
	return m_keyboardstate;
}

MouseState & DirectInput::Device::GetCurrentMouseState()
{
	m_device->GetDeviceState(sizeof(MouseState),m_mousestate);
	return m_mousestate;
}
