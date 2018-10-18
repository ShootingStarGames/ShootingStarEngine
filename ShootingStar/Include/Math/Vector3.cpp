#include "Vector3.h"

namespace shootingStar
{
	namespace math
	{
		Vector3::Vector3(float f) : x(f), y(f), z(f)
		{
		}
		Vector3::Vector3(float x, float y) : x(x), y(y), z(0)
		{
		}
		Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
		{
		}
		const Vector3 Vector3::operator+() const
		{
			return (*this);
		}
		const Vector3 Vector3::operator-() const
		{
			return Vector3(-x, -y, -z);
		}
		const Vector3 Vector3::operator+(const Vector3 & other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		const Vector3 Vector3::operator-(const Vector3 & other) const
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}
		bool Vector3::operator==(const Vector3 & other)
		{
			return (fabsf(x - other.x) < FLT_EPSILON) & (fabsf(y - other.y) < FLT_EPSILON) & (fabsf(z - other.z) < FLT_EPSILON);
		}
		bool Vector3::operator!=(const Vector3 & other)
		{
			return !Vector3::operator==(other);
		}
		const Vector3 Vector3::operator*(const float f) const
		{
			return Vector3(x * f, y * f, z * f);
		}
		const Vector3 Vector3::operator*(const Vector3 & other) const
		{
			return Vector3(x * other.x, y * other.y, z * other.z);
		}
		const Vector3 Vector3::operator/(const float f) const
		{
			return  Vector3(x / f, y / f, z / f);
		}
		const Vector3 Vector3::operator/(const Vector3 & other) const
		{
			return Vector3(x / other.x, y / other.y, z / other.z);
		}
		Vector3 & Vector3::operator+=(const Vector3 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return (*this);
		}
		Vector3 & Vector3::operator-=(const Vector3 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return (*this);
		}
		Vector3 & Vector3::operator*=(const Vector3 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return (*this);
		}
		Vector3 & Vector3::operator*=(float f)
		{
			x *= f;
			y *= f;
			z *= f;
			return (*this);
		}
		Vector3 & Vector3::operator/=(float f)
		{
			x /= f;
			y /= f;
			z /= f;
			return (*this);
		}
		float Vector3::operator[](unsigned int idx) const
		{
			return value[idx];
		}
		const Vector3 Vector3::One()
		{
			return Vector3(1,1,1);
		}
		const Vector3 Vector3::Zero()
		{
			return Vector3(0,0,0);
		}
		const Vector3 Vector3::UnitX()
		{
			return Vector3(1,0,0);
		}
		const Vector3 Vector3::UnitY()
		{
			return Vector3(0,1,0);
		}
		const Vector3 Vector3::UnitZ()
		{
			return Vector3(0,0,1);
		}
		const Vector3 Vector3::Up()
		{
			return Vector3(0,1,0);
		}
		const Vector3 Vector3::Down()
		{
			return Vector3(0,-1,0);
		}
		const Vector3 Vector3::Left()
		{
			return Vector3(-1,0,0);
		}
		const Vector3 Vector3::Right()
		{
			return Vector3(1,0,0);
		}
		const Vector3 Vector3::Foward()
		{
			return Vector3(0,0,1);
		}
		const Vector3 Vector3::Back()
		{
			return Vector3(0,0,-1);
		}
		const Vector3 Vector3::Abs(const Vector3 & vector3)
		{
			float x = vector3.x >= 0 ? vector3.x : -vector3.x;
			float y = vector3.y >= 0 ? vector3.y : -vector3.y;
			float z = vector3.z >= 0 ? vector3.z : -vector3.z;
			return Vector3(x, y, z);
		}
		const Vector3 Vector3::Add(const Vector3 & lhs, const Vector3 & rhs)
		{
			return Vector3(lhs.x + rhs.x, lhs.y + rhs.y,lhs.z + rhs.z);
		}
		const Vector3 Vector3::Clamp(const Vector3 & vector3, const Vector3 & min, const Vector3 & max)
		{
			float x = vector3.x < min.x ? min.x : vector3.x;
			float y = vector3.y < min.y ? min.y : vector3.y;
			float z = vector3.z < min.z ? min.z : vector3.z;

			return Vector3(x > max.x ? max.x : x, y > max.y ? max.y : y, z > max.z ? max.z : z);
		}
		const Vector3 Vector3::CopyTo(float arr[])
		{
			return Vector3(arr[0], arr[1], arr[2]);
		}
		const Vector3 Vector3::Cross(const Vector3 & lhs, const Vector3 & rhs)
		{
			return Vector3(
				lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x);
		}
		const Vector3 Vector3::Lerp(const Vector3 & from, const Vector3 & to, float t)
		{
			Vector3 v = to - from;

			return v * t;
		}
		const Vector3 Vector3::Max(const Vector3 & lhs, const Vector3 & rhs)
		{
			float x = lhs.x < rhs.x ? rhs.x : lhs.x;
			float y = lhs.y < rhs.y ? rhs.y : lhs.y;
			float z = lhs.z < rhs.z ? rhs.z : lhs.z;
			return Vector3(x, y, z);
		}
		const Vector3 Vector3::Min(const Vector3 & lhs, const Vector3 & rhs)
		{
			float x = lhs.x > rhs.x ? rhs.x : lhs.x;
			float y = lhs.y > rhs.y ? rhs.y : lhs.y;
			float z = lhs.z > rhs.z ? rhs.z : lhs.z;
			return Vector3(x, y, z);
		}
		const Vector3 Vector3::Negate(const Vector3 & vector3)
		{
			return -vector3;
		}
		const Vector3 Vector3::Project(const Vector3 & vector3, const Vector3 & axisVector)
		{
			float sqrMag = Vector3::Dot(axisVector, vector3);
			if (sqrMag < FLT_EPSILON)
				return Zero();

			return axisVector * Dot(vector3, axisVector) / sqrMag;
		}
		const Vector3 Vector3::Reflect(Vector3 & dir, const Vector3 & normal)
		{
			return -2.0f * Dot(normal, dir) * normal + dir;
		}
		const Vector3 Vector3::Normalized(const Vector3 & vector3)
		{
			float v = Vector3::Length(vector3);
			if (v < FLT_EPSILON)
				return Zero();
			return vector3 / v;
		}
		float Vector3::Distance(const Vector3 & from, const Vector3 & to)
		{
			float sx = (to.x - from.x);
			float sy = (to.y - from.y);
			float sz = (to.z - from.z);

			return sqrtf(sx * sx + sy * sy + sz *sz);
		}
		float Vector3::DistanceSquared(const Vector3 & from, const Vector3 & to)
		{
			float sx = (to.x - from.x);
			float sy = (to.y - from.y);
			float sz = (to.z - from.z);

			return sx * sx + sy * sy + sz * sz;
		}
		float Vector3::Length(const Vector3 & vector3)
		{
			return sqrtf((vector3.x * vector3.x) + (vector3.y + vector3.y) + (vector3.z + vector3.z));
		}
		float Vector3::LengthSquared(const Vector3 & vector3)
		{
			return (vector3.x * vector3.x) + (vector3.y + vector3.y) + (vector3.z + vector3.z);
		}
		float Vector3::Dot(const Vector3 & lhs, const Vector3 & rhs)
		{
			return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
		}
		const Vector3 Vector3::Project(const Vector3 & axisVector)
		{
			float sqrMag = Vector3::Dot(axisVector, *this);
			if (sqrMag < FLT_EPSILON)
				return Zero();

			return axisVector * Dot(*this, axisVector) / sqrMag;
		}
		const Vector3 Vector3::Reflect(const Vector3 & normal)
		{
			return -2.0f * Dot(normal, (*this)) * normal + (*this);
		}
		const Vector3 Vector3::Normalized() const
		{
			return Vector3::Normalized(*this);
		}
		void Vector3::Set(float newX, float newY, float newZ)
		{
			x = newX;
			y = newY;
			z = newZ;
		}
	}
}