// Manager.cpp: implementation of the Manager class.
//
//////////////////////////////////////////////////////////////////////

#include "Manager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
LPD3D Manager::m_d3d = NULL;
UINT Manager::m_sdk_version = D3D_SDK_VERSION;

LPD3D Manager::GetInterface()
{
	if(!m_d3d)
	{
		m_d3d = Direct3DCreate(m_sdk_version);
	}
	return m_d3d;
}

bool Manager::CheckDeviceMultiSampleType( int adapter, DeviceType deviceType, Format surfaceFormat, bool windowed, MultiSampleType multiSampleType )
{
	return GetInterface()->CheckDeviceMultiSampleType(adapter,(D3DDEVTYPE)deviceType,(D3DFORMAT)surfaceFormat,
		windowed,(D3DMULTISAMPLE_TYPE)multiSampleType,NULL) == D3D_OK;
}

Caps Manager::GetDeviceCaps( int adapter, DeviceType deviceType )
{
	Caps caps;
	GetInterface()->GetDeviceCaps(adapter,(D3DDEVTYPE)deviceType, caps);
	return caps;
}

Format Manager::GetCurrentFormat()
{
	D3DDISPLAYMODE d;
	m_d3d->GetAdapterDisplayMode(0,&d);
	return (Format)d.Format;
}
