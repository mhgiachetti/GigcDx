// TextureLoader.h: interface for the TextureLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGTEXTURELOADER_H__9AA7E038_3270_4DA7_B933_81BD58D83F1E__INCLUDED_)
#define AFX_MGTEXTURELOADER_H__9AA7E038_3270_4DA7_B933_81BD58D83F1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Texture.h"
#include "globalDefines.h"

class TextureLoader  
{
private:
	TextureLoader();
	~TextureLoader();
public:
	static Texture FromFile(LPD3DDEVICE device, const char * srcFile);
	static Texture FromFile(LPD3DDEVICE device, const char * srcFile, int width, int height, int mipLevela, Usage usage, Format format, Pool pool, Filter filter, Filter mipFilter, int colorKey);
	static void Save(const char *dstFile, ImageFileFormat format, LPD3DTEXTURE texture);
};

#endif // !defined(AFX_MGTEXTURELOADER_H__9AA7E038_3270_4DA7_B933_81BD58D83F1E__INCLUDED_)
