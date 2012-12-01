// Font.h: interface for the Font class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FONT_H__2C2E4115_4187_43EF_B36C_CFD8F29052F8__INCLUDED_)
#define AFX_FONT_H__2C2E4115_4187_43EF_B36C_CFD8F29052F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"
#include "Device.h"
#include "FontDescription.h"
#include "Sprite.h"

class Font  
{
	LPD3DXFONT m_font;
public:
	Font();
	Font(const Device &device, HFONT font);
	Font(const Device &device, const FontDescription &description);
	Font(LPD3DXFONT font);
	~Font();
	
	Device GetDevice();
	bool Disposed();
	void Dispose();
	FontDescription GetFontDescription();
	int DrawText(Sprite sprite, string text, int x, int y, int color);
	int DrawText(Sprite sprite, string text, POINT pos, int color);
	int DrawText(Sprite sprite, string text, RECT rect, DrawTextFormat format, int color);
    RECT MeasureString(Sprite sprite, string text, DrawTextFormat format, int color);

	
	operator LPD3DXFONT() const;
	operator LPD3DXFONT*() const;
};

#endif // !defined(AFX_FONT_H__2C2E4115_4187_43EF_B36C_CFD8F29052F8__INCLUDED_)
