#include "stdafx.h"
#include "Engine.h"
#include "WinApp.h"

namespace shootingStar
{
	namespace core
	{
		Engine::Engine(const WndDesc & wndDesc)
		{
			winApp = new WinApp(wndDesc);
			m_bLoop = true;
		}
		Engine::~Engine()
		{
			delete winApp;
			winApp = nullptr;
		}
		int Engine::Run()
		{
			MSG msg;
			ZeroMemory(&msg, sizeof(msg));

			while ((msg.message != WM_QUIT) & m_bLoop)
			{
				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					//Engine.Run;
				}
			}

			return 1;
		}
	}
}