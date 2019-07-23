// Information from this section comes mainly from virtualkeys.hpp in the 
// 
#include "V3DKey.h"
//
//VID: 0x046D  Logitech (3Dconnexion was a subsidiary)
//  PID: 0xC627://SpaceExplorer
static const V3DKey spaceExplorerKeys [] = 
{
  V3DK_INVALID,
  V3DK_1,
  V3DK_2,
  V3DK_TOP,
  V3DK_LEFT,
  V3DK_RIGHT,
  V3DK_FRONT,
  V3DK_ESC,
  V3DK_ALT,
  V3DK_SHIFT,
  V3DK_CTRL,
  V3DK_FIT,
  V3DK_MENU,
  V3DK_PLUS,
  V3DK_MINUS,
  V3DK_ROTATE
};
//VID: 0x046D  Logitech (3Dconnexion was a subsidiary)
//  PID: 0xC625:
static const V3DKey spacePilotKeys [] = 
{
  V3DK_INVALID,
  V3DK_1,
  V3DK_2,
  V3DK_3,
  V3DK_4,
  V3DK_5,
  V3DK_6,
  V3DK_TOP,
  V3DK_LEFT,
  V3DK_RIGHT,
  V3DK_FRONT,
  V3DK_ESC,
  V3DK_ALT,
  V3DK_SHIFT,
  V3DK_CTRL,
  V3DK_FIT,
  V3DK_MENU,
  V3DK_PLUS,
  V3DK_MINUS,
  V3DK_DOMINANT,
  V3DK_ROTATE,
  (V3DKey)(V3DK_USER+0x01)
};
//VID: 0x046D  Logitech (3Dconnexion was a subsidiary)
//  PID: 0xC626: full-size SpaceNavigator
//  PID: 0xC628: the "for Notebooks" SpaceNavigator
static const V3DKey spaceNavigatorKeys [] = 
{
  V3DK_INVALID,
  V3DK_MENU,
  V3DK_FIT
};
// shared by the latest 3Dconnexion hardware
// SpacePilotPro uses all of these
// smaller devices use only some,based on button mask
//VID: 0x256F  3Dconnexion
//  PID: 0xC62E: SpaceMouse plugged in
//  PID: 0xC62F: SpaceMouse wireless
//  PID: 0xC631: SpaceMouse Pro plugged in
//  PID: 0xC632: SpaceMouse Pro wireless
//  PID: 0xC633: SpaceMouse Enterprise
//VID: 0x046D  Logitech (3Dconnexion was a subsidiary)
//  PID: 0xC629: SpacePilot Pro
static const V3DKey spacePilotProKeys [] = 
{
  V3DK_INVALID,
  V3DK_MENU,
  V3DK_FIT,
  V3DK_TOP,
  V3DK_LEFT,
  V3DK_RIGHT,
  V3DK_FRONT,
  V3DK_BOTTOM,
  V3DK_BACK,
  V3DK_ROLL_CW,
  V3DK_ROLL_CCW,
  V3DK_ISO1,
  V3DK_ISO2,
  V3DK_1,
  V3DK_2,
  V3DK_3,
  V3DK_4,
  V3DK_5,
  V3DK_6,
  V3DK_7,
  V3DK_8,
  V3DK_9,
  V3DK_10,
  V3DK_ESC,
  V3DK_ALT,
  V3DK_SHIFT,
  V3DK_CTRL,
  V3DK_ROTATE,
  V3DK_PANZOOM,
  V3DK_DOMINANT,
  V3DK_PLUS,
  V3DK_MINUS
};
//VID: 0x046D  Logitech (3Dconnexion was a subsidiary)
//  PID: 0xC62B: SpaceMouse Pro
static const V3DKey spaceMouseProKeys [] = 
{                      
  V3DK_INVALID,      
  V3DK_MENU,
  V3DK_FIT,
  V3DK_TOP,
  V3DK_INVALID,
  V3DK_RIGHT,
  V3DK_FRONT,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_ROLL_CW,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_1,
  V3DK_2,
  V3DK_3,
  V3DK_4,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_INVALID,
  V3DK_ESC,
  V3DK_ALT,
  V3DK_SHIFT,
  V3DK_CTRL,
  V3DK_ROTATE
};

