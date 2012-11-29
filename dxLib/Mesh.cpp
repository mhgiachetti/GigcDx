// Mesh.cpp: implementation of the Mesh class.
//
//////////////////////////////////////////////////////////////////////

#include "Mesh.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mesh::Mesh()
{
}

Mesh::Mesh( LPD3DXMESH mesh )
{
	SetMesh(mesh);
}

Mesh::~Mesh()
{

}

Mesh Mesh::FromFile( const char * filename, MeshFlags flags, LPD3DDEVICE device )
{
	LPD3DXMESH mesh;
	D3DXLoadMeshFromX(filename,flags,device,NULL,NULL,NULL,NULL,&mesh);
	return Mesh(mesh);
}

Mesh Mesh::FromFile( const char * filename, MeshFlags flags, LPD3DDEVICE device,
						vector<ExtendedMaterial> &outMaterials)
{
	LPD3DXMESH mesh;
	LPD3DXBUFFER pAdjacency;
	LPD3DXBUFFER pEffect;
	LPD3DXBUFFER pMaterials;
	DWORD numMaterials;
	D3DXLoadMeshFromX(filename,flags,device,&pAdjacency,&pMaterials,&pEffect,&numMaterials,&mesh);

	D3DXMATERIAL* exMaterials = (D3DXMATERIAL*)pMaterials->GetBufferPointer();

	outMaterials.resize(numMaterials);

	for (int i=0; i< numMaterials; i++)
	{
		outMaterials[i].Material3D = *((Material*)&exMaterials[i].MatD3D);
		outMaterials[i].Material3D.Ambient = outMaterials[i].Material3D.Diffuse;
		outMaterials[i].TextureFilename = exMaterials[i].pTextureFilename;
	}

	pAdjacency->Release();
	pEffect->Release();
	pMaterials->Release();

	return Mesh(mesh);
}

void Mesh::SetMesh( LPD3DXMESH mesh )
{
	m_mesh = mesh;
}

Mesh::operator LPD3DXMESH()
{
	return m_mesh;
}

Mesh::operator LPD3DXMESH*()
{
	return &m_mesh;
}

void Mesh::DrawSubset( int subset )
{
	m_mesh->DrawSubset(subset);
}

VertexBuffer Mesh::GetVertexBuffer()
{
	VertexBuffer vb;
	m_mesh->GetVertexBuffer(vb);
	return vb;
}

IndexBuffer Mesh::GetIndexBuffer()
{
	IndexBuffer ib;
	m_mesh->GetIndexBuffer(ib);
	return ib;
}

void Mesh::Release()
{
	m_mesh->Release();
}

Device Mesh::GetDevice()
{
	LPD3DDEVICE device;
	m_mesh->GetDevice(&device);
	return Device(device);
}

