#include "Vector4.h"

namespace shootingStar
{
	namespace math
	{
		Vector4::Vector4(float f) : x(f), y(f), z(f)
		{
		}
		
		Vector4::Vector4(float x, float y) : x(x), y(y), z(0), w(0)
		{
		}
		
		Vector4::Vector4(float x, float y, float z) : x(x), y(y), z(z), w(0)
		{
		}

		Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
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
		
		const Vector4 Vector4::Abs(const Vector4 & vec4)
		{
			float x = vec4.x >= 0 ? vec4.x : -vec4.x;
			float y = vec4.y >= 0 ? vec4.y : -vec4.y;
			float z = vec4.z >= 0 ? vec4.z : -vec4.z;
			float w = vec4.w >= 0 ? vec4.w : -vec4.w;

			return Vector4(x, y, z, w);
		}
		
		const Vector4 Vector4::Add(const Vector4 & lhs, const Vector4 & rhs)
		{
			return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
		}
		
		const Vector4 Vector4::Clamp(const Vector4 & vec4, const Vector4 & min, const Vector4 & max)
		{
			float x = vec4.x < min.x ? min.x : vec4.x;
			float y = vec4.y < min.y ? min.y : vec4.y;
			float z = vec4.z < min.z ? min.z : vec4.z;
			float w = vec4.w < min.w ? min.w : vec4.w;

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
		
		const Vector4 Vector4::Negate(const Vector4 & vec4)
		{
			return -vec4;
		}
		
		const Vector4 Vector4::Normalize(const Vector4 & vec4)
		{
			float v = Vector4::Length(vec4);
			if (v < FLT_EPSILON)
				return Zero();
			return vec4 / v;
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
		
		float Vector4::Length(const Vector4 & vec4)
		{
			return sqrtf((vec4.x * vec4.x) + (vec4.y + vec4.y) + (vec4.z + vec4.z) + (vec4.w + vec4.w));
		}
		
		float Vector4::LengthSquared(const Vector4 & vec4)
		{
			return (vec4.x * vec4.x) + (vec4.y + vec4.y) + (vec4.z + vec4.z) + (vec4.w + vec4.w);
		}
		
		float Vector4::Dot(const Vector4 & lhs, const Vector4 & rhs)
		{
			return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
		}
		
		const Vector4 Vector4::Normalized() const
		{
			return Vector4::Normalize(*this);
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