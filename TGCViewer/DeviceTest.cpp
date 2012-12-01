// DeviceTest.cpp: implementation of the DeviceTest class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TGCViewer.h"
#include "DeviceTest.h"
#include "..\tgcLib\TGCSimpleTerrain.h"
#include "..\tgcLib\GuiController.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
XMesh mesh;
Effect effect;
TgcSimpleTerrain terrain;
Font font;

DeviceTest::DeviceTest():SimpleDeviceWindow(NULL)
{
	
}

DeviceTest::~DeviceTest()
{

}

void DeviceTest::Init3D()
{
	GuiController::newInstance();
	GuiController::Instance.m_device = m_d3ddevice;

	mesh = MeshLoader::LoadFromX(m_d3ddevice, "media\\x\\tiger.x");

	string errors;
	effect = Effect::FromFile(m_d3ddevice,"media\\shaders\\prueba.fx", ShaderFlags_None, errors);

	if(!errors.empty())
	{
		MessageBox(NULL,errors.c_str(),"",0);
	}

	terrain.loadHeightmap("media\\terrain\\heightmap.jpg",1,0.1f,Vector3(0,-150,0));
	terrain.loadTexture("media\\terrain\\mapa.jpg");
	terrain.SetEnabled(true);

	FontDescription d;
	d.Height = 15;
	d.Width = 0;
	d.Weight = FontWeight_Normal;
	d.MipLevels = 1;
	d.IsItalic = false;
	d.SetCharSet(CharacterSet_Default);
	d.SetFaceName("Times New Roman");
	font = Font(m_d3ddevice,d);

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

void DeviceTest::Render( double elapsed )
{
	m_d3ddevice.Clear(ClearFlags_Target |ClearFlags_ZBuffer, D3DCOLOR_XRGB(0,40,100),1.0f,0);
	m_d3ddevice.BeginScene();

	static float index = 0;
	index += 0.50f*elapsed;

	Matrix matView;
	Vector3 cameraPos = Vector3::TransformCoordinate(Vector3(12.0f, 7.0f, 12.0f), Matrix::SRotationYawPitchRoll(0,0,index));
	matView.LookAtLH(cameraPos,Vector3(0.0f,0.0f,0.0f),	Vector3(0.0f,1.0f,0.0f));

	m_d3ddevice.Transform.View(matView);

	Matrix matProjection;
	matProjection.PerspectiveFovLH(	D3DXToRadian(45),m_aspect_ratio,1.0f,10000.0f);
	m_d3ddevice.Transform.Projection(matProjection);

	Matrix matTranslate; 
    matTranslate.RotationY(index);
	matTranslate.Identity();
	mesh.SetTransform(matTranslate);
	m_d3ddevice.Transform.World(matTranslate);

	effect.SetTechnique("Default");
	//effect.SetValue("matWorldViewProj",matTranslate*matView*matProjection);

	//effect.SetValue("base_Tex",mesh.m_textures[0]);
	

	//effect.Begin(FX_None);
	//effect.BeginPass(0);

	mesh.Render();
	terrain.render();

	char fpsText[100];

	sprintf(fpsText,"FPS:%d",m_timer.m_fps);

	font.DrawText(NULL,fpsText,WRectangle(0,00,100,100),DrawTextFormat_NoClip,0xff000000);
	

	//effect.EndPass();
	//effect.End();


	m_d3ddevice.EndScene();
	m_d3ddevice.Present();
}

void DeviceTest::Dispose()
{
	mesh.Dispose();
	SimpleDeviceWindow::Dispose();
}

void DeviceTest::init_light()
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

void DeviceTest::MessageLoop()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		
		
		if (!m_accel || !TranslateAccelerator(AfxGetMainWnd()->m_hWnd, m_accel, &msg))
			DispatchMessage(&msg);
	}	
	if (msg.message == WM_QUIT)
		m_exit = true;
}

