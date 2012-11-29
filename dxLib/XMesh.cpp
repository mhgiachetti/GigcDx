// XMesh.cpp: implementation of the XMesh class.
//
//////////////////////////////////////////////////////////////////////

#include "XMesh.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XMesh::XMesh()
{
	m_transform_dirty = false;
	m_transform.Identity();

}

XMesh::~XMesh()
{

}

void XMesh::SetTexture( int nro, const Texture &texture )
{
	if (nro >= m_textures.size())
		m_textures.resize(nro+1);

	m_textures[nro] = texture;
}

void XMesh::SetTexture( const vector<Texture> &textures )
{
	int size = textures.size();
	if(m_textures.size() < size)
		m_textures.resize(size);

	for (int i = 0; i < size ; i++)
	{
		m_textures[i] = textures[i];
	}
}

void XMesh::SetMaterial( int nro, const Material &material )
{
	if (nro >= m_materials.size())
		m_materials.resize(nro+1);
	
	m_materials[nro] = material;
}

void XMesh::SetMaterial( const vector<Material> &materials )
{
	int size = materials.size();
	if(m_materials.size() < size)
		m_materials.resize(size);
	
	for (int i = 0; i < size ; i++)
	{
		m_materials[i] = materials[i];
	}
}

void XMesh::SetMaterial( const vector<ExtendedMaterial> &materials )
{
	int size = materials.size();
	if(m_materials.size() < size)
		m_materials.resize(size);
	
	for (int i = 0; i < size ; i++)
	{
		m_materials[i] = materials[i].Material3D;
	}
}

void XMesh::invalidateTransform()
{
	
}

Matrix XMesh::GetTransform()
{
	if(m_transform_dirty)
	{
		//recalculo la matriz de transformacion
		m_transform =	Matrix::SScale(m_scale.X,m_scale.Y,m_scale.Z)*
						Matrix::SRotationYawPitchRoll(m_rotation.Z,m_rotation.X,m_rotation.Y)*
						Matrix::STranslation(m_position.X,m_position.Y,m_position.Z);

		
		m_transform_dirty = false;
	}

	return m_transform;
}

Vector3 XMesh::GetPosition()
{
	return m_position;
}

Vector3 XMesh::GetRotation()
{
	return m_rotation;
}

Vector3 XMesh::GetScale()
{
	return m_scale;
}

void XMesh::SetTransform( const Matrix &mat )
{
	m_transform = mat;
	m_transform_dirty = false;	
}

void XMesh::SetPosition( const Vector3 &pos )
{
	m_position = pos;
	invalidateTransform();
}

void XMesh::SetRotation( const Vector3 &rot )
{
	m_rotation = rot;
	invalidateTransform();
}

void XMesh::SetScale( const Vector3 &scale )
{
	m_scale = scale;
	invalidateTransform();
}

void XMesh::Render()
{
	
	Device device = m_mesh.GetDevice();
	
	device.Transform.World(GetTransform());
	
	
	for (int i = 0 ; i < m_materials.size(); i++)
	{
		device.SetMaterial(m_materials[i]);
		device.SetTexture(0,m_textures[i]);
		m_mesh.DrawSubset(0);
	}
	
}

void XMesh::Dispose()
{
	for (int i = 0; i < m_textures.size() ; i++)
	{
		m_textures[i].Dispose();
	}
	m_mesh.Dispose();
}
