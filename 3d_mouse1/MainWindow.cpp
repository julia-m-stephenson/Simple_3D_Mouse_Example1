//Simple Application to access 3D connexion events 
// Julia Stephensonson 2019
// This is based on the traditional Windows API so no .NET, MFC or ATL nonsense
// Guts of this based on the MS tutorial at
// https://docs.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=vs-2019
//

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables
#define JMS_NUM_IP_DEVICES 1 // Number of raw input devices we are using

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

HINSTANCE hInst;

//Event handling here 
//define first as refereenced by main 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");

	switch (message)
	{
	case WM_CREATE:
		{
			// first call to app ends here 
			// we'll register interest in 3d Mouse events 
			RAWINPUTDEVICE Rid[JMS_NUM_IP_DEVICES];

			Rid[0].usUsagePage = 0x01;
			Rid[0].usUsage = 0x08;// DMulti-axis controller
			Rid[0].dwFlags = 0x00;
			Rid[0].hwndTarget = 0;

			if (RegisterRawInputDevices(Rid, JMS_NUM_IP_DEVICES, sizeof(Rid[0])) == FALSE) {
				//registration failed. Call GetLastError for the cause of the error
			}
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, Windows desktop!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		// Do we need to de-register the mouse events?
		PostQuitMessage(0);
		break;
	case WM_INPUT: 
		{
			// Handle raw inputs here eventually
			// based on information in https://docs.microsoft.com/en-us/windows/win32/inputdev/using-raw-input
			UINT rawInputSize = sizeof(RAWINPUT);
			RAWINPUT rawInput;

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, &rawInput, &rawInputSize, sizeof(RAWINPUTHEADER));

			if (rawInput.header.dwType == RIM_TYPEHID)
			{
				char buffer[256];
				wsprintf(buffer, TEXT(" HID: dwSizeHid=%04x dwCount:%04x bRawData:%04x \n"),
					rawInput.data.hid.dwSizeHid,
					rawInput.data.hid.dwCount,
					rawInput.data.hid.bRawData[0]);
				OutputDebugString(buffer);

			}
			else
			{
				// ignore??
			}
		}

	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
// We always need a starting point 
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance;

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application dows not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}