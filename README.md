# Simple_3D_Mouse_Example
This project provides the bare minimum example of getting input from a 3D Connexions 3D Mouse,

This will hopefully support all products from 3D Connexions.

Written with the low-level (oldest) Windows API so no MFC, .NET, AFC etc required just the plain old windows API.

Happy for this to be used commercially but please credit me if you've copied code.

Solution developed using Microsoft Visual Studio 2015 Community Edition as its free :-)

Disclaimer: I cobbled this together in my free time. I normally do embedded software in C so GUI stuff in C++ isn't really my thang.....

References:
Basic Windows Application Layout is based on the MS tutorial at 
https://docs.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=vs-2019
Accessing Raw Input detail came from here:-
https://docs.microsoft.com/en-us/windows/win32/inputdev/using-raw-input
The layout of motion data in the window has been lifted from the current 3DxWare_SDK 3DxTest demo provided by 3D Connexions.
Most of the information (but no tthe code) has come from their very early S3DM_SDK_v2-0-4_r7688_raw_input - s3dm_viewer sample code.
A great deal of insight came from looking at the Source of Blender App:-
https://git.blender.org/gitweb/gitweb.cgi/blender.git/blob/HEAD:/intern/ghost/intern/GHOST_NDOFManager.cpp

Things left to do:-

* Add scaling like blender e.g 1/350? So full scale is something like 100% 
* add deadzone
* Add key maps 3d connections see info in virtualkeyss.hpp (3d Connexions)
* change to trace functions for output?
* change to floats?
* zero event????


Julia Stephenson
