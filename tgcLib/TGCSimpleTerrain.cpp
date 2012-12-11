// TgcSimpleTerrain.cpp: implementation of the TgcSimpleTerrain class.
//
//////////////////////////////////////////////////////////////////////

#include "TgcSimpleTerrain.h"
#include "GuiController.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TgcSimpleTerrain::TgcSimpleTerrain()
{
	enabled = true;
	alphaBlendEnable = false;
}

TgcSimpleTerrain::~TgcSimpleTerrain()
{

}

/// <summary>
/// Valor de Y para cada par (X,Z) del Heightmap
/// </summary>
IntMatrix TgcSimpleTerrain::GetHeightmapData()
{
	return heightmapData;
}

/// <summary>
/// Indica si la malla esta habilitada para ser renderizada
/// </summary>
bool TgcSimpleTerrain::GetEnabled()
{
	return enabled;
}
void TgcSimpleTerrain::SetEnabled(bool value)
{
	enabled = value;
}

/// <summary>
/// Centro del terreno
/// </summary>
Vector3 TgcSimpleTerrain::GetCenter()
{
	return center;
}

/// <summary>
/// Habilita el renderizado con AlphaBlending para los modelos
/// con textura o colores por vértice de canal Alpha.
/// Por default está deshabilitado.
/// </summary>
bool TgcSimpleTerrain::GetAlphaBlendEnable()
{
	return alphaBlendEnable;
}
void TgcSimpleTerrain::SetAlphaBlendEnable(bool value)
{
	alphaBlendEnable = value;
}


/// <summary>
/// Crea la malla de un terreno en base a un Heightmap
/// </summary>
/// <param name="heightmapPath">Imagen de Heightmap</param>
/// <param name="scaleXZ">Escala para los ejes X y Z</param>
/// <param name="scaleY">Escala para el eje Y</param>
/// <param name="center">Centro de la malla del terreno</param>
void TgcSimpleTerrain::loadHeightmap(string heightmapPath, float scaleXZ, float scaleY, Vector3 center)
{
	Device d3dDevice = GuiController::Instance.D3dDevice;
	this->center = center;

	//Dispose de VertexBuffer anterior, si habia
	if (!vbTerrain.Disposed())
	{
		vbTerrain.Dispose();
	}

	//cargar heightmap
	heightmapData = loadHeightMap(d3dDevice, heightmapPath);
	float width = (float)heightmapData.GetLength(0);
	float length = (float)heightmapData.GetLength(1);


	//Crear vertexBuffer
	int vertexSize = CustomVertex::PositionTextured::Size();
	totalVertices = 2 * 3 * (heightmapData.GetLength(0) - 1) * (heightmapData.GetLength(1) - 1);
	vbTerrain.Create(d3dDevice, CustomVertex::PositionTextured::Size()*totalVertices, Usage_Dynamic | Usage_WriteOnly, CustomVertex::PositionTextured::Format(), Pool_Default);

	//Cargar vertices
	int dataIdx = 0;
	vector<CustomVertex::PositionTextured> data(totalVertices);

	center.X = center.X * scaleXZ - (width / 2) * scaleXZ;
	center.Y = center.Y * scaleY;
	center.Z = center.Z * scaleXZ - (length / 2) * scaleXZ;

	for (int i = 0; i < width - 1; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			//Vertices
			Vector3 v1 = Vector3(center.X + i * scaleXZ, center.Y + heightmapData.GetItem(i, j) * scaleY, center.Z + j * scaleXZ);
			Vector3 v2 = Vector3(center.X + i * scaleXZ, center.Y + heightmapData.GetItem(i, j + 1) * scaleY, center.Z + (j + 1) * scaleXZ);
			Vector3 v3 = Vector3(center.X + (i + 1) * scaleXZ, center.Y + heightmapData.GetItem(i + 1, j) * scaleY, center.Z + j * scaleXZ);
			Vector3 v4 = Vector3(center.X + (i + 1) * scaleXZ, center.Y + heightmapData.GetItem(i + 1, j + 1) * scaleY, center.Z + (j + 1) * scaleXZ);

			//Coordendas de textura
			Vector2 t1 = Vector2(i / width, j / length);
			Vector2 t2 = Vector2(i / width, (j + 1) / length);
			Vector2 t3 = Vector2((i + 1) / width, j / length);
			Vector2 t4 = Vector2((i + 1) / width, (j + 1) / length);

			//Cargar triangulo 1
			data[dataIdx] = CustomVertex::PositionTextured(v1, t1.X, t1.Y);
			data[dataIdx + 1] = CustomVertex::PositionTextured(v2, t2.X, t2.Y);
			data[dataIdx + 2] = CustomVertex::PositionTextured(v4, t4.X, t4.Y);

			//Cargar triangulo 2
			data[dataIdx + 3] = CustomVertex::PositionTextured(v1, t1.X, t1.Y);
			data[dataIdx + 4] = CustomVertex::PositionTextured(v4, t4.X, t4.Y);
			data[dataIdx + 5] = CustomVertex::PositionTextured(v3, t3.X, t3.Y);

			dataIdx += 6;
		}
	}


	vbTerrain.SetData(&(data[0]), totalVertices*vertexSize, LockFlags_None);
}

/// <summary>
/// Carga la textura del terreno
/// </summary>
void TgcSimpleTerrain::loadTexture(string path)
{
	//Dispose textura anterior, si habia
	if (!terrainTexture.Disposed())
	{
		terrainTexture.Dispose();
	}

	Device d3dDevice = GuiController::Instance.D3dDevice;

	terrainTexture = TextureLoader::FromFile(d3dDevice,path.c_str());
}




/// <summary>
/// Carga los valores del Heightmap en una matriz
/// </summary>
IntMatrix TgcSimpleTerrain::loadHeightMap(Device d3dDevice, string path)
{
	Texture bitmap = TextureLoader::FromFile(d3dDevice,path.c_str(),0,0,1,Usage_None, Format_X8R8G8B8,Pool_Managed,Filter_None,Filter_None,0);
	SurfaceDescription desc = bitmap.GetSurfaceDescription(0);

	int pitch;
	byte * bdata = (byte*)bitmap.LockRectangle(0,LockFlags_ReadOnly,pitch);

	int width = desc.Width;
	int height = desc.Height;
	IntMatrix heightmap(width, height);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//(j, i) invertido para primero barrer filas y despues columnas
			int offset = j*pitch + i*4;
			byte r = bdata[offset + 0];
			byte g = bdata[offset + 1];
			byte b = bdata[offset + 2];
			float intensity = r * 0.299f + g * 0.587f + b * 0.114f;
			heightmap.SetItem(i, j, (int)intensity);
		}
    
	}

	bitmap.Dispose();
	return heightmap;
}


/// <summary>
/// Renderiza el terreno
/// </summary>
void TgcSimpleTerrain::render()
{
	if (!enabled)
		return;

	Device d3dDevice = GuiController::Instance.D3dDevice;
	d3dDevice.Transform.World = Matrix::SIdentity();

	//Render terrain 
	d3dDevice.SetTexture(0, terrainTexture);
	d3dDevice.SetTexture(1, NULL);
	d3dDevice.material = TgcD3dDevice::DEFAULT_MATERIAL;

	d3dDevice.SetVertexFormat(CustomVertex::PositionTextured::Format());
	d3dDevice.SetStreamSource(0, vbTerrain, 0,CustomVertex::PositionTextured::Size());
	d3dDevice.DrawPrimitives(PrimitiveType_TriangleList, 0, totalVertices / 3);
}

Vector3 TgcSimpleTerrain::GetPosition()
{
	return center;
}

/// <summary>
/// Libera los recursos del Terreno
/// </summary>
void TgcSimpleTerrain::dispose()
{
	vbTerrain.Dispose();
	terrainTexture.Dispose();
	heightmapData.Free();
}
