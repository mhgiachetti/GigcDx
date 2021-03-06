// RenderState.h: interface for the RenderState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RENDERSTATE_H__03A47915_11ED_496A_92C4_C2C40DF6916C__INCLUDED_)
#define AFX_RENDERSTATE_H__03A47915_11ED_496A_92C4_C2C40DF6916C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"

class RenderState  
{

protected:
	LPD3DDEVICE m_device;
	
public:
	RenderState();
	RenderState(LPD3DDEVICE device);
	virtual ~RenderState();
	virtual void SetDevice(LPD3DDEVICE device);

public:
	virtual void SetLighting(bool enable);
	virtual bool GetLighting();
	virtual void SetCullMode(Cull cullMode);
	virtual Cull GetCullMode();
	virtual void SetZBufferEnable(bool enable);
	virtual bool GetZBufferEnable();
	virtual void SetAlphaBlendEnable(bool enable);
	virtual bool GetAlphaBlendEnable();
	virtual void SetblendOperation(BlendOperation blendOp);
	virtual BlendOperation GetblendOperation();
	virtual void SetSourceBlend(Blend blend);
	virtual Blend GetSourceBlend();
	virtual void SetDestinationBlend(Blend blend);
	virtual Blend GetDestinationBlend();
	virtual void SetAmbient(UINT color);
	virtual UINT GetAmbient();
	virtual void SetNormalizeNormals(bool enable);
	virtual bool GetNormalizeNormals();
	virtual void SetPointSize(float size);
	virtual float GetPointSize();
	virtual void SetfillMode(FillMode mode);
	virtual FillMode GetfillMode();
	virtual void SetSpecularEnable(bool enable);
	virtual bool GetSpecularEnable();
	virtual void SetshadeMode(ShadeMode mode);
	virtual ShadeMode GetshadeMode();
	virtual void SetMultiSampleAntiAlias(bool enable);
	virtual bool GetMultiSampleAntiAlias();
	virtual void SetSlopeScaleDepthBias(float bias);
	virtual float GetSlopeScaleDepthBias();
	virtual void SetDepthBias(float bias);
	virtual float GetDepthBias();
	virtual void SetColorVertex(bool enable);
	virtual bool GetColorVertex();
	virtual void SetFogEnable(bool enable);
	virtual bool GetFogEnable();
	virtual void SetAlphaTestEnable(bool enable);
	virtual bool GetAlphaTestEnable();
	virtual void SetReferenceAlpha(int value);
	virtual int GetReferenceAlpha();
	virtual void SetAlphaFunction(Compare function);
	virtual Compare GetAlphaFunction();
	virtual void SetPointSpriteEnable(bool enable);
	virtual bool GetPointSpriteEnable();
	virtual void SetPointScaleEnable(bool enable);
	virtual bool GetPointScaleEnable();
	virtual void SetPointScaleA(float value);
	virtual float GetPointScaleA();
	virtual void SetPointScaleB(float value);
	virtual float GetPointScaleB();
	virtual void SetPointScaleC(float value);
	virtual float GetPointScaleC();

public:
	PROPERTYGETSET(bool,Lighting);
	PROPERTYGETSET(Cull,CullMode);
	PROPERTYGETSET(bool,ZBufferEnable);
	PROPERTYGETSET(bool,AlphaBlendEnable);
	PROPERTYGETSET(BlendOperation,blendOperation);
	PROPERTYGETSET(Blend,SourceBlend);
	PROPERTYGETSET(Blend,DestinationBlend);
	PROPERTYGETSET(UINT,Ambient);
	PROPERTYGETSET(bool,NormalizeNormals);
	PROPERTYGETSET(float,PointSize);
	PROPERTYGETSET(FillMode,fillMode);
	PROPERTYGETSET(bool,SpecularEnable);
	PROPERTYGETSET(ShadeMode,shadeMode);
	PROPERTYGETSET(bool,MultiSampleAntiAlias);
	PROPERTYGETSET(float,SlopeScaleDepthBias);
	PROPERTYGETSET(float,DepthBias);
	PROPERTYGETSET(bool,ColorVertex);
	PROPERTYGETSET(bool,FogEnable);
	PROPERTYGETSET(bool,AlphaTestEnable);
	PROPERTYGETSET(int,ReferenceAlpha);
	PROPERTYGETSET(Compare,AlphaFunction);
	PROPERTYGETSET(bool,PointSpriteEnable);
	PROPERTYGETSET(bool,PointScaleEnable);
	PROPERTYGETSET(float,PointScaleA);
	PROPERTYGETSET(float,PointScaleB);
	PROPERTYGETSET(float,PointScaleC);
};

#endif // !defined(AFX_RENDERSTATE_H__03A47915_11ED_496A_92C4_C2C40DF6916C__INCLUDED_)
