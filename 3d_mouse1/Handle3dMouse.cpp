#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "V3DKey.h"// From 3dConnexions
#include "V3DKeyDebug.h"// My code, Text strings for the above
#include "KeyMap3dMouse.h"
#include "Handle3dMouse.h"

/////////////////////////////////////////
// Globals
/////////////////////////////////////////
static RID_DEVICE_INFO globalDeviceInfo = { 0 };
static short globalAxis[6] = { 0 };//Full set of ROTATION and Movement 
static const V3DKey * currentKeyMap = NULL;// pointer to current map
static short currentKeyMapSize = 0; // number of elemements of the above

/////////////////////////////////////////
// Handling 3D mouse events
/////////////////////////////////////////
UINT handle3dMouseEvents(RAWINPUT rawInputPacket, short **axisData, UINT *key)
{
	BYTE *pRawData;
	RID_DEVICE_INFO deviceInfo;
	UINT deviceInfoSize = sizeof(RID_DEVICE_INFO);
	UINT returnSize = 0;
	UINT returnValue = 0;
	char buffer[256];
	*key = V3DK_INVALID;
#ifdef JMS_VERBOSE
	wsprintf(buffer, TEXT(" HID: dwSizeHid=%04x dwCount:%04x bRawData:%04x \n"),
		rawInputPacket.data.hid.dwSizeHid,
		rawInputPacket.data.hid.dwCount,
		rawInputPacket.data.hid.bRawData[0]);
	OutputDebugString(buffer);
#endif
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
#ifdef JMS_VERBOSE
			wsprintf(buffer, TEXT(" HID Info: dwVendorId=0x%04x dwProductId:0x%04x dwVersionNumber:0x%04x usUsage:0x%02x usUsagePage:0x%02x \n"),
				deviceInfo.hid.dwVendorId,
				deviceInfo.hid.dwProductId,
				deviceInfo.hid.dwVersionNumber,
				deviceInfo.hid.usUsage,
				deviceInfo.hid.usUsagePage);
			OutputDebugString(buffer);
#endif
			// Save device info for later
			globalDeviceInfo = deviceInfo;
			// double check usage matches multi-globalAxis device
			if ((deviceInfo.hid.usUsage != 0x08) || (deviceInfo.hid.usUsagePage != 0x01)) {
				currentKeyMap = NULL;
				currentKeyMapSize = 0;
				return -1;
			}

			// decode vendor ids
			// based on https://www.3dconnexion.co.uk/nc/service/faqs/faq/how-can-i-check-if-my-usb-3d-mouse-is-recognized-by-windows.html
			
			if (deviceInfo.hid.dwVendorId == 0x046D)
			{
				// Logitech VendorId (Have to be careful as loads of meeces use this)
				switch (deviceInfo.hid.dwProductId) {
// Older devices all seem to have different key mappings bit of a pain
				case 0xC606: OutputDebugString(TEXT("SpaceMouse Classic USB\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					break;
				case 0xC603: OutputDebugString(TEXT("SpaceMouse Plus USB\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					break;
#if 0 // duplicate has same vid/pid
				case 0xC603: OutputDebugString(TEXT("SpaceMouse Plus XT USB\n"));
					break;
#endif
				case 0xC605: OutputDebugString(TEXT("CadMan\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					break;
				case 0xC621: OutputDebugString(TEXT("SpaceBall 5000 USB\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					break;
				case 0xC623: OutputDebugString(TEXT("SpaceTraveler\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					break;
				case 0xC625: 
					OutputDebugString(TEXT("SpacePilot\n"));
					currentKeyMap = spacePilotKeys;
					currentKeyMapSize = sizeof(spacePilotKeys) / sizeof(V3DKey);
					break;
// Newer Devices have a standardised Key Mapping which makes things easier
				case 0xC626: OutputDebugString(TEXT("SpaceNavigator\n"));
					currentKeyMap = spaceNavigatorKeys;
					currentKeyMapSize = sizeof(spaceNavigatorKeys) / sizeof(V3DKey);
					break;
				case 0xC627: OutputDebugString(TEXT("SpaceExplorer\n"));
					currentKeyMap = spaceExplorerKeys;
					currentKeyMapSize = sizeof(spaceExplorerKeys) / sizeof(V3DKey);
					break;
				case 0xC628: OutputDebugString(TEXT("SpaceNavigator for Notebooks\n"));
					currentKeyMap = spaceNavigatorKeys;
					currentKeyMapSize = sizeof(spaceNavigatorKeys) / sizeof(V3DKey);
					break;
				case 0xC629: OutputDebugString(TEXT("SpacePilot Pro\n"));
					currentKeyMap = spacePilotProKeys;
					currentKeyMapSize = sizeof(spacePilotProKeys) / sizeof(V3DKey);
					break;
				case 0xC62B: OutputDebugString(TEXT("SpaceMouse Pro\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);					
					break;
				default:
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					break;
				}
			}
			else if (deviceInfo.hid.dwVendorId == 0x256F) {
				// 3Dconnexion
				switch (deviceInfo.hid.dwProductId) {
// More modern devices also used standard key mapping
				case 0xC62E: OutputDebugString(TEXT("SpaceMouse Wireless (cabled)\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);
					break;
				case 0xC62F: OutputDebugString(TEXT("SpaceMouse Wireless Receiver\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);
					break;
				case 0xC631: OutputDebugString(TEXT("SpaceMouse Pro Wireless (cabled)\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);
					break;
				case 0xC632: OutputDebugString(TEXT("SpaceMouse Pro Wireless Receiver\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);
					break;
				case 0xC633: OutputDebugString(TEXT("SpaceMouse Enterprise\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);
					break;
				case 0xC635: OutputDebugString(TEXT("SpaceMouse Compact\n"));
					currentKeyMap = spaceMouseProKeys;
					currentKeyMapSize = sizeof(spaceMouseProKeys) / sizeof(V3DKey);
					break;

// These are not multi-globalAxis devices so not really interested
				case 0xC650: //OutputDebugString(TEXT("CadMouse\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					return -1;
					break;
				case 0xC651: //OutputDebugString(TEXT("CadMouse Wireless\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					return -1;
					break;
				case 0xC652: //OutputDebugString(TEXT("Universal Receiver\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					return -1;
					break;
				case 0xC654: //OutputDebugString(TEXT("CadMouse Pro Wireless\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					return -1;
					break;
				case 0xC657: //OutputDebugString(TEXT("CadMouse Pro Wireless Left\n"));
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					return -1;
					break;
				default:
					currentKeyMap = NULL;
					currentKeyMapSize = 0;
					return -1;
					break;
				}
			}
			else {
				// Unrecognised device
				currentKeyMap = NULL;
				currentKeyMapSize = 0;
				return -1;
			}

		}
		else
		{
			// ignore??
			currentKeyMap = NULL;
			currentKeyMapSize = 0;
			return -1;
		}

	}
	else
	{
		return -1;// couldn't process message
	}
	// If we got this far is a device we support !!
	// Process data
	// This is based on code from TranslateRawInputData (rawinput.hpp) provided as part of the 
	// 3D Connexions S3DM_SDK_v2-0-4_r7688_raw_input example
	pRawData = rawInputPacket.data.hid.bRawData;
	if (pRawData[0] == 0x01) // Translation vector
	{
		// this is x,y,z 16 bit number 
		short* pTranslationData = (short*)(&rawInputPacket.data.hid.bRawData[1]);
		// Cache the pan zoom data
		globalAxis[0] = (pTranslationData[0]);
		globalAxis[1] = (pTranslationData[1]);
		globalAxis[2] = (pTranslationData[2]);
		// Check if we have a Rotation information in same packet
		if (rawInputPacket.data.hid.dwSizeHid >= 13) // Highspeed package
		{
			// Cache the rotation data
			globalAxis[3] = (pTranslationData[3]);
			globalAxis[4] = (pTranslationData[4]);
			globalAxis[5] = (pTranslationData[5]);
			//deviceData.isDirty = true;????
		}
		returnValue = H3D_MOTION_EVENT;

	}
	else if (pRawData[0] == 0x02)  // Rotation vector
	{
		// this is x,y,z 16 bit number 
		short* pRotationData = (short*)(&rawInputPacket.data.hid.bRawData[1]);
		// Cache the pan zoom data
		globalAxis[3] = (pRotationData[0]);
		globalAxis[4] = (pRotationData[1]);
		globalAxis[5] = (pRotationData[2]);
		returnValue = H3D_MOTION_EVENT;
	}
	else if (pRawData[0] == 0x03)  // Keystate change
	{
		INT16 i = 0;// index of key map
		if ((currentKeyMap != NULL) && (currentKeyMapSize != 0)) {
			INT32 sKeyData = *(INT32*)(&rawInputPacket.data.hid.bRawData[1]);
			INT32 mask = 0x0001;
			if (sKeyData != 0x0000) {
				// Key has been pressed
				for (i = 1; i < currentKeyMapSize; i++) {
					if ((mask&sKeyData) == mask) {
						// mask set
						if (i < V3DKEYDEBUGSIZE)
						{
							wsprintf(buffer, TEXT(" sKeyData:0x%04x currentKeyMapSize:%d entry: %d Mapped:0x%04x %s \n"),
								sKeyData,
								currentKeyMapSize,
								i,
								currentKeyMap[i],
								V3DKeyDebug[currentKeyMap[i]]
							);
						}
						else
						{
							wsprintf(buffer, TEXT(" sKeyData:0x%04x currentKeyMapSize:%d entry: %d Mapped:0x%04x \n"),
								sKeyData,
								currentKeyMapSize,
								i,
								currentKeyMap[i]
							);
						}
						OutputDebugString(buffer);
						*key = currentKeyMap[i];
						break;
					}
					mask = mask << 1;
				}
			}
		}
		returnValue = H3D_KEY_EVENT;
	}
	else 
	{
		// We don't understand this data type
		return -1;
	}
	wsprintf(buffer, TEXT(" Vector Info: TX:%06d TY:%06d TZ:%06d RX:%06d RY:%06d RZ:%06d  \n"),
		globalAxis[0],
		globalAxis[1],
		globalAxis[2],
		globalAxis[3],
		globalAxis[4],
		globalAxis[5]);
	OutputDebugString(buffer);
	*axisData = globalAxis;
	return returnValue;
}
