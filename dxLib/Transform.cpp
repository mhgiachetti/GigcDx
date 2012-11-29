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

void Transform::Projection( Matrix &mat )
{
	m_device->SetTransform(D3DTS_PROJECTION, mat);
}

Matrix Transform::Projection()
{
	Matrix mat;

	m_device->GetTransform(D3DTS_PROJECTION,mat);
	return mat;
}

void Transform::World( Matrix &mat )
{
	m_device->SetTransform(D3DTS_WORLD, mat);
}

Matrix Transform::World()
{
	Matrix mat;
	
	m_device->GetTransform(D3DTS_WORLD,mat);
	return mat;
}

void Transform::View( Matrix &mat )
{
	m_device->SetTransform(D3DTS_VIEW, mat);
}

Matrix Transform::View()
{
	Matrix mat;
	
	m_device->GetTransform(D3DTS_VIEW,mat);
	return mat;
}

void Transform::SetDevice( LPD3DDEVICE device )
{
	m_device = device;
}


