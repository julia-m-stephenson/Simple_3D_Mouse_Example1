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

			deviceInfo.hid.dwVendorId;
			deviceInfo.hid.dwProductId;
			deviceInfo.hid.dwVersionNumber;
			deviceInfo.hid.usUsage;
			deviceInfo.hid.usUsagePage;


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
