#pragma once
#include "math_func.h"

namespace shootingStar
{
	namespace math
	{
		class Vector4
		{
		public:
			Vector4();
			Vector4(float f);
			Vector4(float x, float y);
			Vector4(float x, float y, float z);
			Vector4(float x, float y, float z, float w);

		public:
			const Vector4		operator + () const;
			const Vector4		operator - () const;

			const Vector4		operator + (const Vector4& other) const;
			const Vector4		operator - (const Vector4& other) const;
			bool				operator == (const Vector4& other) const;
			bool				operator != (const Vector4& other) const;
			bool				operator <(const Vector4& other) const;
			bool				operator >(const Vector4& other) const;
			bool				operator <=(const Vector4& other) const;
			bool				operator >=(const Vector4& other) const;

			const Vector4		operator * (const float f) const;
			const Vector4		operator * (const Vector4& other) const;
			const Vector4		operator / (const float f) const;
			const Vector4		operator / (const Vector4& other) const;

			Vector4&			operator += (const Vector4& other);
			Vector4&			operator -= (const Vector4& other);
			Vector4&			operator *= (const Vector4& other);
			Vector4&			operator *= (float f);
			Vector4&			operator /= (float f);

			float				operator[](unsigned int idx) const;

			friend Vector4		operator+(float lhs, const Vector4& rhs) { return Vector4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w); }
			friend Vector4		operator-(float lhs, const Vector4& rhs) { return Vector4(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w); }
			friend Vector4		operator*(float lhs, const Vector4& rhs) { return Vector4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }
			friend Vector4		operator/(float lhs, const Vector4& rhs) { return Vector4(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w); }

		public:
			static const Vector4 One();
			static const Vector4 Zero();
			static const Vector4 UnitX();
			static const Vector4 UnitY();
			static const Vector4 UnitZ();
			static const Vector4 UnitW();

			static const Vector4 Abs(const Vector4& vec4);
			static const Vector4 Add(const Vector4& lhs, const Vector4& rhs);
			static const Vector4 Clamp(const Vector4& vec4, const Vector4& min, const Vector4& max);
			static const Vector4 CopyTo(float arr[]);
			static const Vector4 Lerp(const Vector4& from, const Vector4& to, float t);
			static const Vector4 Max(const Vector4& lhs, const Vector4& rhs);
			static const Vector4 Min(const Vector4& lhs, const Vector4& rhs);
			static const Vector4 Negate(const Vector4& vec4);
			static const Vector4 Normalize(const Vector4 &vec4);

		public:
			static float Distance(const Vector4& from, const Vector4& to);
			static float DistanceSquared(const Vector4& from, const Vector4& to);
			static float Length(const Vector4 &vec4);
			static float LengthSquared(const Vector4 &vec4);
			static float Dot(const Vector4& lhs, const Vector4& rhs);

		public:
			const Vector4 Normalized() const;
			void Set(float newX, float newY, float newZ, float newW);

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