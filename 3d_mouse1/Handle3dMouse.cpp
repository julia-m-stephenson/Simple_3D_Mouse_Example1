#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
/////////////////////////////////////////
// Globals
/////////////////////////////////////////
static RID_DEVICE_INFO globalDeviceInfo = { 0 };

/////////////////////////////////////////
// Handling 3D mouse events
/////////////////////////////////////////
UINT handle3dMouseEvents(RAWINPUT rawInputPacket)
{
	BYTE *pRawData;
	RID_DEVICE_INFO deviceInfo;
	UINT deviceInfoSize = sizeof(RID_DEVICE_INFO);
	UINT returnSize = 0;

	char buffer[256];
	wsprintf(buffer, TEXT(" HID: dwSizeHid=%04x dwCount:%04x bRawData:%04x \n"),
		rawInputPacket.data.hid.dwSizeHid,
		rawInputPacket.data.hid.dwCount,
		rawInputPacket.data.hid.bRawData[0]);
	OutputDebugString(buffer);

	// Lets have a look at the device info
	// Blender only does this once which makes sense we want to make the event loop as lean as possible
	if ((returnSize = GetRawInputDeviceInfo(rawInputPacket.header.hDevice, RIDI_DEVICEINFO, &deviceInfo, &deviceInfoSize)) > sizeof(RID_DEVICE_INFO))
	{
		// Something bad happened
		char buffer[256];
		wsprintf(buffer, TEXT(" GetRawInputDeviceInfo: Has overflowed buffer, returnSize=%04x expected size :%04x \n"),
			returnSize,
			sizeof(RID_DEVICE_INFO));
		OutputDebugString(buffer);
		PostQuitMessage(0);
	}
	if (returnSize > 0) {
		// Valid data received
		if (deviceInfo.dwType == RIM_TYPEHID)
		{
			// Phew it _is_ a HID device not a smelly old keyboard or normal mouse
			wsprintf(buffer, TEXT(" HID Info: dwVendorId=0x%04x dwProductId:0x%04x dwVersionNumber:0x%04x usUsage:0x%02x usUsagePage:0x%02x \n"),
				deviceInfo.hid.dwVendorId,
				deviceInfo.hid.dwProductId,
				deviceInfo.hid.dwVersionNumber,
				deviceInfo.hid.usUsage,
				deviceInfo.hid.usUsagePage);
			OutputDebugString(buffer);
			// Save device info for later
			globalDeviceInfo = deviceInfo;
			// decode vendor ids
			// based on https://www.3dconnexion.co.uk/nc/service/faqs/faq/how-can-i-check-if-my-usb-3d-mouse-is-recognized-by-windows.html
			deviceInfo.hid.dwVendorId;
			deviceInfo.hid.dwProductId;
			deviceInfo.hid.dwVersionNumber;
			deviceInfo.hid.usUsage;
			deviceInfo.hid.usUsagePage;
			if (deviceInfo.hid.dwVendorId == 0x046D)
			{
				// Logitech VendorId (Have to be careful as loads of meeces use this)
				switch (deviceInfo.hid.dwProductId) {
// Older devices all seem to have different key mappings bit of a pain
				case 0xC606: OutputDebugString(TEXT("SpaceMouse Classic USB\n"));
					break;
				case 0xC603: OutputDebugString(TEXT("SpaceMouse Plus USB\n"));
					break;
#if 0 // duplicate has same vid/pid
				case 0xC603: OutputDebugString(TEXT("SpaceMouse Plus XT USB\n"));
					break;
#endif
				case 0xC605: OutputDebugString(TEXT("CadMan\n"));
					break;
				case 0xC621: OutputDebugString(TEXT("SpaceBall 5000 USB\n"));
					break;
				case 0xC623: OutputDebugString(TEXT("SpaceTraveler\n"));
					break;
				case 0xC625: OutputDebugString(TEXT("SpacePilot\n"));
					break;
// Newer Devices have a standardised Key Mapping which makes things easier
				case 0xC626: OutputDebugString(TEXT("SpaceNavigator\n"));
					break;
				case 0xC627: OutputDebugString(TEXT("SpaceExplorer\n"));
					break;
				case 0xC628: OutputDebugString(TEXT("SpaceNavigator for Notebooks\n"));
					break;
				case 0xC629: OutputDebugString(TEXT("SpacePilot Pro\n"));
					break;
				case 0xC62B: OutputDebugString(TEXT("SpaceMouse Pro\n"));
					break;
				default:
					break;
				}
			}
			else if (deviceInfo.hid.dwVendorId == 0x256F) {
				// 3Dconnexion
				switch (deviceInfo.hid.dwProductId) {
// More modern devices also used standard key mapping
				case 0xC62E: OutputDebugString(TEXT("SpaceMouse Wireless (cabled)\n"));
					break;
				case 0xC62F: OutputDebugString(TEXT("SpaceMouse Wireless Receiver\n"));
					break;
				case 0xC631: OutputDebugString(TEXT("SpaceMouse Pro Wireless (cabled)\n"));
					break;
				case 0xC632: OutputDebugString(TEXT("SpaceMouse Pro Wireless Receiver\n"));
					break;
				case 0xC633: OutputDebugString(TEXT("SpaceMouse Enterprise\n"));
					break;
				case 0xC635: OutputDebugString(TEXT("SpaceMouse Compact\n"));
					break;
#if 0
// These are not multi-axis devices so not really interested
				case 0xC650: OutputDebugString(TEXT("CadMouse\n"));
					break;
				case 0xC651: OutputDebugString(TEXT("CadMouse Wireless\n"));
					break;
				case 0xC652: OutputDebugString(TEXT("Universal Receiver\n"));
					break;
				case 0xC654: OutputDebugString(TEXT("CadMouse Pro Wireless\n"));
					break;
				case 0xC657: OutputDebugString(TEXT("CadMouse Pro Wireless Left\n"));
					break;
#endif
				default:
					break;
				}
			}
		}
		else
		{
			// ignore??
			return 0;
		}

	}
	// Process data
	pRawData = rawInputPacket.data.hid.bRawData;
	return 0;
}
