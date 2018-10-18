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
			return Vector2(0,0);
		}

		const Vector2 Vector2::UnitX()
		{
			return Vector2(1,0);
		}

		const Vector2 Vector2::UnitY()
		{
			return Vector2(0,1);
		}

		const Vector2 Vector2::Abs(const Vector2 & vector2)
		{
			float x = vector2.x >= 0 ? vector2.x : -vector2.x;
			float y = vector2.y >= 0 ? vector2.y : -vector2.y;

			return Vector2(x, y);
		}

		const Vector2 Vector2::Add(const Vector2 & left, const Vector2 & right)
		{
			return Vector2(left.x + right.x, left.y + right.y);
		}

		const Vector2 Vector2::Clamp(const Vector2& vector, const Vector2& min, const Vector2& max)
		{
			float x = (vector.x < min.x ? min.x : vector.x);
			float y = vector.y < min.y ? min.y : vector.y;
			return Vector2(x > max.x ? max.x : x, y > max.y ? max.y : y );
		}

		const Vector2 Vector2::CopyTo(float arr[])
		{
			return Vector2(arr[0], arr[1]);
		}

		float Vector2::Distance(const Vector2 & from, const Vector2 & to)
		{
			float sx = (to.x - from.x) * (to.x - from.x);
			float sy = (to.y - from.y) * (to.y - from.y);
			return sqrtf(sx + sy);
		}

		float Vector2::DistanceSquared(const Vector2 & from, const Vector2 & to)
		{
			float sx = (to.x - from.x) * (to.x - from.x);
			float sy = (to.y - from.y) * (to.y - from.y);
			return sx + sy;
		}

		float Vector2::Length(const Vector2 &vector)
		{
			return sqrtf((vector.x * vector.x) + (vector.y + vector.y));
		}

		float Vector2::LengthSquared(const Vector2 &vector)
		{
			return (vector.x * vector.x) + (vector.y + vector.y);
		}

		const Vector2 Vector2::Lerp(const Vector2 & from, const Vector2 & to, float t)
		{
			Vector2 v = to - from;

			return v * t;
		}

		const Vector2 Vector2::Max(const Vector2 & left, const Vector2 & right)
		{
			float x = left.x < right.x ? right.x : left.x;
			float y = left.y < right.y ? right.y : left.y;
			return Vector2(x, y);
		}

		const Vector2 Vector2::Min(const Vector2 & left, const Vector2 & right)
		{
			float x = left.x > right.x ? right.x : left.x;
			float y = left.y > right.y ? right.y : left.y;
			return Vector2(x, y);
		}

		const Vector2 Vector2::Negate(const Vector2 & vector2)
		{
			return -vector2;
		}

		const Vector2 Vector2::Reflect(Vector2 & dir, const Vector2 & normal)
		{
			Vector2 proj = dir.Project(normal);

			return (dir - 2 * proj).Normalized();
		}

		float Vector2::Dot(const Vector2 & left, const Vector2 & right)
		{
			return (left.x * right.x) + (left.y * right.y);
		}

		const Vector2 Vector2::Normalized(const Vector2 &vector)
		{
			float v = Vector2::Length(vector);
			return vector / v;
		}

		const Vector2 Vector2::Project(const Vector2 & vector2)
		{
			Vector2 v = vector2.Normalized();
			return v * Vector2::Dot(v, *this);
		}

		const Vector2 Vector2::Normalized() const
		{
			return Vector2::Normalized(*this);
		}

	}
}
