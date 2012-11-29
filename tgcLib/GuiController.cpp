// GuiController.cpp: implementation of the GuiController class.
//
//////////////////////////////////////////////////////////////////////

#include "GuiController.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GuiController::GuiController()
{

}

GuiController::~GuiController()
{

}

/// <summary>
/// Crear nueva instancia. Solo el MainForm lo hace
/// </summary>
void GuiController::newInstance()
{
	Instance = GuiController();
}

Device GuiController::D3dDevice()
{
	return Device();
}
