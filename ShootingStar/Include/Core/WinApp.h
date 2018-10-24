#pragma once
#include "../Common.h"
#include "../resource.h"
#include "../Math/SMath.h"

namespace shootingStar {
	namespace core
	{
		struct WndDesc
		{
			math::Rectangle rect;
			HINSTANCE		instance = NULL;
			std::wstring	title = L"ShootingStarEngine";
			DWORD			dwStyle = WS_OVERLAPPED;
			HWND			parentHandle = NULL;

			WndDesc() = default;
		};
		class WinApp
		{
		public:
			WinApp(const WndDesc& wndDesc);

		public:
			void Update();

		private:
			static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		
		private:
			BOOL Initialize();
			void Destroy();

		private:
			math::Rectangle	m_rect;
			WNDCLASSEX		m_windowInfo;
			HINSTANCE		m_hInstance;
			std::wstring	m_sTitle;
			HWND			m_hParent;
			HWND			m_hWnd;
			DWORD			m_dwStyle;

		private:
			bool		m_closed;
		};


	}
}