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

class Device  
{
protected:
	LPD3DDEVICE m_device;

public:
	Device();
	Device(LPD3DDEVICE device);
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
	void setStreamSource(int streamNumber, LPD3DVERTEXBUFFER vb, int offset, int stride);
	void setIndices(LPD3DINDEXBUFFER ib);
	void SetTexture(int stage, const Texture &texture);
	virtual void Release();

	virtual void SetLight(int index, const Light &light);
	virtual void LightEnable(int index, bool enable);
	virtual void SetMaterial(const Material &mat);

	virtual void DrawPrimitives(PrimitiveType pt, int startVertex, int primitiveCount);
	virtual void DrawIndexedPrimitives(PrimitiveType primitiveType, int baseVertex, int minVertexIndex,
                                          int numVertices, int startIndex, int primCount);
	virtual void DrawUserPrimitives(PrimitiveType pt, int primitiveCount,const void * pVertices, int stride);

	void SetDevice(LPD3DDEVICE device);
	
	//operadores
	operator LPD3DDEVICE( void );

};

#endif // !defined(AFX_MGDEVICE_H__7592C0FA_8975_4789_A621_497E8BBC5067__INCLUDED_)
