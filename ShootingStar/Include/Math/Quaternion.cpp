#include "../stdafx.h"
#include "Quaternion.h"

namespace shootingStar
{
	namespace math
	{
		Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
		{
		}
		const Quaternion Quaternion::operator+() const
		{
			return (*this);
		}
		const Quaternion Quaternion::operator-() const
		{
			return Quaternion(-x, -y, -z, -w);
		}
		const Quaternion Quaternion::operator*(const Quaternion & other) const
		{
			return Quaternion(
				this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
				this->w * other.y + this->y * other.w + this->z * other.x - this->x * other.z,
				this->w * other.z + this->z * other.w + this->x * other.y - this->y * other.x,
				this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z);
		}
		const Quaternion Quaternion::operator*(const float f) const
		{
			return Quaternion(x * f, y * f, z * f, w * f);
		}
		const Quaternion Quaternion::operator/(const float f) const
		{
			return Quaternion(x / f, y / f, z / f, w / f);
		}
		
		bool Quaternion::operator==(const Quaternion & other)
		{
			return IsEqualUsingDot(Dot(*this, other));
		}
		bool Quaternion::operator!=(const Quaternion & other)
		{
			return !((*this) == other);
		}
		
		Quaternion & Quaternion::operator*=(const Quaternion & other)
		{
			x = this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y;
			y = this->w * other.y + this->y * other.w + this->z * other.x - this->x * other.z;
			z = this->w * other.z + this->z * other.w + this->x * other.y - this->y * other.x;
			w = this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z;
			return (*this);
		}
		
		float Quaternion::operator[](unsigned int idx) const
		{
			return value[idx];
		}
		
		float Quaternion::Dot(const Quaternion & lhs, const Quaternion & rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
		}
		float Quaternion::Angle(const Quaternion & lhs, const Quaternion & rhs)
		{
			float dot = Dot(lhs, rhs); 
			
			return IsEqualUsingDot(dot) ? 0.0f : acos(min(abs(dot), 1.0f)) * 2.0F * rad2deg;
		}

		const Quaternion Quaternion::Slerp(const Quaternion & from, const Quaternion & to, float t)
		{
			float fromWeight, toWeight;

			float diff = (from.x * to.x) + (from.y * to.y) + (from.z * to.z) + (from.w * to.w);

			if ((1.0f - fabsf(diff)) > kEpsilon)
			{
				float theta = acosf(fabsf(diff));
				float oneOverSinTheta = 1.0f / sinf(theta);

				fromWeight = sinf(theta * (1.0f - t)) * oneOverSinTheta;
				toWeight = sinf(theta * t) * oneOverSinTheta;

				if (diff < 0.0f)
					fromWeight *= -1.0f;
			}
			else
			{
				fromWeight = 1.0f - t;
				toWeight = t;
			}

			return Quaternion((from.x * fromWeight) + (to.x  * toWeight),
				(from.y * fromWeight) + (to.y  * toWeight),
				(from.z * fromWeight) + (to.z  * toWeight),
				(from.w * fromWeight) + (to.w  * toWeight)).Normalized();
		}

		const Quaternion Quaternion::Lerp(const Quaternion & from, const Quaternion & to, float t)
		{
			float diff = (from.x * to.x) + (from.y * to.y) + (from.z * to.z) + (from.w * to.w);

			float fromWeight = 1.0f - t;
			float toWeight = t;

			return Quaternion((from.x * fromWeight) + (to.x * toWeight),
				(from.y * fromWeight) + (to.y * toWeight),
				(from.z * fromWeight) + (to.z * toWeight),
				(from.w * fromWeight) + (to.w * toWeight));
		}

		const Quaternion Quaternion::FromYawPitchRoll(float yaw, float pitch, float roll)
		{
			float syaw = sinf(yaw / 2.0f);
			float cyaw = cosf(yaw / 2.0f);
			float spitch = sinf(pitch / 2.0f);
			float cpitch = cosf(pitch / 2.0f);
			float sroll = sinf(roll / 2.0f);
			float croll = cosf(roll / 2.0f);

			return Quaternion(
				syaw * cpitch * sroll + cyaw * spitch * croll,
				syaw * cpitch * croll - cyaw * spitch * sroll,
				cyaw * cpitch * sroll - syaw * spitch * croll,
				cyaw * cpitch * croll + syaw * spitch * sroll);
		}
		
		const Quaternion Quaternion::FromAxis(const Vector3 & axis, float angle)
		{
			Vector3 temp = Vector3::Normalize(axis);

			return Quaternion(sinf(angle / 2.0f) * temp.x,
				sinf(angle / 2.0f) * temp.y,
				sinf(angle / 2.0f) * temp.z,
				cosf(angle / 2.0f));
		}
		const Quaternion Quaternion::Identity()
		{
			return Quaternion(0, 0, 0, 1);
		}
		const Quaternion Quaternion::Eular(float x, float y, float z)
		{
			return Quaternion::FromYawPitchRoll(x,y,z);
		}
		void Quaternion::Set(float newX, float newY, float newZ, float newW)
		{
			x = newX;
			y = newY;
			z = newZ;
			w = newW;
		}
		const Quaternion Quaternion::Normalized() const
		{
			float sq = (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
			float dst = 1.0f / sqrtf(sq);

			return Quaternion(this->x * dst, this->y * dst, this->z * dst, this->w * dst);
		}
		const Quaternion Quaternion::Inversed() const
		{
			float sq = (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
			return this->Conjugate() / sq;
		}
		const Quaternion Quaternion::Conjugate() const
		{
			return Quaternion(-x, -y, -z, w);
		}
	}
}