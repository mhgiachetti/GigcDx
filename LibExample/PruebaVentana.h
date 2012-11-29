// PruebaVentana.h: interface for the PruebaVentana class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRUEBAVENTANA_H__6EC2E44E_CCA8_4E42_A6E8_09EA93D2D41E__INCLUDED_)
#define AFX_PRUEBAVENTANA_H__6EC2E44E_CCA8_4E42_A6E8_09EA93D2D41E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "..\dxLib\SimpleDeviceWindow.h"

class PruebaVentana : public SimpleDeviceWindow 
{
public:
	PruebaVentana(HINSTANCE hInstance);
	virtual ~PruebaVentana();

	virtual void Init3D();
	virtual void Render(double elapsed);
	virtual void Dispose();
	void init_light();
};

#endif // !defined(AFX_PRUEBAVENTANA_H__6EC2E44E_CCA8_4E42_A6E8_09EA93D2D41E__INCLUDED_)
