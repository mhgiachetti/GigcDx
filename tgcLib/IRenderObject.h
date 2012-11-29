// IRenderObject.h: interface for the IRenderObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IRENDEROBJECT_H__1A9DCCF8_74E9_4ACB_B68D_127F9B95254F__INCLUDED_)
#define AFX_IRENDEROBJECT_H__1A9DCCF8_74E9_4ACB_B68D_127F9B95254F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IRenderObject  
{
public:
	/// <summary>
	/// Renderiza el objeto
	/// </summary>
	virtual void render() = 0;
	
	/// <summary>
	/// Libera los recursos del objeto
	/// </summary>
	virtual void dispose() = 0;
	
	/// <summary>
	/// Habilita el renderizado con AlphaBlending para los modelos
	/// con textura o colores por vértice de canal Alpha.
	/// Por default está deshabilitado.
	/// </summary>
	virtual bool GetAlphaBlendEnable() = 0;
	virtual void SetAlphaBlendEnable(bool enable) = 0;
};

#endif // !defined(AFX_IRENDEROBJECT_H__1A9DCCF8_74E9_4ACB_B68D_127F9B95254F__INCLUDED_)
