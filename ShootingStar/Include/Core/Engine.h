#pragma once

namespace shootingStar
{
	namespace core
	{
		class WinApp;
		struct WndDesc;

		class Engine
		{
		public:
			Engine(const WndDesc& wndDesc);
			~Engine();

			int Run();
		private:
			WinApp * winApp;
			bool m_bLoop;
		};
	}
}
