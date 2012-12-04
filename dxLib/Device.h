// Device.h: interface for the Device class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGDEVICE_H__7592C0FA_8975_4789_A621_497E8BBC5067__INCLUDED_)
#define AFX_MGDEVICE_H__7592C0FA_8975_4789_A621_497E8BBC5067__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
#include "Transform.h"
#include "RenderState.h"
#include "Light.h"
#include "Material.h"
#include "Texture.h"
#include "PresentParameters.h"
#include "ViewPort.h"
#include "IndexBuffer.h"

class Device  
{
protected:
	LPD3DDEVICE m_device;

public:
	Device();
	Device(LPD3DDEVICE device);

	Device(
		int adapter, DeviceType deviceType, HWND renderWindow, CreateFlags behaviorFlags,const PresentParameters &presentationParameters);

	virtual ~Device();

	Transform Transform;
	RenderState RenderState;
	
	//funciones
	void BeginScene();
	void EndScene();
	void Present();
	void Clear(ClearFlags flags, int color, float zdepth, DWORD stencil);
	void SetVertexFormat(VertexFormat format);
	VertexFormat GetVertexFormat();
	void SetStreamSource(int streamNumber, LPD3DVERTEXBUFFER vb, int offset, int stride);
	void SetIndices(const IndexBuffer &ib);
	IndexBuffer GetIndices();
	void SetTexture(int stage, const Texture &texture);
	virtual void Dispose();

	virtual void SetLight(int index, const Light &light);
	virtual void LightEnable(int index, bool enable);
	virtual void Setmaterial(const Material &mat);
	virtual Material Getmaterial();
	void SetSamplerState(int stage, SamplerStageStates state, int value);

	virtual void DrawPrimitives(PrimitiveType pt, int startVertex, int primitiveCount);
	virtual void DrawIndexedPrimitives(PrimitiveType primitiveType, int baseVertex, int minVertexIndex,
                                          int numVertices, int startIndex, int primCount);
	virtual void DrawUserPrimitives(PrimitiveType pt, int primitiveCount,const void * pVertices, int stride);

	void SetDevice(LPD3DDEVICE device);

	virtual Viewport Getviewport();
	virtual void Setviewport(Viewport viewport);

	PROPERTYGETSET(Viewport,viewport);
	PROPERTYGETSET(Material,material);
	PROPERTYGETSET(IndexBuffer,Indices);
	
	//operadores
	operator LPD3DDEVICE( void );
	operator LPD3DDEVICE( void ) const;
	operator LPD3DDEVICE*( void ) const;

};

#endif // !defined(AFX_MGDEVICE_H__7592C0FA_8975_4789_A621_497E8BBC5067__INCLUDED_)
