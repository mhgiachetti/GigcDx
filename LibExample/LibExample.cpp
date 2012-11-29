// LibExample.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "PruebaVentana.h"


//agrego la libreria de directx
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")




int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	PruebaVentana window(hInstance);

	window.Play();
	
	return 0;
	
}


