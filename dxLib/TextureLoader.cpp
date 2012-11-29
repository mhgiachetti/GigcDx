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

void TextureLoader::Save( const char * dstFile, ImageFileFormat format, LPD3DTEXTURE texture )
{
	D3DXSaveTextureToFile(dstFile, (D3DXIMAGE_FILEFORMAT)format,texture, NULL);
}

