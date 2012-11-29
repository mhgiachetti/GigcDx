// Effect.cpp: implementation of the Effect class.
//
//////////////////////////////////////////////////////////////////////

#include "Effect.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Effect::Effect()
{

}

Effect::Effect( LPD3DXEFFECT effect )
{
	SetEffect(effect);
}

Effect::~Effect()
{

}

Effect Effect::FromFile( LPD3DDEVICE device,const char * srcFile,ShaderFlags flags, string &outCompilationErrors )
{
	Effect effect;
	LPD3DXBUFFER errors;

	D3DXCreateEffectFromFile(device, srcFile, NULL, NULL, flags, NULL, effect,&errors);

	if(errors != NULL)
		outCompilationErrors = (char *)errors->GetBufferPointer();
	else
		outCompilationErrors = "";
	return effect;
}

Effect::operator LPD3DXEFFECT() const
{
	return m_effect;
}

Effect::operator LPD3DXEFFECT*() const
{
	return (LPD3DXEFFECT *)&m_effect;
}

void Effect::Release()
{
	m_effect->Release();
}

void Effect::SetEffect( LPD3DXEFFECT effect )
{
	m_effect = effect;
}

void Effect::SetTechnique( const char * technique )
{
	m_effect->SetTechnique(technique);
}

int Effect::Begin( FX flags )
{
	UINT passes;
	m_effect->Begin(&passes,flags);
	return passes;
}

void Effect::End()
{
	m_effect->End();
}

void Effect::BeginPass( int passNumber )
{
	m_effect->BeginPass(passNumber);
}

void Effect::EndPass()
{
	m_effect->EndPass();
}

void Effect::SetValue( const char * parameter, const Matrix &matrix )
{
	//el shader necesita las matrices transpuestas
	HRESULT res = m_effect->SetMatrix(parameter, Matrix::STranspose(matrix));
	SUCCEEDED(res);
}

void Effect::SetValue( const char * parameter, const Texture &texture )
{
	HRESULT res = m_effect->SetTexture(parameter, texture);
	SUCCEEDED(res);
}

void Effect::SetValue( const char * parameter, int value )
{
	m_effect->SetInt(parameter, value);
}

void Effect::SetValue( const char * parameter, float value )
{
	m_effect->SetFloat(parameter, value);
}

void Effect::SetValue( const char * parameter, bool value )
{
	m_effect->SetBool(parameter, value);
}

