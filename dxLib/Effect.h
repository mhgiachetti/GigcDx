// Effect.h: interface for the Effect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGEFFECT_H__746B4065_1902_4F58_AE9E_8E1666E64755__INCLUDED_)
#define AFX_MGEFFECT_H__746B4065_1902_4F58_AE9E_8E1666E64755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
#include <string>
#include "Matrix.h"
#include "Texture.h"
using namespace std;

class Effect  
{
public:
	LPD3DXEFFECT m_effect;

	static Effect FromFile(LPD3DDEVICE device,const char * srcFile, ShaderFlags flags, string &outCompilationErrors);

public:
	Effect();
	Effect(LPD3DXEFFECT effect);
	virtual ~Effect();

	void Release();
	void SetEffect(LPD3DXEFFECT effect);
	void SetTechnique(const char * technique);
	int Begin(FX flags);
	void End();
	void BeginPass(int passNumber);
	void EndPass();

	void SetValue(const char * parameter, const Matrix &matrix);
	void SetValue(const char * parameter, const Texture &texture);
	void SetValue(const char * parameter, int value);
	void SetValue(const char * parameter, float value);
	void SetValue(const char * parameter, bool value);

	operator LPD3DXEFFECT()const;
	operator LPD3DXEFFECT*()const;

};

#endif // !defined(AFX_MGEFFECT_H__746B4065_1902_4F58_AE9E_8E1666E64755__INCLUDED_)
