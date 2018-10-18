#include "Vector4.h"

namespace shootingStar
{
	namespace math
	{
		Vector4::Vector4(float f) : x(f), y(f), z(f)
		{
		}
		Vector4::Vector4(float x, float y) : x(x), y(y), z(0)
		{
		}
		Vector4::Vector4(float x, float y, float z) : x(x), y(y), z(z)
		{
		}
		Vector4::Vector4(float x, float y, float z) : x(x), y(y), z(z), w(w)
		{
		}
		const Vector4 Vector4::operator+() const
		{
			return (*this);
		}
		const Vector4 Vector4::operator-() const
		{
			return Vector4(-x, -y, -z, -w);
		}
		const Vector4 Vector4::operator+(const Vector4 & other) const
		{
			return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}
		const Vector4 Vector4::operator-(const Vector4 & other) const
		{
			return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
		}
		bool Vector4::operator==(const Vector4 & other)
		{
			return 
				(fabsf(x - other.x) < FLT_EPSILON)	& 
				(fabsf(y - other.y) < FLT_EPSILON)	& 
				(fabsf(z - other.z) < FLT_EPSILON)	& 
				(fabsf(w - other.w) < FLT_EPSILON);
		}
		bool Vector4::operator!=(const Vector4 & other)
		{
			return !Vector4::operator==(other);
		}
		const Vector4 Vector4::operator*(const float f) const
		{
			return Vector4(x * f, y * f, z * f, w * f);
		}
		const Vector4 Vector4::operator*(const Vector4 & other) const
		{
			return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
		}
		const Vector4 Vector4::operator/(const float f) const
		{
			return  Vector4(x / f, y / f, z / f, w / f);
		}
		const Vector4 Vector4::operator/(const Vector4 & other) const
		{
			return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
		}
		Vector4 & Vector4::operator+=(const Vector4 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return (*this);
		}
		Vector4 & Vector4::operator-=(const Vector4 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return (*this);
		}
		Vector4 & Vector4::operator*=(const Vector4 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			
			return (*this);
		}
		Vector4 & Vector4::operator*=(float f)
		{
			x *= f;
			y *= f;
			z *= f;
			w *= f;
			
			return (*this);
		}
		Vector4 & Vector4::operator/=(float f)
		{
			x /= f;
			y /= f;
			z /= f;
			w /= f;

			return (*this);
		}
		float Vector4::operator[](unsigned int idx) const
		{
			return value[idx];
		}
		const Vector4 Vector4::One()
		{
			return Vector4(1, 1, 1, 1);
		}
		const Vector4 Vector4::Zero()
		{
			return Vector4(0, 0, 0);
		}
		const Vector4 Vector4::UnitX()
		{
			return Vector4(1, 0, 0);
		}
		const Vector4 Vector4::UnitY()
		{
			return Vector4(0, 1, 0);
		}
		const Vector4 Vector4::UnitZ()
		{
			return Vector4(0, 0, 1);
		}
		const Vector4 Vector4::UnitW()
		{
			return Vector4(0, 0, 0, 1);
		}
		const Vector4 Vector4::Abs(const Vector4 & vector4)
		{
			float x = vector4.x >= 0 ? vector4.x : -vector4.x;
			float y = vector4.y >= 0 ? vector4.y : -vector4.y;
			float z = vector4.z >= 0 ? vector4.z : -vector4.z;
			float w = vector4.w >= 0 ? vector4.w : -vector4.w;

			return Vector4(x, y, z, w);
		}
		const Vector4 Vector4::Add(const Vector4 & lhs, const Vector4 & rhs)
		{
			return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
		}
		const Vector4 Vector4::Clamp(const Vector4 & vector4, const Vector4 & min, const Vector4 & max)
		{
			float x = vector4.x < min.x ? min.x : vector4.x;
			float y = vector4.y < min.y ? min.y : vector4.y;
			float z = vector4.z < min.z ? min.z : vector4.z;
			float w = vector4.w < min.w ? min.w : vector4.w;

			return Vector4(x > max.x ? max.x : x, y > max.y ? max.y : y, z > max.z ? max.z : z, w > max.w ? max.w : w);
		}
		const Vector4 Vector4::CopyTo(float arr[])
		{
			return Vector4(arr[0], arr[1], arr[2], arr[3]);
		}
		const Vector4 Vector4::Lerp(const Vector4 & from, const Vector4 & to, float t)
		{
			Vector4 v = to - from;

			return v * t;
		}
		const Vector4 Vector4::Max(const Vector4 & lhs, const Vector4 & rhs)
		{
			float x = lhs.x < rhs.x ? rhs.x : lhs.x;
			float y = lhs.y < rhs.y ? rhs.y : lhs.y;
			float z = lhs.z < rhs.z ? rhs.z : lhs.z;
			float w = lhs.w < rhs.w ? rhs.w : lhs.w;

			return Vector4(x, y, z, w);
		}
		const Vector4 Vector4::Min(const Vector4 & lhs, const Vector4 & rhs)
		{
			float x = lhs.x > rhs.x ? rhs.x : lhs.x;
			float y = lhs.y > rhs.y ? rhs.y : lhs.y;
			float z = lhs.z > rhs.z ? rhs.z : lhs.z;
			float w = lhs.w > rhs.w ? rhs.w : lhs.w;

			return Vector4(x, y, z, w);
		}
		const Vector4 Vector4::Negate(const Vector4 & vector4)
		{
			return -vector4;
		}
		const Vector4 Vector4::Normalized(const Vector4 & vector4)
		{
			float v = Vector4::Length(vector4);
			if (v < FLT_EPSILON)
				return Zero();
			return vector4 / v;
		}
		float Vector4::Distance(const Vector4 & from, const Vector4 & to)
		{
			float sx = (to.x - from.x);
			float sy = (to.y - from.y);
			float sz = (to.z - from.z);
			float sw = (to.w - from.w);

			return sqrtf(sx * sx + sy * sy + sz * sz + sw * sw);
		}
		float Vector4::DistanceSquared(const Vector4 & from, const Vector4 & to)
		{
			float sx = (to.x - from.x);
			float sy = (to.y - from.y);
			float sz = (to.z - from.z);
			float sw = (to.w - from.w);

			return sx * sx + sy * sy + sz * sz + sw * sw;
		}
		float Vector4::Length(const Vector4 & vector4)
		{
			return sqrtf((vector4.x * vector4.x) + (vector4.y + vector4.y) + (vector4.z + vector4.z) + (vector4.w + vector4.w));
		}
		float Vector4::LengthSquared(const Vector4 & vector4)
		{
			return (vector4.x * vector4.x) + (vector4.y + vector4.y) + (vector4.z + vector4.z) + (vector4.w + vector4.w);
		}
		float Vector4::Dot(const Vector4 & lhs, const Vector4 & rhs)
		{
			return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
		}
		const Vector4 Vector4::Normalized() const
		{
			return Vector4::Normalized(*this);
		}
		void Vector4::Set(float newX, float newY, float newZ, float newW)
		{
			x = newX;
			y = newY;
			z = newZ;
			w = newW;
		}
	}
}