#pragma once
#include "math_func.h"
#include "Vector3.h"
namespace shootingStar
{
	namespace math
	{
		class Vector3;

		class Quaternion
		{
		public:
			Quaternion() = default;
			Quaternion(float x, float y, float z, float w);


		public:
			const Quaternion		operator + () const;
			const Quaternion		operator - () const;
			const Quaternion		operator * (const Quaternion& other) const;
			const Quaternion		operator * (const float f) const;
			const Quaternion		operator / (const float f) const;

			bool					operator == (const Quaternion& other);
			bool					operator != (const Quaternion& other);

			Quaternion&			operator *= (const Quaternion& other);

			float				operator[](unsigned int idx) const;

		public:
			static float			Dot(const Quaternion& lhs, const Quaternion& rhs);
			static float			Angle(const Quaternion& lhs, const Quaternion& rhs);
			static const Quaternion Slerp(const Quaternion& from, const Quaternion& to, float t);
			static const Quaternion Lerp(const Quaternion& from, const Quaternion& to, float t);
			static const Quaternion FromYawPitchRoll(float yaw, float pitch, float roll);
			static const Quaternion	FromAxis(const Vector3& axis, float angle);
			static const Quaternion Identity();
			static const Quaternion Eular(float x, float y, float z);
		private:
			static bool IsEqualUsingDot(float dot)
			{
				return dot > 1.0f - kEpsilon;
			}

		public:
			void Set(float newX, float newY, float newZ, float newW);
			const Quaternion Normalized() const;
			const Quaternion Inversed() const;
			const Quaternion Conjugate() const;

		public:
			union
			{
				struct
				{
					float x, y, z, w;
				};

				float value[4] = { 0.0f };
			};
		};
	}
}