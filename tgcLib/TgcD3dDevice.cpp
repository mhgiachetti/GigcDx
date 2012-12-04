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
	
	if (caps.deviceCaps.SupportsHardwareTransformAndLight)
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
	d3dDevice = Device(0, DeviceType_Hardware, panel3d, flags, d3dpp);
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
	d3dDevice.Transform.Projection = 	
		Matrix::SPerspectiveFovLH(D3DXToRadian(45.0f),
		aspectRatio, zNearPlaneDistance, zFarPlaneDistance);

	//Render state
	d3dDevice.RenderState.SpecularEnable = false;
	d3dDevice.RenderState.fillMode = FillMode_Solid;
	d3dDevice.RenderState.CullMode = Cull_None;
	d3dDevice.RenderState.shadeMode = ShadeMode_Gouraud;
	d3dDevice.RenderState.MultiSampleAntiAlias = true;
	d3dDevice.RenderState.SlopeScaleDepthBias = -0.1f;
	d3dDevice.RenderState.DepthBias = 0;
	d3dDevice.RenderState.ColorVertex = true;
	d3dDevice.RenderState.Lighting = false;
	d3dDevice.RenderState.ZBufferEnable = true;
	d3dDevice.RenderState.FogEnable = false;

	//Alpha Blending
	d3dDevice.RenderState.AlphaBlendEnable = false;
	d3dDevice.RenderState.AlphaTestEnable = false;
	d3dDevice.RenderState.ReferenceAlpha = 100;
	d3dDevice.RenderState.AlphaFunction = Compare_Greater;
	d3dDevice.RenderState.blendOperation = BlendOperation_Add;
	d3dDevice.RenderState.SourceBlend = Blend_SourceAlpha;
	d3dDevice.RenderState.DestinationBlend = Blend_InvSourceAlpha;

	//Texture Filtering
	d3dDevice.SetSamplerState(0, SamplerStageStates_MinFilter, (int)TextureFilter_Linear);
	d3dDevice.SetSamplerState(0, SamplerStageStates_MagFilter, (int)TextureFilter_Linear);
	d3dDevice.SetSamplerState(0, SamplerStageStates_MipFilter, (int)TextureFilter_Linear);

	d3dDevice.SetSamplerState(1, SamplerStageStates_MinFilter, (int)TextureFilter_Linear);
	d3dDevice.SetSamplerState(1, SamplerStageStates_MagFilter, (int)TextureFilter_Linear);
	d3dDevice.SetSamplerState(1, SamplerStageStates_MipFilter, (int)TextureFilter_Linear);

	//Clear lights
	//foreach (Light light in d3dDevice.Lights)
	//{
	//	light.Enabled = false;
	//}

	//Limpiar todas las texturas
	//GuiController::Instance.TexturesManager.clearAll();

	//Reset Material
	d3dDevice.material = DEFAULT_MATERIAL;
	ClearColor = DEFAULT_CLEAR_COLOR;

	//Limpiar IndexBuffer
	d3dDevice.Indices = NULL;



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
	d3dDevice.Clear(ClearFlags_Target | ClearFlags_ZBuffer, ClearColor, 1.0f, 0);
	HighResolutionTimer::Instance.Set();
}

void TgcD3dDevice::resetWorldTransofrm()
{
	d3dDevice.Transform.World = Matrix::SIdentity();
}

void TgcD3dDevice::shutDown()
{
	d3dDevice.Dispose();
}
