// XMesh.h: interface for the XMesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGXMESH_H__EA873E0B_025F_4E3B_8BD6_107D5FBC7E6A__INCLUDED_)
#define AFX_MGXMESH_H__EA873E0B_025F_4E3B_8BD6_107D5FBC7E6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"
#include "Matrix.h"
#include "ExtendedMaterial.h"


class XMesh  
{
public:
	Mesh m_mesh;
	vector<Texture> m_textures;
	vector<Material> m_materials;

protected:
	Matrix m_transform;
	bool m_transform_dirty;
	Vector3 m_position;
	Vector3 m_rotation;
	Vector3 m_scale;
	
public:
	XMesh();
	virtual ~XMesh();

	void SetTexture(int nro, const Texture &textures);
	void SetTexture(const vector<Texture> &textures);
	void SetMaterial(int nro, const Material &material);
	void SetMaterial(const vector<Material> &materials);
	void SetMaterial(const vector<ExtendedMaterial> &materials);

	void invalidateTransform();
	Matrix GetTransform();
	Vector3 GetPosition();
	Vector3 GetRotation();
	Vector3 GetScale();
	void SetTransform(const Matrix &mat);
	void SetPosition(const Vector3 &pos);
	void SetRotation(const Vector3 &rot);
	void SetScale(const Vector3 &scale);

	
	void Render();
	void Release();

};

#endif // !defined(AFX_MGXMESH_H__EA873E0B_025F_4E3B_8BD6_107D5FBC7E6A__INCLUDED_)
