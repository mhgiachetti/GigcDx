// Transform.h: interface for the Transform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGTRANSFORM_H__D20CAABB_E0DE_4A01_9E1E_E18099B7AD1D__INCLUDED_)
#define AFX_MGTRANSFORM_H__D20CAABB_E0DE_4A01_9E1E_E18099B7AD1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
#include "Matrix.h"

class Transform  
{

protected:
	LPD3DDEVICE m_device;

public:
	Transform();
	Transform(LPD3DDEVICE device);
	virtual ~Transform();

	virtual void SetProjection(Matrix &mat);
	virtual Matrix GetProjection();

	virtual void SetWorld(Matrix &mat);
	virtual Matrix GetWorld();

	virtual void SetView(Matrix &mat);
	virtual Matrix GetView();

	virtual void SetDevice(LPD3DDEVICE device);

	PROPERTYGETSET(Matrix,World);
	PROPERTYGETSET(Matrix,View);
	PROPERTYGETSET(Matrix,Projection);

};

#endif // !defined(AFX_MGTRANSFORM_H__D20CAABB_E0DE_4A01_9E1E_E18099B7AD1D__INCLUDED_)
