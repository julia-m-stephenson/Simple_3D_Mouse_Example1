// Information from this section comes mainly from virtualkeys.hpp in the 
// 
#include "V3DKey.h"
//
//    case 0x046D:  // Logitech (3Dconnexion was a subsidiary)
//        case 0xC627://SpaceExplorer
// 0xc627
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
//    case 0x046D:  // Logitech (3Dconnexion was a subsidiary)
//        case 0xC625:
//0xc625
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
//    case 0x046D:  // Logitech (3Dconnexion was a subsidiary)
//      switch (product_id) {
        // -- current devices --
//        case 0xC626:  // full-size SpaceNavigator
//        case 0xC628:  // the "for Notebooks" SpaceNavigator
// 0xc626
// 0xc628
static const V3DKey spaceNavigatorKeys [] = 
{
  V3DK_INVALID,
  V3DK_MENU,
  V3DK_FIT
};
//  0xc629
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
//0xc62b
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

// This comes from blender source file GHOST_NDOFManager.cpp
// shared by the latest 3Dconnexion hardware
// SpacePilotPro uses all of these
// smaller devices use only some,based on button mask
//    case 0x256F:  // 3Dconnexion
//        case 0xC62E:  // SpaceMouse plugged in
//        case 0xC62F:  // SpaceMouse wireless
//        case 0xC631:  // SpaceMouse Pro plugged in
//        case 0xC632:  // SpaceMouse Pro wireless
//        case 0xC633:  // SpaceMouse Enterprise
//    case 0x046D:  // Logitech (3Dconnexion was a subsidiary)
//      switch (product_id) {
//        // -- current devices --
//        case 0xC626:  // full-size SpaceNavigator
//        case 0xC628:  // the "for Notebooks" SpaceNavigator
//        case 0xC629:  // SpacePilot Pro
//        case 0xC62B:  // SpaceMouse Pro


static const V3DKey spaceModern[] = {
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
