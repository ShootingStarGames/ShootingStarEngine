#pragma once
#include "../shootingStar.h"
#include "math_func.h"
#include "Vector3.h"
#include "Matrix4x4.h"


namespace shootingStar
{
	namespace math
	{
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

			friend Quaternion	operator*(const Quaternion& lhs, const Quaternion& rhs)
			{
				return Quaternion(
					lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
					lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
					lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x,
					lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
			}
			friend Vector3	operator*(const Quaternion& rotation, const Vector3& point)
			{
				float x = rotation.x * 2.0f;
				float y = rotation.y * 2.0f;
				float z = rotation.z * 2.0f;
				float xx = rotation.x * x;
				float yy = rotation.y * y;
				float zz = rotation.z * z;
				float xy = rotation.x * y;
				float xz = rotation.x * z;
				float yz = rotation.y * z;
				float wx = rotation.w * x;
				float wy = rotation.w * y;
				float wz = rotation.w * z;
				Vector3 res;
				res.x = (1.0f - (yy + zz)) * point.x + (xy - wz) * point.y + (xz + wy) * point.z;
				res.y = (xy + wz) * point.x + (1.0f - (xx + zz)) * point.y + (yz - wx) * point.z;
				res.z = (xz - wy) * point.x + (yz + wx) * point.y + (1.0f - (xx + yy)) * point.z;
				return res;
			}

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
			void SetLookRotation(Vector3 view);
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