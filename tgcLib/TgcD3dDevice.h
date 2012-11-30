// TgcD3dDevice.h: interface for the TgcD3dDevice class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGCD3DDEVICE_H__19C4E428_AAF1_46BD_A6C8_195FF4380149__INCLUDED_)
#define AFX_TGCD3DDEVICE_H__19C4E428_AAF1_46BD_A6C8_195FF4380149__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../dxLib/dxLib.h"

class TgcD3dDevice  
{
public:
	Device D3dDevice;
	HWND panel3d;
	static const int DEFAULT_CLEAR_COLOR;
	static const Material DEFAULT_MATERIAL;
	static const int DIRECTX_MULTITEXTURE_COUNT;
	//Valores de configuracion de la matriz de Proyeccion
	static float fieldOfViewY;
	static float aspectRatio;
	static float zNearPlaneDistance;
	static float zFarPlaneDistance;
	
	virtual ~TgcD3dDevice();
	

	/// <summary>
	/// Color con el que se limpia la pantalla
	/// </summary>
	int ClearColor;
	
	TgcD3dDevice(HWND panel3d);

	/// <summary>
	/// This event-handler is a good place to create and initialize any 
	/// Direct3D related objects, which may become invalid during a 
	/// device reset.
	/// </summary>
	//void OnResetDevice(object sender, EventArgs e)
	//{
		//GuiController::Instance.onResetDevice();
	//}

	/// <summary>
	/// Hace las operaciones de Reset del device
	/// </summary>
	void doResetDevice();

	/// <summary>
	/// Valores default del Direct3d Device
	/// </summary>
	void setDefaultValues();

	void doClear();

	void resetWorldTransofrm();

	/// <summary>
	/// Liberar Device al finalizar la aplicacion
	/// </summary>
	void shutDown();
};

#endif // !defined(AFX_TGCD3DDEVICE_H__19C4E428_AAF1_46BD_A6C8_195FF4380149__INCLUDED_)
