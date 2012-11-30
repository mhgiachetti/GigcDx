// TgcD3dDevice.cpp: implementation of the TgcD3dDevice class.
//
//////////////////////////////////////////////////////////////////////

#include "TgcD3dDevice.h"
#include <wtypes.h>
#include "HighResolutionTimer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


const Material TgcD3dDevice::DEFAULT_MATERIAL;
const int TgcD3dDevice::DEFAULT_CLEAR_COLOR = 0xFF4E81B3;
/// <summary>
/// Cantidad de texturas simultaneas soportadas por DirectX
/// </summary>
const int TgcD3dDevice::DIRECTX_MULTITEXTURE_COUNT = 8;
//Valores de configuracion de la matriz de Proyeccion
float TgcD3dDevice::fieldOfViewY = D3DXToRadian(45.0f);
float TgcD3dDevice::aspectRatio = -1;
float TgcD3dDevice::zNearPlaneDistance = 1;
float TgcD3dDevice::zFarPlaneDistance = 10000;


TgcD3dDevice::TgcD3dDevice( HWND panel3d )
{
	this->panel3d = panel3d;
	RECT winRect;
	GetWindowRect(panel3d,&winRect);
	aspectRatio = fabs((float)(winRect.right-winRect.left) / (winRect.bottom-winRect.top));
	
	Caps caps = Manager::GetDeviceCaps(0, DeviceType_Hardware);
	CreateFlags flags;
	
	//Console.WriteLine("Max primitive count:" + caps.MaxPrimitiveCount);
	
	if (caps.deviceCaps.SupportsHardwareTransformAndLight())
		flags = CreateFlags_HardwareVertexProcessing;
	else
		flags = CreateFlags_SoftwareVertexProcessing;
	
	PresentParameters d3dpp;;
	
	d3dpp.BackBufferFormat = Format_Unknown;
	d3dpp.swapEffect = SwapEffect_Discard;
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = DepthFormat_D24S8;
	d3dpp.PresentationInterval = PresentInterval_Immediate;
    
	//Antialiasing
	if (Manager::CheckDeviceMultiSampleType(0, DeviceType_Hardware,
		Manager::GetCurrentFormat(), true, MultiSampleType_NonMaskable))
	{
		d3dpp.MultiSample = MultiSampleType_NonMaskable;
		d3dpp.MultiSampleQuality = 0;
	}
	else
	{
		d3dpp.MultiSample = MultiSampleType_None;
	}
    
	
	//Crear Graphics Device
	//Device.IsUsingEventHandlers = false;
	D3dDevice = Device(0, DeviceType_Hardware, panel3d, flags, d3dpp);
	//d3dDevice.DeviceReset += new System.EventHandler(this.OnResetDevice);
}

TgcD3dDevice::~TgcD3dDevice()
{

}

void TgcD3dDevice::doResetDevice()
{
	setDefaultValues();
	
	//Reset Timer
	HighResolutionTimer::Instance.Reset();
}

void TgcD3dDevice::setDefaultValues()
{
	//Frustum values
	D3dDevice.Transform.Projection(	
		Matrix::SPerspectiveFovLH(D3DXToRadian(45.0f),
		aspectRatio, zNearPlaneDistance, zFarPlaneDistance));

	//Render state
	D3dDevice.RenderState.SetSpecularEnable(false);
	D3dDevice.RenderState.SetFillMode(FillMode_Solid);
	D3dDevice.RenderState.SetCullMode(Cull_None);
	D3dDevice.RenderState.SetShadeMode(ShadeMode_Gouraud);
	D3dDevice.RenderState.SetMultiSampleAntiAlias(true);
	D3dDevice.RenderState.SetSlopeScaleDepthBias(-0.1f);
	D3dDevice.RenderState.SetDepthBias(0);
	D3dDevice.RenderState.SetColorVertex(true);
	D3dDevice.RenderState.SetLighting(false);
	D3dDevice.RenderState.SetZBufferEnable(true);
	D3dDevice.RenderState.SetFogEnable(false);

	//Alpha Blending
	D3dDevice.RenderState.SetAlphaBlendEnable(false);
	D3dDevice.RenderState.SetAlphaTestEnable(false);
	D3dDevice.RenderState.SetReferenceAlpha(100);
	D3dDevice.RenderState.SetAlphaFunction(Compare_Greater);
	D3dDevice.RenderState.SetBlendOperation(BlendOperation_Add);
	D3dDevice.RenderState.SetSourceBlend(Blend_SourceAlpha);
	D3dDevice.RenderState.SetDestinationBlend(Blend_InvSourceAlpha);

	//Texture Filtering
	D3dDevice.SetSamplerState(0, SamplerStageStates_MinFilter, (int)TextureFilter_Linear);
	D3dDevice.SetSamplerState(0, SamplerStageStates_MagFilter, (int)TextureFilter_Linear);
	D3dDevice.SetSamplerState(0, SamplerStageStates_MipFilter, (int)TextureFilter_Linear);

	D3dDevice.SetSamplerState(1, SamplerStageStates_MinFilter, (int)TextureFilter_Linear);
	D3dDevice.SetSamplerState(1, SamplerStageStates_MagFilter, (int)TextureFilter_Linear);
	D3dDevice.SetSamplerState(1, SamplerStageStates_MipFilter, (int)TextureFilter_Linear);

	//Clear lights
	//foreach (Light light in d3dDevice.Lights)
	//{
	//	light.Enabled = false;
	//}

	//Limpiar todas las texturas
	//GuiController::Instance.TexturesManager.clearAll();

	//Reset Material
	D3dDevice.SetMaterial(DEFAULT_MATERIAL);
	ClearColor = DEFAULT_CLEAR_COLOR;

	//Limpiar IndexBuffer
	D3dDevice.setIndices(NULL);



	/* INEXPLICABLE PERO ESTO HACE QUE MI NOTEBOOK SE CUELGUE CON LA PANTALLA EN NEGRO!!!!!!!!!!

	//PointSprite
	this.d3dDevice.RenderState.PointSpriteEnable = true;
	this.d3dDevice.RenderState.PointScaleEnable = true;
	this.d3dDevice.RenderState.PointScaleA = 1.0f;
	this.d3dDevice.RenderState.PointScaleB = 1.0f;
	this.d3dDevice.RenderState.PointScaleC = 0.0f;
	 */ 
}

void TgcD3dDevice::doClear()
{
	D3dDevice.Clear(ClearFlags_Target | ClearFlags_ZBuffer, ClearColor, 1.0f, 0);
	HighResolutionTimer::Instance.Set();
}

void TgcD3dDevice::resetWorldTransofrm()
{
	D3dDevice.Transform.World(Matrix::SIdentity());
}

void TgcD3dDevice::shutDown()
{
	D3dDevice.Dispose();
}
