/*----------------------------------------------------------------------
 *  V3DKey.h -- Virtual 3D Keys
 *
 *  enums for all current V3DKeys
 *
 * Written:     January 2013
 * Original author:      Jim Wick
 *
 *----------------------------------------------------------------------
 *
 * Copyright notice:
 * Copyright (c) 2013-2015 3Dconnexion. All rights reserved. 
 * 
 * This file and source code are an integral part of the "3Dconnexion
 * Software Developer Kit", including all accompanying documentation,
 * and is protected by intellectual property laws. All use of the
 * 3Dconnexion Software Developer Kit is subject to the License
 * Agreement found in the "LicenseAgreementSDK.txt" file.
 * All rights not expressly granted by 3Dconnexion are reserved.
 *
 */
#ifndef _V3DKey_H_
#define _V3DKey_H_

static char v3DKeyCvsId[]="(C) 2013-2015 3Dconnexion: $Id: V3DKey.h 11750 2015-09-08 13:58:59Z jwick $";

/*
 * Virtual 3D Keys
 *
 * Functions that refer to hardware keys use these constants to identify the keys.
 * These represent hardware buttons on devices that have them.
 * If a hardware device doesn't have a key, it won't produce the event.
 * Not all hardware devices have all keys but any key that does exist is
 * in this enum.  If new hardware keys are added in the future, a new constant will
 * be created for it.
 * 
 * SI_BUTTON_PRESS_EVENT and SI_BUTTON_RELEASE_EVENT events identify the hardware
 * keys that generated the events through V3DKeys (Virtual 3D Mouse Keys).
 * These will represent the actual hardware key pressed unless the user did 
 * something clever in his xml file.
 */
/* This enum is replicated in virtualkeys.hpp.  Reflect any changest there. */
typedef enum
{
   V3DK_INVALID     = 0,
   V3DK_MENU		= 1,
   V3DK_FIT			= 2,
   V3DK_TOP			= 3,
   V3DK_LEFT		= 4,
   V3DK_RIGHT		= 5,
   V3DK_FRONT		= 6,
   V3DK_BOTTOM		= 7,
   V3DK_BACK		= 8,
   V3DK_ROLL_CW		= 9,
   V3DK_ROLL_CCW	= 10,
   V3DK_ISO1		= 11,
   V3DK_ISO2		= 12,
   V3DK_1			= 13,
   V3DK_2			= 14,
   V3DK_3			= 15,
   V3DK_4			= 16,
   V3DK_5			= 17,
   V3DK_6			= 18,
   V3DK_7			= 19,
   V3DK_8			= 20,
   V3DK_9			= 21,
   V3DK_10			= 22,
   V3DK_ESC			= 23,
   V3DK_ALT			= 24,
   V3DK_SHIFT		= 25,
   V3DK_CTRL		= 26,
   V3DK_ROTATE		= 27,
   V3DK_PANZOOM		= 28,
   V3DK_DOMINANT	= 29,
   V3DK_PLUS		= 30,
   V3DK_MINUS		= 31,
   V3DK_SPIN_CW		= 32,
   V3DK_SPIN_CCW	= 33,
   V3DK_TILT_CW		= 34,
   V3DK_TILT_CCW	= 35,
   V3DK_ENTER		= 36,
   V3DK_DELETE		= 37,
   V3DK_RESERVED0	= 38,
   V3DK_RESERVED1	= 39,
   V3DK_RESERVED2	= 40,
   V3DK_F1			= 41,
   V3DK_F2			= 42,
   V3DK_F3			= 43,
   V3DK_F4			= 44,
   V3DK_F5			= 45,
   V3DK_F6			= 46,
   V3DK_F7			= 47,
   V3DK_F8			= 48,
   V3DK_F9			= 49,
   V3DK_F10			= 50,
   V3DK_F11			= 51,
   V3DK_F12			= 52,
   V3DK_F13			= 53,
   V3DK_F14			= 54,
   V3DK_F15			= 55,
   V3DK_F16			= 56,
   V3DK_F17			= 57,
   V3DK_F18			= 58,
   V3DK_F19			= 59,
   V3DK_F20			= 60,
   V3DK_F21			= 61,
   V3DK_F22			= 62,
   V3DK_F23			= 63,
   V3DK_F24			= 64,
   V3DK_F25			= 65,
   V3DK_F26			= 66,
   V3DK_F27			= 67,
   V3DK_F28			= 68,
   V3DK_F29			= 69,
   V3DK_F30			= 70,
   V3DK_F31			= 71,
   V3DK_F32			= 72,
   V3DK_F33			= 73,
   V3DK_F34			= 74,
   V3DK_F35			= 75,
   V3DK_F36			= 76,
   V3DK_11			= 77,
   V3DK_12			= 78,
   V3DK_13			= 79,
   V3DK_14			= 80,
   V3DK_15			= 81,
   V3DK_16			= 82,
   V3DK_17			= 83,
   V3DK_18			= 84,
   V3DK_19			= 85,
   V3DK_20			= 86,
   V3DK_21			= 87,
   V3DK_22			= 88,
   V3DK_23			= 89,
   V3DK_24			= 90,
   V3DK_25			= 91,
   V3DK_26			= 92,
   V3DK_27			= 93,
   V3DK_28			= 94,
   V3DK_29			= 95,
   V3DK_30			= 96,
   V3DK_31			= 97,
   V3DK_32			= 98,
   V3DK_33			= 99,
   V3DK_34			= 100,
   V3DK_35			= 101,
   V3DK_36			= 102,
   V3DK_VIEW_1		= 103,
   V3DK_VIEW_2		= 104,
   V3DK_VIEW_3		= 105,
   V3DK_VIEW_4		= 106,
   V3DK_VIEW_5		= 107,
   V3DK_VIEW_6		= 108,
   V3DK_VIEW_7		= 109,
   V3DK_VIEW_8		= 110,
   V3DK_VIEW_9		= 111,
   V3DK_VIEW_10		= 112,
   V3DK_VIEW_11		= 113,
   V3DK_VIEW_12		= 114,
   V3DK_VIEW_13		= 115,
   V3DK_VIEW_14		= 116,
   V3DK_VIEW_15		= 117,
   V3DK_VIEW_16		= 118,
   V3DK_VIEW_17		= 119,
   V3DK_VIEW_18		= 120,
   V3DK_VIEW_19		= 121,
   V3DK_VIEW_20		= 122,
   V3DK_VIEW_21		= 123,
   V3DK_VIEW_22		= 124,
   V3DK_VIEW_23		= 125,
   V3DK_VIEW_24		= 126,
   V3DK_VIEW_25		= 127,
   V3DK_VIEW_26		= 128,
   V3DK_VIEW_27		= 129,
   V3DK_VIEW_28		= 130,
   V3DK_VIEW_29		= 131,
   V3DK_VIEW_30		= 132,
   V3DK_VIEW_31		= 133,
   V3DK_VIEW_32		= 134,
   V3DK_VIEW_33		= 135,
   V3DK_VIEW_34		= 136,
   V3DK_VIEW_35		= 137,
   V3DK_VIEW_36		= 138,
   V3DK_SAVE_VIEW_1	= 139,
   V3DK_SAVE_VIEW_2	= 140,
   V3DK_SAVE_VIEW_3	= 141,
   V3DK_SAVE_VIEW_4	= 142,
   V3DK_SAVE_VIEW_5	= 143,
   V3DK_SAVE_VIEW_6	= 144,
   V3DK_SAVE_VIEW_7	= 145,
   V3DK_SAVE_VIEW_8	= 146,
   V3DK_SAVE_VIEW_9	= 147,
   V3DK_SAVE_VIEW_10= 148,
   V3DK_SAVE_VIEW_11= 149,
   V3DK_SAVE_VIEW_12= 150,
   V3DK_SAVE_VIEW_13= 151,
   V3DK_SAVE_VIEW_14= 152,
   V3DK_SAVE_VIEW_15= 153,
   V3DK_SAVE_VIEW_16= 154,
   V3DK_SAVE_VIEW_17= 155,
   V3DK_SAVE_VIEW_18= 156,
   V3DK_SAVE_VIEW_19= 157,
   V3DK_SAVE_VIEW_20= 158,
   V3DK_SAVE_VIEW_21= 159,
   V3DK_SAVE_VIEW_22= 160,
   V3DK_SAVE_VIEW_23= 161,
   V3DK_SAVE_VIEW_24= 162,
   V3DK_SAVE_VIEW_25= 163,
   V3DK_SAVE_VIEW_26= 164,
   V3DK_SAVE_VIEW_27= 165,
   V3DK_SAVE_VIEW_28= 166,
   V3DK_SAVE_VIEW_29= 167,
   V3DK_SAVE_VIEW_30= 168,
   V3DK_SAVE_VIEW_31= 169,
   V3DK_SAVE_VIEW_32= 170,
   V3DK_SAVE_VIEW_33= 171,
   V3DK_SAVE_VIEW_34= 172,
   V3DK_SAVE_VIEW_35= 173,
   V3DK_SAVE_VIEW_36= 174,
   V3DK_TAB			= 175,
   V3DK_SPACE		= 176,
   V3DK_MENU_1      = 177,
   V3DK_MENU_2      = 178,
   V3DK_MENU_3      = 179,
   V3DK_MENU_4      = 180,
   V3DK_MENU_5      = 181,
   V3DK_MENU_6      = 182,
   V3DK_MENU_7      = 183,
   V3DK_MENU_8      = 184,
   V3DK_MENU_9      = 185,
   V3DK_MENU_10     = 186,
   V3DK_MENU_11     = 187,
   V3DK_MENU_12     = 188,
   V3DK_MENU_13     = 189,
   V3DK_MENU_14     = 190,
   V3DK_MENU_15     = 191,
   V3DK_MENU_16     = 192,
   /* add more here as needed - don't change value of anything that may already be used */
   V3DK_USER        = 0x10000
} V3DKey;


#endif   /* _V3DKey_H_ */
