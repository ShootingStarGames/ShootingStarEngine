#pragma once

namespace shootingStar
{
	namespace core
	{
		class Timer
		{
		private:
			LARGE_INTEGER m_tSecond;
			LARGE_INTEGER m_tTime;
			float		m_fDeltaTime;
			float		m_fTimeScale;

		public:
			float GetDeltaTime()	const
			{
				return m_fDeltaTime * m_fTimeScale;
			}

			float GetTimeScale() const
			{
				return m_fTimeScale;
			}

		public:
			void SetTimeScale(float fTimeScale)
			{
				m_fTimeScale = fTimeScale;
			}
		public:
			bool Reset();
			void Update();
		};

	}
}