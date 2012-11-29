// MeshLoader.cpp: implementation of the MeshLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "MeshLoader.h"
#include "Mesh.h"
#include "TextureLoader.h"
#include "Path.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MeshLoader::MeshLoader()
{
	
}

MeshLoader::~MeshLoader()
{
	
}

XMesh MeshLoader::LoadFromX( Device device, const char * srcFile )
{
	XMesh mesh;
	string dir = Path::GetDirectoryName(srcFile)+"\\";
	vector<ExtendedMaterial> materials;
	vector<Texture> textures;
	
	mesh.m_mesh = Mesh::FromFile(srcFile, MeshFlags_Managed, device, materials);
	
	textures.resize(materials.size());
	
	for (int i = 0; i < materials.size();i++)
	{
		string tex = dir + materials[i].TextureFilename;
		textures[i] = TextureLoader::FromFile(device,tex.c_str());
	}
	
	mesh.SetTexture(textures);
	mesh.SetMaterial(materials);

	return mesh;
}

XMesh MeshLoader::LoadFromXML( Device device, const char * srcFile )
{
	XMesh mesh;
	string dir = Path::GetDirectoryName(srcFile)+"\\";
	vector<ExtendedMaterial> materials;
	vector<Texture> textures;



	return mesh;
}

