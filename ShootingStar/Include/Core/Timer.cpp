#include "../stdafx.h"
#include "Timer.h"

namespace shootingStar
{
	namespace core
	{
		Timer::Timer()
		{
			Reset();
		}
		void Timer::Reset()
		{
			m_cStart = clock::now();
			m_fTimeScale = 1.f;
		}
		float Timer::Elapsed() // ElapsedTime Milli Second
		{
			return duration_cast<fmillisecond>(clock::now() - m_cStart).count()* m_fTimeScale;;
		}
		float Timer::ElapsedSeconds() // ElapsedTime Second
		{
			return Elapsed() * 1000.0f* m_fTimeScale;;
		}
	}
}
 