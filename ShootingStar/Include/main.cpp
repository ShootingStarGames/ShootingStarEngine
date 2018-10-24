#include "stdafx.h"
#include "Core/WinApp.h"
#include "Core/Engine.h"

using namespace shootingStar;
using namespace core;
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPreInstance,
	_In_ LPWSTR		lpCmdLine,
	_In_ int		nCmdShow)
{
	WndDesc desc;
	{
		desc.rect = math::Rectangle(0, 0, 800, 600);
		desc.instance = hInstance;
		desc.title = L"ShootingStarEngine";
		desc.dwStyle = WS_OVERLAPPED;
		desc.parentHandle = NULL;
	}

	Engine engine(desc);

	engine.Run();
	return 0;
}
