// TgcText2d.h: interface for the TgcText2d class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGCTEXT2D_H__94098456_153A_4445_BA7C_3EBD9638F51F__INCLUDED_)
#define AFX_TGCTEXT2D_H__94098456_153A_4445_BA7C_3EBD9638F51F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../dxLib/dxLib.h"
#include "GuiController.h"

class TgcText2d  
{
public:
	virtual ~TgcText2d();

	Font d3dFont;

    int color;

    WRectangle rectangle;
	WPoint GetPosition()
    {
        return rectangle.TopLeft();
    }
	void SetPosition(WPoint pos)
    {
        rectangle.OffsetRect(pos);
    }
    /// <summary>
    /// Tamaño maximo del recuadro del texto
    /// </summary>
    WSize GetSize()
    {
        return rectangle.Size();
	}
	void SetSize(WSize value)
	{
       rectangle.SetSize(value);
    }

    string text;

    DrawTextFormat format;

    /// <summary>
    /// Alternativas de alineación del texto
    /// </summary>
    enum TextAlign
    {
        TextAlign_LEFT,
        TextAlign_RIGHT,
        TextAlign_CENTER
    };
protected:
	TextAlign align;
public:
    /// <summary>
    /// Alineación del texto
    /// </summary>
    TextAlign GetAlign()
    {
        return align;
    }
	void SetAlign(TextAlign value)
    {
        changeTextAlign(value);
    }

    TgcText2d()
    {
        changeTextAlign(TextAlign_CENTER);
        
		//changeFont(TgcDrawText::VERDANA_10); TODO
		changeFont(NULL);
        //color = Color.Black;

        Viewport viewport = GuiController::Instance.D3dDevice().GetViewport();
        rectangle = WRectangle(0, 0, viewport.Width, viewport.Height);
    }

    void render()
    {
		//TODO
        /*Sprite sprite = GuiController::Instance.Text3d.TextSprite;
        sprite.Begin(SpriteFlags.AlphaBlend);
        d3dFont.DrawText(sprite, text, rectangle, format, color);
        sprite.End();*/
    }

    /// <summary>
    /// Cambia la fuente del texto
    /// </summary>
    /// <param name="font">Fuente del sistema</param>
    void changeFont(HFONT font)
    {
        //Sprite sprite = GuiController.Instance.Text3d.TextSprite;
        FontDescription d;
		d.SetFaceName("Verdana");
		d.Height = 10;
		
		d3dFont = Font(GuiController::Instance.D3dDevice(), d);
    }

    /// <summary>
    /// Cambiar TextAlign y configurar DrawTextFormat
    /// </summary>
    void changeTextAlign(TextAlign align)
    {
        this->align = align;
        DrawTextFormat fAlign = DrawTextFormat_None;
        switch (align)
        {
            case TextAlign_LEFT:
                fAlign = DrawTextFormat_Left;
                break;
            case TextAlign_RIGHT:
                fAlign = DrawTextFormat_Right;
                break;
            case TextAlign_CENTER:
                fAlign = DrawTextFormat_Center;
                break;
        }
        format = DrawTextFormat_NoClip | DrawTextFormat_ExpandTabs | DrawTextFormat_WordBreak | fAlign;
    }

    void dispose()
    {
        //TODO: No se por que pero esto da error al hacer resize de la pantalla
        //d3dFont.Dispose();
    }

};

#endif // !defined(AFX_TGCTEXT2D_H__94098456_153A_4445_BA7C_3EBD9638F51F__INCLUDED_)
