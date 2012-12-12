// TgcD3dInput.h: interface for the TgcD3dInput class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGCD3DINPUT_H__EB9FDD2F_5EFC_431B_BB81_1444C174E282__INCLUDED_)
#define AFX_TGCD3DINPUT_H__EB9FDD2F_5EFC_431B_BB81_1444C174E282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../dxLib/dxLib.h"

/// <summary>
/// Botones del mouse para DirectInput
/// </summary>
enum MouseButtons
{
	MouseButtons_BUTTON_LEFT   = 0,
    MouseButtons_BUTTON_RIGHT  = 1,
    MouseButtons_BUTTON_MIDDLE = 2,
};

#define HISTORY_BUFFER_SIZE		10
#define WEIGHT_MODIFIER			0.2f

class TgcD3dInput  
{
public:
	TgcD3dInput();
	virtual ~TgcD3dInput();

    HWND guiControl;
    HWND panel3d;
    
    //Keyboard
	DirectInput::Device keyboardDevice;
    DirectInput::KeyboardState previouskeyboardState;
    DirectInput::KeyboardState currentkeyboardState;

    //Mouse
    DirectInput::Device mouseDevice;
    bool previousMouseButtonsState[3];
    bool currentMouseButtonsState[3];
    float deltaMouseX;
    float deltaMouseY;
    float deltaMouseWheel;
    int mouseX;
    int mouseY;
    Vector2 mouseMovement[2];
    int mouseIndex;
    Vector2 historyBuffer[HISTORY_BUFFER_SIZE];
    
    const WPoint ceroPoint;
    bool mouseInside;


    bool enableMouseFiltering;
	/// <summary>
    /// Habilitar Mouse Smooth
    /// </summary>
    PROPERTYSIMPLGETSET(bool,EnableMouseSmooth,enableMouseFiltering);

    float weightModifier;
    /// <summary>
    /// Influencia para filtrar el movimiento del mouse
    /// </summary>
    PROPERTYSIMPLGETSET(float,WeightModifier,weightModifier);

    /// <summary>
    /// Desplazamiento relativo de X del mouse
    /// </summary>
    PROPERTYSIMPLGET(float,XposRelative,deltaMouseX);

    /// <summary>
    /// Desplazamiento relativo de Y del mouse
    /// </summary>
    PROPERTYSIMPLGET(float,YposRelative,deltaMouseY);

    /// <summary>
    /// Posicion absoluta de X del mouse
    /// </summary>
    PROPERTYSIMPLGET(float,Xpos,mouseX);

    /// <summary>
    /// Posicion absoluta de Y del mouse
    /// </summary>
    PROPERTYSIMPLGET(float,Ypos,mouseY);

    /// <summary>
    /// Rueda del Mouse
    /// </summary>
    PROPERTYSIMPLGET(float,WheelPos,deltaMouseWheel);


    TgcD3dInput(HWND guiControl, HWND panel3d);


    void destroy();

    void update();

    bool checkMouseInsidePanel3d();


    void updateKeyboard();

    void updateMouse();

    /// <summary>
    /// Filter the relative mouse movement based on a weighted sum of the mouse
    /// movement from previous frames to ensure that the mouse movement this
    /// frame is smooth. 
    /// </summary>
    void performMouseFiltering(int x, int y);

    /// <summary>
    /// Average the mouse movement across a couple of frames to smooth out mouse movement.
    /// </summary>
    void performMouseSmoothing(float x, float y);

    
    /// <summary>
    /// Informa si una tecla se encuentra presionada
    /// </summary>
    bool keyDown(Key key);

    /// <summary>
    /// Informa si una tecla se dejo de presionar
    /// </summary>
    bool keyUp(Key key);


    /// <summary>
    /// Informa si una tecla se presiono y luego se libero
    /// </summary>
    bool keyPressed(Key key);

    /// <summary>
    /// Informa si un boton del mouse se encuentra presionado
    /// </summary>
    bool buttonDown(MouseButtons button);

    /// <summary>
    /// Informa si un boton del mouse se dejo de presionar
    /// </summary>
    bool buttonUp(MouseButtons button);

    /// <summary>
    /// Informa si un boton del mouse se presiono y luego se libero
    /// </summary>
    bool buttonPressed(MouseButtons button);


};

#endif // !defined(AFX_TGCD3DINPUT_H__EB9FDD2F_5EFC_431B_BB81_1444C174E282__INCLUDED_)
