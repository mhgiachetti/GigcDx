// FontDescription.h: interface for the FontDescription class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FONTDESCRIPTION_H__0DCEA423_67F2_4A7A_B284_D30046B7C17B__INCLUDED_)
#define AFX_FONTDESCRIPTION_H__0DCEA423_67F2_4A7A_B284_D30046B7C17B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include "globalDefines.h"
using namespace std;

struct FontDescription  
{
public:
	int Height;
    int Width;
    FontWeight Weight;
    int MipLevels;
    bool IsItalic;
private:
    byte _charSet;
    byte _outputPrecision;
    byte _quality;
    byte _pitchAndFamily;
    char _faceName[LF_FACESIZE];
public:
	FontDescription();
	~FontDescription();

	void SetFaceName(string facename);
	string GetFaceName();
	Precision GetOutputPrecision();
	void SetOutputPrecision(Precision outputPrecision);
	FontQuality GetQuality();
	void SetQuality(FontQuality quality);
	PitchAndFamily GetPitchAndFamily();
	void SetPitchAndFamily(PitchAndFamily pitchAndFamily);
	CharacterSet GetCharSet();
	void SetCharSet(CharacterSet charSet);

	operator D3DXFONT_DESC()const;
	operator D3DXFONT_DESC*()const;
};

#endif // !defined(AFX_FONTDESCRIPTION_H__0DCEA423_67F2_4A7A_B284_D30046B7C17B__INCLUDED_)
