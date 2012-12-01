// Font.cpp: implementation of the Font class.
//
//////////////////////////////////////////////////////////////////////

#include "Font.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Font::Font()
{
	m_font = NULL;
}

Font::Font(const Device &device, HFONT font)
{
	LOGFONT lf;

	GetObject(font,sizeof(LOGFONT), &lf);
	FontDescription fd;
	fd.SetCharSet((CharacterSet)lf.lfCharSet);
	fd.Width = lf.lfWidth;
	fd.Height= lf.lfHeight;
	fd.Weight= (FontWeight)lf.lfWeight;
	fd.SetFaceName(lf.lfFaceName);
	fd.SetOutputPrecision((Precision)lf.lfOutPrecision);
	fd.SetPitchAndFamily((PitchAndFamily)lf.lfPitchAndFamily);
	fd.SetQuality((FontQuality)lf.lfQuality);
	fd.IsItalic = lf.lfItalic > 0;
	
	D3DXCreateFontIndirect(device,fd,&m_font);
}

Font::Font( const Device &device, const FontDescription &description)
{
	D3DXCreateFontIndirect(device,description,&m_font);
}

Font::Font( LPD3DXFONT font )
{
	m_font = font;
}

Font::~Font()
{

}

Device Font::GetDevice()
{
	Device device;
	m_font->GetDevice(device);
	return device;
}

bool Font::Disposed()
{
	return m_font == NULL;
}

void Font::Dispose()
{
	if(m_font)
	{
		m_font->Release();
		m_font = NULL;
	}
}

Font::operator LPD3DXFONT() const
{
	return m_font;
}

Font::operator LPD3DXFONT*() const
{
	return (LPD3DXFONT*)&m_font;
}

FontDescription Font::GetFontDescription()
{
	FontDescription fd;
	m_font->GetDesc(fd);
	return fd;
}

int Font::DrawText( Sprite sprite, string text, int x, int y, int color )
{
	RECT rect;
	rect.left = rect.right = x;
	rect.top = rect.bottom = y;
	DrawTextFormat format = DrawTextFormat_Center | DrawTextFormat_NoClip | DrawTextFormat_VerticalCenter;
	
	return DrawText(sprite,text,rect,format,color);
}

int Font::DrawText( Sprite sprite, string text, POINT pos, int color )
{
	return DrawText(sprite,text,pos.x,pos.y,color);
}

int Font::DrawText( Sprite sprite, string text, RECT rect, DrawTextFormat format, int color )
{
	return m_font->DrawTextA(sprite,text.c_str(),-1,&rect, format,color);
}

RECT Font::MeasureString( Sprite sprite, string text, DrawTextFormat format, int color )
{
	int w = 0;  
	int h = 0;  
	LPDIRECT3DTEXTURE9 texture;  
	RECT rect;  
	POINT pt;  
	for(unsigned int i = 0;i < text.length();i++){  
		char c = text[i];  
		m_font->GetGlyphData(c,&texture,&rect,&pt);  
		int ch = rect.bottom - rect.top;  
		int cw = rect.right - rect.left;  
		if(ch > h) h = ch;  
		w += cw;  
    }  
	return rect;
}
