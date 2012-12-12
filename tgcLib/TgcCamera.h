// TgcCamera.h: interface for the TgcCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGCCAMERA_H__A1B943EF_6186_4E9D_99B5_1C01F55FEF09__INCLUDED_)
#define AFX_TGCCAMERA_H__A1B943EF_6186_4E9D_99B5_1C01F55FEF09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../dxLib/dxLib.h"


class TgcCamera  
{
public:
	/// <summary>
	/// Posición de la cámara
	/// </summary>
	Vector3 getPosition() = 0;
	
	/// <summary>
	/// Posición del punto al que mira la cámara
	/// </summary>
	Vector3 getLookAt() = 0;
	
	/// <summary>
	/// Actualizar el estado interno de la cámara en cada frame
	/// </summary>
	void updateCamera() = 0;
	
	/// <summary>
	/// Actualizar la matriz View en base a los valores de la cámara
	/// </summary>
    void updateViewMatrix(Device d3dDevice) = 0;

};

#endif // !defined(AFX_TGCCAMERA_H__A1B943EF_6186_4E9D_99B5_1C01F55FEF09__INCLUDED_)
