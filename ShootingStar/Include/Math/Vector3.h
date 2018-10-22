#pragma once
#include "../shootingStar.h"
#include "math_func.h"

namespace shootingStar
{
	namespace math
	{
		class Vector3
		{
		public:
			Vector3();
			Vector3(float f);
			Vector3(float x, float y);
			Vector3(float x, float y,float z);

		public:
			const Vector3		operator + () const;
			const Vector3		operator - () const;

			const Vector3		operator + (const Vector3& other) const;
			const Vector3		operator - (const Vector3& other) const;
			bool				operator == (const Vector3& other) const;
			bool				operator != (const Vector3& other) const;

			bool				operator <(const Vector3& other) const;
			bool				operator >(const Vector3& other) const;
			bool				operator <=(const Vector3& other) const;
			bool				operator >=(const Vector3& other) const;

			const Vector3		operator * (const float f) const;
			const Vector3		operator * (const Vector3& other) const;
			const Vector3		operator / (const float f) const;
			const Vector3		operator / (const Vector3& other) const;

			Vector3&			operator += (const Vector3& other);
			Vector3&			operator -= (const Vector3& other);
			Vector3&			operator *= (const Vector3& other);
			Vector3&			operator *= (float f);
			Vector3&			operator /= (float f);

			float				operator[](unsigned int idx) const;

			friend Vector3		operator+(float lhs, const Vector3& rhs) { return Vector3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z); }
			friend Vector3		operator-(float lhs, const Vector3& rhs) { return Vector3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z); }
			friend Vector3		operator*(float lhs, const Vector3& rhs) { return Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }
			friend Vector3		operator/(float lhs, const Vector3& rhs) { return Vector3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z); }

		public:
			static const Vector3 One();
			static const Vector3 Zero();
			static const Vector3 UnitX();
			static const Vector3 UnitY();
			static const Vector3 UnitZ();
			static const Vector3 Up();
			static const Vector3 Down();
			static const Vector3 Left();
			static const Vector3 Right();
			static const Vector3 Foward();
			static const Vector3 Back();

			static const Vector3 Abs(const Vector3& vec3);
			static const Vector3 Add(const Vector3& lhs, const Vector3& rhs);
			static const Vector3 Clamp(const Vector3& vec3, const Vector3& min, const Vector3& max);
			static const Vector3 CopyTo(float arr[]);
			static const Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
			static const Vector3 Lerp(const Vector3& from, const Vector3& to, float t);
			static const Vector3 Max(const Vector3& lhs, const Vector3& rhs);
			static const Vector3 Min(const Vector3& lhs, const Vector3& rhs);
			static const Vector3 Negate(const Vector3& vec3);
			static const Vector3 Project(const Vector3& vec3, const Vector3& axisVector);
			static const Vector3 Reflect(Vector3& dir, const Vector3& normal);
			static const Vector3 Normalize(const Vector3 &vec3);

		public:
			static float Distance(const Vector3& from, const Vector3& to);
			static float DistanceSquared(const Vector3& from, const Vector3& to);
			static float Length(const Vector3 &vec3);
			static float LengthSquared(const Vector3 &vec3);
			static float Dot(const Vector3& lhs, const Vector3& rhs);

		public:
			const Vector3 Project(const Vector3& axisVector);
			const Vector3 Reflect(const Vector3& normal);
			const Vector3 Normalized() const;
			void Set(float newX, float newY, float newZ);

		public:
			union
			{
				struct
				{
					float x, y, z;
				};

				float value[3] = { 0.0f };
			};
		};
	}
}