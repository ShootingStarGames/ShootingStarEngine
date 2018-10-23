#pragma once
#include "../stdafx.h"
#include <chrono>

namespace shootingStar
{
	namespace core
	{
		using namespace std::chrono;

		typedef high_resolution_clock     clock;
		typedef duration<float, std::milli> fmillisecond;

		class Timer
		{
		private:
			time_point<clock> m_cStart;
			float m_fTimeScale;
		public:
			Timer();
			void Reset();
			float Elapsed();
			float ElapsedSeconds();
		};
	}
}