#include "../stdafx.h"
#include "Timer.h"

namespace shootingStar
{
	namespace core
	{
		bool Timer::Reset()
		{
			QueryPerformanceFrequency(&m_tSecond);
			QueryPerformanceCounter(&m_tTime);

			m_fDeltaTime = 0.f;

			return true;
		}
		void Timer::Update()
		{
			LARGE_INTEGER tTime;
			QueryPerformanceCounter(&tTime);

			m_fDeltaTime = (tTime.QuadPart - m_tTime.QuadPart) / (float)m_tSecond.QuadPart;

			m_tTime = tTime;
		}
	}
}
 