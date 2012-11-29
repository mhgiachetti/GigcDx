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

	virtual void Projection(Matrix &mat);
	virtual Matrix Projection();

	virtual void World(Matrix &mat);
	virtual Matrix World();

	virtual void View(Matrix &mat);
	virtual Matrix View();

	virtual void SetDevice(LPD3DDEVICE device);

};

#endif // !defined(AFX_MGTRANSFORM_H__D20CAABB_E0DE_4A01_9E1E_E18099B7AD1D__INCLUDED_)
