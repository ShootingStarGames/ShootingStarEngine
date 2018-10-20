#include "Vector2.h"
 
namespace shootingStar
{
	namespace math
	{
		Vector2::Vector2(float f) : x(f), y(f)
		{
		}

		Vector2::Vector2(float x, float y) : x(x), y(y)
		{
		}

		const Vector2 Vector2::operator+() const
		{
			return (*this);
		}

		const Vector2 Vector2::operator-() const
		{
			return Vector2(-x, -y);
		}

		const Vector2 Vector2::operator+(const Vector2 & other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		const Vector2 Vector2::operator-(const Vector2 & other) const
		{
			return Vector2(x - other.x, y - other.y);
		}

		bool Vector2::operator==(const Vector2 & other)
		{
			return (fabsf(x - other.x) < FLT_EPSILON) & (fabsf(y - other.y) < FLT_EPSILON);
		}

		bool Vector2::operator!=(const Vector2 & other)
		{
			return !Vector2::operator==(other);
		}

		const Vector2 Vector2::operator*(const float f) const
		{
			return  Vector2(x * f, y * f);
		}

		const Vector2 Vector2::operator*(const Vector2 & other) const
		{
			return  Vector2(x * other.x, y * other.y);
		}

		const Vector2 Vector2::operator/(const float f) const
		{
			return  Vector2(x / f, y / f);
		}

		const Vector2 Vector2::operator/(const Vector2 & other) const
		{
			return Vector2(x / other.x, y / other.y);
		}

		Vector2 & Vector2::operator+=(const Vector2 & other)
		{
			x += other.x;
			y += other.y;
			return (*this);
		}

		Vector2 & Vector2::operator-=(const Vector2 & other)
		{
			x -= other.x;
			y -= other.y;
			return (*this);
		}

		Vector2 & Vector2::operator*=(const Vector2 & other)
		{
			x *= other.x;
			y *= other.y;
			return (*this);
		}

		Vector2 & Vector2::operator*=(float f)
		{
			x *= f;
			y *= f;
			return (*this);
		}

		Vector2 & Vector2::operator/=(float f)
		{
			return operator*=(1.0f / f);
		}

		float Vector2::operator[](unsigned int idx) const
		{
			return value[idx];
		}

		const Vector2 Vector2::One()
		{
			return Vector2(1, 1);
		}

		const Vector2 Vector2::Zero()
		{
			return Vector2(0, 0);
		}

		const Vector2 Vector2::UnitX()
		{
			return Vector2(1, 0);
		}

		const Vector2 Vector2::UnitY()
		{
			return Vector2(0, 1);
		}

		const Vector2 Vector2::Abs(const Vector2 & vec2)
		{
			float x = vec2.x >= 0 ? vec2.x : -vec2.x;
			float y = vec2.y >= 0 ? vec2.y : -vec2.y;

			return Vector2(x, y);
		}

		const Vector2 Vector2::Add(const Vector2 & lhs, const Vector2 & rhs)
		{
			return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
		}

		const Vector2 Vector2::Clamp(const Vector2& vec2, const Vector2& min, const Vector2& max)
		{
			float x = vec2.x < min.x ? min.x : vec2.x;
			float y = vec2.y < min.y ? min.y : vec2.y;
			return Vector2(x > max.x ? max.x : x, y > max.y ? max.y : y);
		}

		const Vector2 Vector2::CopyTo(float arr[])
		{
			return Vector2(arr[0], arr[1]);
		}

		const Vector2 Vector2::Lerp(const Vector2 & from, const Vector2 & to, float t)
		{
			Vector2 v = to - from;

			return v * t;
		}

		const Vector2 Vector2::Max(const Vector2 & lhs, const Vector2 & rhs)
		{
			float x = lhs.x < rhs.x ? rhs.x : lhs.x;
			float y = lhs.y < rhs.y ? rhs.y : lhs.y;
			return Vector2(x, y);
		}

		const Vector2 Vector2::Min(const Vector2 & lhs, const Vector2 & rhs)
		{
			float x = lhs.x > rhs.x ? rhs.x : lhs.x;
			float y = lhs.y > rhs.y ? rhs.y : lhs.y;
			return Vector2(x, y);
		}

		const Vector2 Vector2::Negate(const Vector2 & vec2)
		{
			return -vec2;
		}

		const Vector2 Vector2::Project(const Vector2 & vec2, const Vector2 & axisVector)
		{
			float sqrMag = Vector2::Dot(axisVector, vec2);
			if (sqrMag < FLT_EPSILON)
				return Zero();

			return axisVector * Dot(vec2, axisVector) / sqrMag;
		}

		const Vector2 Vector2::Reflect(Vector2 & dir, const Vector2 & normal)
		{
			return -2.0f * Dot(normal, dir) * normal + dir;
		}

		const Vector2 Vector2::Normalize(const Vector2 &vec2)
		{
			float v = Vector2::Length(vec2);
			if (v < FLT_EPSILON)
				return Zero();
			return vec2 / v;
		}

		float Vector2::Distance(const Vector2 & from, const Vector2 & to)
		{
			float sx = (to.x - from.x);
			float sy = (to.y - from.y);

			return sqrtf(sx * sx + sy * sy);
		}

		float Vector2::DistanceSquared(const Vector2 & from, const Vector2 & to)
		{
			float sx = (to.x - from.x) * (to.x - from.x);
			float sy = (to.y - from.y) * (to.y - from.y);
			return sx + sy;
		}

		float Vector2::Length(const Vector2 &vec2)
		{
			return sqrtf((vec2.x * vec2.x) + (vec2.y + vec2.y));
		}

		float Vector2::LengthSquared(const Vector2 &vec2)
		{
			return (vec2.x * vec2.x) + (vec2.y + vec2.y);
		}

		float Vector2::Dot(const Vector2 & lhs, const Vector2 & rhs)
		{
			return (lhs.x * rhs.x) + (lhs.y * rhs.y);
		}

		const Vector2 Vector2::Project(const Vector2 & axisVector)
		{
			float sqrMag = Vector2::Dot(axisVector, *this);
			if (sqrMag < FLT_EPSILON)
				return Zero();

			return axisVector * Dot(*this, axisVector) / sqrMag;
		}

		const Vector2 Vector2::Reflect(const Vector2 & normal)
		{
			return -2.0f * Dot(normal, (*this)) * normal + (*this);
		}

		const Vector2 Vector2::Normalized() const
		{
			return Vector2::Normalize(*this);
		}

		void Vector2::Set(float newX, float newY)
		{
			x = newX;
			y = newY;
		}

	}
}
