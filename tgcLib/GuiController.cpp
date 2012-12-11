// GuiController.cpp: implementation of the GuiController class.
//
//////////////////////////////////////////////////////////////////////

#include "GuiController.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GuiController GuiController::Instance;

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

Device GuiController::GetD3dDevice()
{
	return m_device;
}

void GuiController::stopCurrentExample()
{
	
}
