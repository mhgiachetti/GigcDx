// Mesh.h: interface for the Mesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGMESH_H__FC25FDDF_4ADC_42AA_AA0F_61134BA98359__INCLUDED_)
#define AFX_MGMESH_H__FC25FDDF_4ADC_42AA_AA0F_61134BA98359__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include <vector>
#include "ExtendedMaterial.h"
#include "Device.h"

using namespace std;

class Mesh  
{
public:
	LPD3DXMESH m_mesh;

public:
	Mesh();
	Mesh(LPD3DXMESH mesh);
	virtual ~Mesh();
	void SetMesh(LPD3DXMESH mesh);
	void DrawSubset(int subset);
	VertexBuffer GetVertexBuffer();
	IndexBuffer GetIndexBuffer();
	void Release();
	Device GetDevice();

	static Mesh FromFile(const char * filename, MeshFlags flags, LPD3DDEVICE device);
	static Mesh FromFile( const char * filename, MeshFlags flags, LPD3DDEVICE device, vector<ExtendedMaterial> &materials);


	operator LPD3DXMESH();
	operator LPD3DXMESH*();

};

#endif // !defined(AFX_MGMESH_H__FC25FDDF_4ADC_42AA_AA0F_61134BA98359__INCLUDED_)
