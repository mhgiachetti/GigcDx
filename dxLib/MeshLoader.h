// MeshLoader.h: interface for the MeshLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MESHLOADER_H__F75874F5_AC17_4EE7_B309_545C11F3B4B4__INCLUDED_)
#define AFX_MESHLOADER_H__F75874F5_AC17_4EE7_B309_545C11F3B4B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "XMesh.h"
#include "Device.h"

class MeshLoader  
{
private:
	MeshLoader();
	~MeshLoader();
public:

	static XMesh LoadFromX(Device device, const char * srcFile);
	static XMesh LoadFromXML(Device device, const char * srcFile);

};

#endif // !defined(AFX_MGMESHLOADER_H__F75874F5_AC17_4EE7_B309_545C11F3B4B4__INCLUDED_)
