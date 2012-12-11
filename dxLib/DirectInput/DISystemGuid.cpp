// DISystemGuid.cpp: implementation of the SystemGuid class.
//
//////////////////////////////////////////////////////////////////////

#include "DISystemGuid.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace DirectInput;

SystemGuid::SystemGuid()
{

}

SystemGuid::~SystemGuid()
{

}

const Guid SystemGuid::Mouse = GUID_SysMouse;
const Guid SystemGuid::Keyboard = GUID_SysKeyboard;
