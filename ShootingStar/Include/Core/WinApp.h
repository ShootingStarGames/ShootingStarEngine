#pragma once
#include "../shootingStar.h"
#include "../Common.h"
#include "../Math/SMath.h"

namespace shootingStar {
	namespace Core
	{
		class WinApp
		{
		public:
			struct Desc
			{
				math::Rectangle rect;
				std::string		name = "ShootingStarEngine";
				bool			windowMode = false;
				bool			isChild = false;
				HWND			parentHandle = NULL;

				Desc() = default;
			};

		public:
			WinApp(const Desc& desc);

		private:
			static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		
		private:
			void Initialize();
			void Destroy();

		private:
			math::Rectangle	_rect;
			WNDCLASSEX	_windowInfo;
			HWND		_parentHandle;
			HWND		_handle;
			uint		_options;
			bool		_windowsMode;
		};


	}
}