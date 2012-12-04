// Transform.cpp: implementation of the Transform class.
//
//////////////////////////////////////////////////////////////////////

#include "Transform.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Transform::Transform()
{
}

Transform::Transform( LPD3DDEVICE device )
{
	m_device = device;
}

Transform::~Transform()
{

}

void Transform::SetProjection( Matrix &mat )
{
	m_device->SetTransform(D3DTS_PROJECTION, mat);
}

Matrix Transform::GetProjection()
{
	Matrix mat;

	m_device->GetTransform(D3DTS_PROJECTION,mat);
	return mat;
}

void Transform::SetWorld( Matrix &mat )
{
	m_device->SetTransform(D3DTS_WORLD, mat);
}

Matrix Transform::GetWorld()
{
	Matrix mat;
	
	m_device->GetTransform(D3DTS_WORLD,mat);
	return mat;
}

void Transform::SetView( Matrix &mat )
{
	m_device->SetTransform(D3DTS_VIEW, mat);
}

Matrix Transform::GetView()
{
	Matrix mat;
	
	m_device->GetTransform(D3DTS_VIEW,mat);
	return mat;
}

void Transform::SetDevice( LPD3DDEVICE device )
{
	m_device = device;
}


