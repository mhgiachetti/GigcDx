// PruebaVentana.cpp: implementation of the PruebaVentana class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PruebaVentana.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMesh mesh;
Effect effect;

PruebaVentana::PruebaVentana( HINSTANCE hInstance ):SimpleDeviceWindow(hInstance)
{
	
}

PruebaVentana::~PruebaVentana()
{

}

void PruebaVentana::Init3D()
{
	mesh = MeshLoader::LoadFromX(m_d3ddevice, "media\\x\\tiger.x");

	string errors;
	effect = Effect::FromFile(m_d3ddevice,"media\\shaders\\prueba.fx", ShaderFlags_None, errors);

	if(!errors.empty())
	{
		MessageBox(NULL,errors.c_str(),"",0);
	}

	init_light();

	m_d3ddevice.RenderState.SetLighting(false);
	m_d3ddevice.RenderState.SetCullMode(Cull_None);
	m_d3ddevice.RenderState.SetZBufferEnable(true);
	m_d3ddevice.RenderState.SetAmbient(D3DCOLOR_XRGB(50,50,50));
	m_d3ddevice.RenderState.SetNormalizeNormals(true);
	m_d3ddevice.RenderState.SetAlphaBlendEnable(true);
	m_d3ddevice.RenderState.SetBlendOperation(BlendOperation_Add);
	m_d3ddevice.RenderState.SetSourceBlend(Blend_SourceAlpha);
	m_d3ddevice.RenderState.SetDestinationBlend(Blend_InvSourceAlpha);
	m_d3ddevice.RenderState.SetFillMode(FillMode_Solid);

}

void PruebaVentana::Render( double elapsed )
{
	m_d3ddevice.Clear(ClearFlags_Target |ClearFlags_ZBuffer, D3DCOLOR_XRGB(0,40,100),1.0f,0);
	m_d3ddevice.BeginScene();

	static float index = 0;
	index += 0.03f;

	Matrix matView;
	matView.LookAtLH(Vector3(3.0f, 1.0f, 3.0f),Vector3(0.0f,0.0f,0.0f),	Vector3(0.0f,1.0f,0.0f));

	m_d3ddevice.Transform.View(matView);

	Matrix matProjection;
	matProjection.PerspectiveFovLH(	D3DXToRadian(45),m_aspect_ratio,1.0f,100.0f);
	m_d3ddevice.Transform.Projection(matProjection);

	Matrix matTranslate; 
    matTranslate.RotationY(index);
	mesh.SetTransform(matTranslate);
	m_d3ddevice.Transform.World(matTranslate);

	effect.SetTechnique("Default");
	effect.SetValue("matWorldViewProj",matTranslate*matView*matProjection);

	effect.SetValue("base_Tex",mesh.m_textures[0]);

	effect.Begin(FX_None);
	effect.BeginPass(0);

	mesh.Render();


	effect.EndPass();
	effect.End();


	m_d3ddevice.EndScene();
	m_d3ddevice.Present();
}

void PruebaVentana::Dispose()
{
	mesh.Dispose();
	SimpleDeviceWindow::Dispose();
}

void PruebaVentana::init_light()
{
	Light light;
	Material material;

	light.Type = LightType_Spot;
	light.Diffuse = ColorValue(0.5f, 0.5f, 0.5f, 1.0f);
	light.Direction = Vector3(0.0f, 0.0f, -1.0f);
	light.Position = Vector3(-12.0f, 0.0f, 30.0f);
    light.Range = 100.0f;  
    light.Attenuation0 = 0.0f;
    light.Attenuation1 = 0.125f;
    light.Attenuation2 = 0.0f;  
	light.Phi = D3DXToRadian(40.0f);
    light.Theta = D3DXToRadian(20.0f);
    light.Falloff = 1.0f;  

	m_d3ddevice.SetLight(0,light);
	m_d3ddevice.LightEnable(0,true);

	material.Diffuse = ColorValue(1.0f,1.0f,1.0f,1.0f);
	material.Ambient = ColorValue(1.0f,1.0f,1.0f,1.0f);

	m_d3ddevice.SetMaterial(material);

}
