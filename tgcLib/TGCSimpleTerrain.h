// TgcSimpleTerrain.h: interface for the TgcSimpleTerrain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGCSIMPLETERRAIN_H__B1764ADE_C452_48B1_818A_4C765146DB4F__INCLUDED_)
#define AFX_TGCSIMPLETERRAIN_H__B1764ADE_C452_48B1_818A_4C765146DB4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../dxLib/dxLib.h"
#include "IRenderObject.h"
#include "IntMatrix.h"

class TgcSimpleTerrain : IRenderObject
{
private:
	VertexBuffer vbTerrain;
	Texture terrainTexture;
	int totalVertices;
	IntMatrix heightmapData;
	bool enabled;
	Vector3 center;
	bool alphaBlendEnable;

public:
	TgcSimpleTerrain();
	virtual ~TgcSimpleTerrain();

	IntMatrix GetHeightmapData();
	
	bool GetEnabled();
	void SetEnabled(bool value);
	Vector3 GetCenter();

	bool GetAlphaBlendEnable();
	void SetAlphaBlendEnable(bool value);

	void loadHeightmap(string heightmapPath, float scaleXZ, float scaleY, Vector3 center);
	void loadTexture(string path);
	void render();
	Vector3 GetPosition();
	void dispose();

protected:
	IntMatrix loadHeightMap(Device d3dDevice, string path);
};

#endif // !defined(AFX_TGCSIMPLETERRAIN_H__B1764ADE_C452_48B1_818A_4C765146DB4F__INCLUDED_)
