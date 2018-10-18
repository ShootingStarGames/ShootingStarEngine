#pragma once
#include "../shootingStar.h"

namespace shootingStar
{
	namespace math
	{
		class Vector2
		{
		public:
			Vector2() = default;
			Vector2(float f);
			Vector2(float x, float y);

		public:
			const Vector2 operator + () const;
			const Vector2 operator - () const;

			const Vector2 operator + (const Vector2& other) const;
			const Vector2 operator - (const Vector2& other) const;
			bool operator == (const Vector2& other);
			bool operator != (const Vector2& other);
			
			const Vector2 operator * (const float f) const;
			const Vector2 operator * (const Vector2& other) const;
			const Vector2 operator / (const float f) const;
			const Vector2 operator / (const Vector2& other) const;

			Vector2& operator += (const Vector2& other);
			Vector2& operator -= (const Vector2& other);
			Vector2& operator *= (const Vector2& other);
			Vector2& operator *= (float f);
			Vector2& operator /= (float f);

			float operator[](unsigned int idx) const;

			friend Vector2 operator+(float left, const Vector2& right) { return Vector2(left + right.x, left + right.y); }
			friend Vector2 operator-(float left, const Vector2& right) { return Vector2(left - right.x, left - right.y); }
			friend Vector2 operator*(float left, const Vector2& right) { return Vector2(left * right.x, left * right.y); }
			friend Vector2 operator/(float left, const Vector2& right) { return Vector2(left / right.x, left / right.y); }

		public:
			static const Vector2 One();
			static const Vector2 Zero();
			static const Vector2 UnitX();
			static const Vector2 UnitY();
			static const Vector2 Abs(const Vector2& vector2);
			static const Vector2 Add(const Vector2& left, const Vector2& right);
			static const Vector2 Clamp(const Vector2& vector, const Vector2& min, const Vector2& max);
			static const Vector2 CopyTo(float arr[]);
			static float Distance(const Vector2& from, const Vector2& to);
			static float DistanceSquared(const Vector2& from, const Vector2& to);
			static float Length(const Vector2 &vector);
			static float LengthSquared(const Vector2 &vector);
			static const Vector2 Lerp(const Vector2& from, const Vector2& to, float t);
			static const Vector2 Max(const Vector2& left, const Vector2& right);
			static const Vector2 Min(const Vector2& left, const Vector2& right);
			static const Vector2 Negate(const Vector2& vector2);
			static const Vector2 Reflect(Vector2& dir, const Vector2& normal);
			static float Dot(const Vector2& left, const Vector2& right);
			static const Vector2 Normalized(const Vector2 &vector);

		public:
			const Vector2 Project(const Vector2& vector2);
			const Vector2 Normalized() const;
		public:
			union
			{
				struct
				{
					float x, y;
				};

				float value[2] = { 0.0f };
			};
		};
	}
}