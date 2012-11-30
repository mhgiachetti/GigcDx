// TextureLoader.cpp: implementation of the TextureLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "TextureLoader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
TextureLoader::TextureLoader()
{
	
}

TextureLoader::~TextureLoader()
{
	
}

Texture TextureLoader::FromFile( LPD3DDEVICE device, const char * srcFile )
{
	Texture texture;
	D3DXCreateTextureFromFile(device, srcFile, texture);
	return texture;
}

Texture TextureLoader::FromFile( LPD3DDEVICE device, const char * srcFile, int width, int height, int mipLevel, Usage usage, Format format, Pool pool, Filter filter, Filter mipFilter, int colorKey )
{
	Texture texture;
	D3DXCreateTextureFromFileEx(device, srcFile, width, height, mipLevel, usage, (D3DFORMAT)format, (D3DPOOL)pool, filter, mipFilter, colorKey, NULL,NULL,texture);
	return texture;
}

void TextureLoader::Save( const char * dstFile, ImageFileFormat format, LPD3DTEXTURE texture )
{
	D3DXSaveTextureToFile(dstFile, (D3DXIMAGE_FILEFORMAT)format,texture, NULL);
}

