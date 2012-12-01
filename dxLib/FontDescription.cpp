// FontDescription.cpp: implementation of the FontDescription class.
//
//////////////////////////////////////////////////////////////////////

#include "FontDescription.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FontDescription::FontDescription()
{
	ZeroMemory(this, sizeof(FontDescription));
}

FontDescription::~FontDescription()
{

}

std::string FontDescription::GetFaceName()
{
	return _faceName;
}

void FontDescription::SetFaceName( string facename )
{
	strcpy(_faceName,facename.c_str());
}


Precision FontDescription::GetOutputPrecision()
{
	return (Precision)_outputPrecision;
}

void FontDescription::SetOutputPrecision( Precision outputPrecision )
{
	_outputPrecision = (byte)outputPrecision;
}

FontQuality FontDescription::GetQuality()
{
	return (FontQuality)_quality;
}

void FontDescription::SetQuality( FontQuality quality )
{
	_quality = (byte)quality;
}

PitchAndFamily FontDescription::GetPitchAndFamily()
{
	return (PitchAndFamily)_pitchAndFamily;
}

void FontDescription::SetPitchAndFamily( PitchAndFamily pitchAndFamily )
{
	_pitchAndFamily = (byte)pitchAndFamily;
}

CharacterSet FontDescription::GetCharSet()
{
	return (CharacterSet)_charSet;
}

void FontDescription::SetCharSet( CharacterSet charSet )
{
	_charSet = (byte)charSet;
}

FontDescription::operator D3DXFONT_DESC() const
{
	return *((D3DXFONT_DESC*)this);
}

FontDescription::operator D3DXFONT_DESC*() const
{
	return (D3DXFONT_DESC*)this;
}
