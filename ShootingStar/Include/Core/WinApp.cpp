#include "stdafx.h"
#include "WinApp.h"


namespace shootingStar {
	namespace core
	{
		WinApp::WinApp(const WndDesc & wndDesc)
		{
			m_rect = wndDesc.rect;
			m_hInstance = wndDesc.instance;
			m_sTitle = wndDesc.title;
			m_dwStyle = wndDesc.dwStyle;
			m_hParent = wndDesc.parentHandle;


			Initialize();
		}
		LRESULT WinApp::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			switch (msg)
			{
			case WM_CLOSE:
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			}
			return DefWindowProc(hWnd, msg, wParam, lParam);;
		}
		BOOL WinApp::Initialize()
		{
			m_windowInfo.cbSize = sizeof(WNDCLASSEXW);
			m_windowInfo.style = CS_HREDRAW | CS_VREDRAW;
			m_windowInfo.lpfnWndProc = WinApp::WndProc;
			m_windowInfo.cbClsExtra = 0;
			m_windowInfo.cbWndExtra = 0;
			m_windowInfo.hInstance = m_hInstance;
			m_windowInfo.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_ICON1));
			m_windowInfo.hCursor = LoadCursor(nullptr, IDC_ARROW);
			m_windowInfo.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			m_windowInfo.lpszMenuName = NULL;
			m_windowInfo.lpszClassName = m_sTitle.c_str();
			m_windowInfo.hIconSm = LoadIcon(m_windowInfo.hInstance, MAKEINTRESOURCE(IDI_ICON1));

			RegisterClassEx(&m_windowInfo);

			m_hWnd = CreateWindowW(m_windowInfo.lpszClassName, m_windowInfo.lpszClassName,
				WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInstance, nullptr);

			if (!m_hWnd)
			{
				return FALSE;
			}

			RECT rc = { 0,0, m_rect.width, m_rect.height };
			AdjustWindowRect(&rc, m_dwStyle, FALSE);

			SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left,
				rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

			ShowWindow(m_hWnd, SW_SHOW);
			UpdateWindow(m_hWnd);

			m_closed = false;
			return TRUE;
		}
		void WinApp::Destroy()
		{
			UnregisterClass(m_windowInfo.lpszClassName, m_windowInfo.hInstance);

			DestroyWindow(m_hWnd);
		}
	}
}