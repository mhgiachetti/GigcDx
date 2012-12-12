// TgcD3dInput.cpp: implementation of the TgcD3dInput class.
//
//////////////////////////////////////////////////////////////////////

#include "TgcD3dInput.h"
#include "GuiController.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TgcD3dInput::~TgcD3dInput()
{

}

TgcD3dInput::TgcD3dInput()
{
	
}

TgcD3dInput::TgcD3dInput( HWND guiControl, HWND panel3d )
{
	this->guiControl = guiControl;
	this->panel3d = panel3d;
	
	//keyboard
	keyboardDevice = DirectInput::Device(/*SystemGuid::Keyboard*/ GUID_SysKeyboard);
	keyboardDevice.SetCooperativeLevel(guiControl, CooperativeLevelFlags_Background | CooperativeLevelFlags_NonExclusive);
	keyboardDevice.Acquire();
	
	//mouse
	mouseDevice = DirectInput::Device(/*SystemGuid::Mouse*/ GUID_SysMouse);
	mouseDevice.SetCooperativeLevel(guiControl, CooperativeLevelFlags_Background | CooperativeLevelFlags_NonExclusive);
	mouseDevice.Acquire();
	mouseIndex = 0;
	enableMouseFiltering = true;
	weightModifier = WEIGHT_MODIFIER;
	mouseX = 0;
	mouseY = 0;
	
	//Inicializar mouseMovement
	//mouseMovement = new Vector2[2];
	//for (int i = 0; i < mouseMovement.Length; i++)
	//{
	//    mouseMovement[i] = new Vector2(0.0f, 0.0f);
	//}
	
	//Inicializar historyBuffer
	//historyBuffer = new Vector2[HISTORY_BUFFER_SIZE];
	//for (int i = 0; i < historyBuffer.Length; i++)
	//{
	//    historyBuffer[i] = new Vector2(0.0f, 0.0f);
	//}
	
	//Inicializar ubicacion del cursor
	//Point ceroToScreen = this.panel3d.PointToScreen(ceroPoint);
	//Cursor.Position = new Point(ceroToScreen.X + panel3d.Width / 2, ceroToScreen.Y + panel3d.Height / 2);
	//mouseInside = checkMouseInsidePanel3d();
	
	
	//Inicializar estados de teclas
	//int[] keysArray = (int[])Enum.GetValues(typeof(Key));
	//int maxKeyValue = keysArray[keysArray.Length - 1];
	ZeroMemory(&previouskeyboardState,sizeof(previouskeyboardState));
	ZeroMemory(&currentkeyboardState,sizeof(currentkeyboardState));
	//for (int i = 0; i < maxKeyValue; i++)
	//{
	//    previouskeyboardState[i] = false;
	//    currentkeyboardState[i] = false;
	//}
	
	//Inicializar estados de botones del mouse
	ZeroMemory(&previousMouseButtonsState,sizeof(previousMouseButtonsState));
	ZeroMemory(&currentMouseButtonsState,sizeof(currentMouseButtonsState));
	//for (int i = 0; i < previousMouseButtonsState.Length; i++)
	//{
	//    previousMouseButtonsState[i] = false;
	//    currentMouseButtonsState[i] = false;
	//}
}



void TgcD3dInput::destroy()
{
	keyboardDevice.Unacquire();
	keyboardDevice.Dispose();
	
	mouseDevice.Unacquire();
	mouseDevice.Dispose();
}

void TgcD3dInput::update()
{
	//Ver si el cursor esta dentro del panel3d
	bool currentInside = checkMouseInsidePanel3d();
	
	//Si esta afuera y antes estaba adentro significa que salio. No capturar ningun evento, fuera de jurisdiccion
	if (mouseInside && !currentInside)
	{
		mouseInside = false;
	}
	
	//Ahora esta adentro, capturar eventos
	else if (currentInside)
	{
		//Estaba afuera y ahora esta adentro, hacer foco en panel3d para perder foco de algun control exterior
		if (!mouseInside)
		{
			//panel3d.Focus();
			SetFocus(panel3d);
		}
		
		mouseInside = true;
		
		updateKeyboard();
		updateMouse();
		
		//Terminar ejemplo
		if (keyPressed(Key_Escape))
		{
			GuiController::Instance.stopCurrentExample();
		}
	}
}

bool TgcD3dInput::checkMouseInsidePanel3d()
{
	//Obtener mouse X, Y absolute
	/*Point ceroToScreen = this.panel3d.PointToScreen(ceroPoint);
	mouseX = Cursor.Position.X - ceroToScreen.X;
	mouseY = Cursor.Position.Y - ceroToScreen.Y;
	
	  //Ver si el cursor esta dentro del panel3d
	return panel3d.ClientRectangle.Contains(mouseX, mouseY);*/
	//TODO:
	return true;
}

void TgcD3dInput::updateKeyboard()
{
	previouskeyboardState = currentkeyboardState;
	currentkeyboardState = keyboardDevice.GetCurrentKeyboardState();
	
	//Hacer copia del estado actual
	//Array.Copy(currentkeyboardState, previouskeyboardState, currentkeyboardState.Length);
	
	//Actualizar cada tecla del estado actual
	/*for (int i = 0; i < currentkeyboardState.Length; i++)
	{
	Key k = (Key)(i+1);
	currentkeyboardState[i] = state[k];
}*/
}

void TgcD3dInput::updateMouse()
{
	DirectInput::MouseState &mouseState = mouseDevice.CurrentMouseState;
	memcpy(previousMouseButtonsState,currentMouseButtonsState,sizeof(currentMouseButtonsState));
	memcpy(currentMouseButtonsState,mouseState.GetMouseButtons(),sizeof(currentMouseButtonsState));
	
	//Hacer copia del estado actual
	//Array.Copy(currentMouseButtonsState, previousMouseButtonsState, currentMouseButtonsState.Length);
	
	//Actualizar estado de cada boton
	//byte[] mouseStateButtons = mouseState.GetMouseButtons();
	//currentMouseButtonsState[(int)MouseButtons.BUTTON_LEFT] = mouseStateButtons[(int)MouseButtons.BUTTON_LEFT] != 0;
	//currentMouseButtonsState[(int)MouseButtons.BUTTON_MIDDLE] = mouseStateButtons[(int)MouseButtons.BUTTON_MIDDLE] != 0;
	//currentMouseButtonsState[(int)MouseButtons.BUTTON_RIGHT] = mouseStateButtons[(int)MouseButtons.BUTTON_RIGHT] != 0;
	
	
	//Mouse X, Y relative
	if (enableMouseFiltering)
	{
		performMouseFiltering(mouseState.X, mouseState.Y);
		performMouseSmoothing(deltaMouseX, deltaMouseY);
	}
	else
	{
		deltaMouseX = mouseState.X;
		deltaMouseY = mouseState.Y;
	}
	
	
	//Mouse Wheel
	if (mouseState.Z > 0)
	{
		deltaMouseWheel = 1.0f;
	}
	else if (mouseState.Z < 0)
	{
		deltaMouseWheel = -1.0f;
	}
	else
	{
		deltaMouseWheel = 0.0f;
	}
}

void TgcD3dInput::performMouseFiltering( int x, int y )
{
	for (int i = HISTORY_BUFFER_SIZE - 1; i > 0; --i)
	{
		historyBuffer[i].X = historyBuffer[i - 1].X;
		historyBuffer[i].Y = historyBuffer[i - 1].Y;
	}
	
	historyBuffer[0].X = x;
	historyBuffer[0].Y = y;
	
	float averageX = 0.0f;
	float averageY = 0.0f;
	float averageTotal = 0.0f;
	float currentWeight = 1.0f;
	
	for (i = 0; i < HISTORY_BUFFER_SIZE; i++)
	{
		averageX += historyBuffer[i].X * currentWeight;
		averageY += historyBuffer[i].Y * currentWeight;
		averageTotal += 1.0f * currentWeight;
		currentWeight *= weightModifier;
	}
	
	deltaMouseX = averageX / averageTotal;
	deltaMouseY = averageY / averageTotal;
}

void TgcD3dInput::performMouseSmoothing( float x, float y )
{
	mouseMovement[mouseIndex].X = x;
	mouseMovement[mouseIndex].Y = y;
	
	deltaMouseX = (mouseMovement[0].X + mouseMovement[1].X) * 0.05f;
	deltaMouseY = (mouseMovement[0].Y + mouseMovement[1].Y) * 0.05f;
	
	mouseIndex ^= 1;
	mouseMovement[mouseIndex].X = 0.0f;
	mouseMovement[mouseIndex].Y = 0.0f;
}

bool TgcD3dInput::keyDown( Key key )
{
	if (!mouseInside) return false;
	
	int k = (int)key - 1;
	return currentkeyboardState[k];
}

bool TgcD3dInput::keyUp( Key key )
{
	if (!mouseInside) return false;
	
	int k = (int)key - 1;
	return previouskeyboardState[k] && !currentkeyboardState[k];
}

bool TgcD3dInput::keyPressed( Key key )
{
	if (!mouseInside) return false;
	
	int k = (int)key - 1;
	return !previouskeyboardState[k] && currentkeyboardState[k];
}

bool TgcD3dInput::buttonDown( MouseButtons button )
{
	if (!mouseInside) return false;
	
	return currentMouseButtonsState[(int)button];
}

bool TgcD3dInput::buttonUp( MouseButtons button )
{
	if (!mouseInside) return false;
	
	int b = (int)button;
	return previousMouseButtonsState[b] && !currentMouseButtonsState[b];
}

bool TgcD3dInput::buttonPressed( MouseButtons button )
{
	if (!mouseInside) return false;
	
	int b = (int)button;
	return !previousMouseButtonsState[b] && currentMouseButtonsState[b];
}
