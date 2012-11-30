// Manager.h: interface for the Manager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGER_H__03D776B7_9323_43B4_A17D_3C3EACCD5684__INCLUDED_)
#define AFX_MANAGER_H__03D776B7_9323_43B4_A17D_3C3EACCD5684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"
#include "Caps.h"

class Manager  
{
protected:
	static LPD3D m_d3d;
	
public:
	static UINT m_sdk_version;
	static LPD3D GetInterface();

	//static AdapterListCollection GetAdapters();
	/*static bool CheckDeviceType(int adapter, DeviceType checkType, Format displayFormat,
		Format backBufferFormat, bool windowed);
	
	static bool CheckDeviceType(int adapter, DeviceType checkType, Format displayFormat,
		Format backBufferFormat, bool windowed,	int &result);
	
	static bool CheckDeviceFormat(int adapter, DeviceType deviceType, Format adapterFormat, Usage usage,
		ResourceType resourceType, DepthFormat checkFormat);
	
	static bool CheckDeviceFormat(int adapter, DeviceType deviceType, Format adapterFormat, Usage usage,
		ResourceType resourceType, DepthFormat checkFormat, out int result);
	
	static bool CheckDeviceFormat(int adapter, DeviceType deviceType, Format adapterFormat, Usage usage,
		ResourceType resourceType, Format checkFormat);
	
	static bool CheckDeviceFormat(int adapter, DeviceType deviceType, Format adapterFormat, Usage usage,
		ResourceType resourceType, Format checkFormat, out int result);
	
	static bool CheckDeviceMultiSampleType(int adapter, DeviceType deviceType, Format surfaceFormat,
		[MarshalAs(UnmanagedType.U1)] bool windowed,
		MultiSampleType multiSampleType, out int result,
		out int qualityLevels);
	*/
	static bool CheckDeviceMultiSampleType(int adapter, DeviceType deviceType, Format surfaceFormat,
		bool windowed, MultiSampleType multiSampleType);
	
	/*static bool CheckDepthStencilMatch(int adapter, DeviceType deviceType, Format adapterFormat,
		Format renderTargetFormat, DepthFormat depthStencilFormat,
		out int result);
	
	static bool CheckDepthStencilMatch(int adapter, DeviceType deviceType, Format adapterFormat,
		Format renderTargetFormat, DepthFormat depthStencilFormat);
	
	static bool CheckDeviceFormatConversion(int adapter, DeviceType deviceType, Format sourceFormat,
		Format targetFormat, out int result);
	
	static bool CheckDeviceFormatConversion(int adapter, DeviceType deviceType, Format sourceFormat,
		Format targetFormat);*/
	
	static Caps GetDeviceCaps(int adapter, DeviceType deviceType);
	//static IntPtr GetAdapterMonitor(int adapter);
	//static bool DisableD3DSpy();
	//static bool GenerateD3DSpyBreak();
	
	static Format GetCurrentFormat();


};

#endif // !defined(AFX_MANAGER_H__03D776B7_9323_43B4_A17D_3C3EACCD5684__INCLUDED_)
