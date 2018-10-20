#include "Matrix4x4.h"

namespace shootingStar
{
	namespace math
	{
		Matrix4x4::Matrix4x4(
			float _00, float _01, float _02, float _03,
			float _10, float _11, float _12, float _13,
			float _20, float _21, float _22, float _23,
			float _30, float _31, float _32, float _33)
			:	m00(_00), m01(_01), m02(_02), m03(_03),
				m10(_10), m11(_11), m12(_12), m13(_13),
				m20(_20), m21(_21), m22(_22), m23(_23),
				m30(_30), m31(_31), m32(_32), m33(_33)
		{
		}

		Matrix4x4::Matrix4x4(const Vector4 & row0, const Vector4 & row1, const Vector4 & row2, const Vector4 & row3)
		{
			rows[0] = row0;
			rows[1] = row1;
			rows[2] = row2;
			rows[3] = row3;
		}
		bool Matrix4x4::operator!=(const Matrix4x4 & mat) const
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					float f = abs(m[i][j] - mat.m[i][j]);

					if (f > FLT_EPSILON)
						return true;
				}
			return false;
		}
		bool Matrix4x4::operator==(const Matrix4x4 & mat) const
		{
			return !((*this) == mat);
		}
		Matrix4x4 & Matrix4x4::operator+=(const Matrix4x4 & mat)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					m[i][j] += mat.m[i][j];

			return (*this);
		}
		Matrix4x4 & Matrix4x4::operator-=(const Matrix4x4 & mat)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					m[i][j] -= mat.m[i][j];

			return (*this);
		}
		Matrix4x4 & Matrix4x4::operator*=(const Matrix4x4 & mat)
		{
			(*this) = Multiply((*this), mat);

			return (*this);
		}
		Matrix4x4 & Matrix4x4::operator*=(float f)
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					m[i][j] *= f;

			return (*this);
		}
		Matrix4x4 & Matrix4x4::operator/=(float f)
		{
			return (*this)*=(1.0f / f);
		}
		const Matrix4x4 Matrix4x4::operator+(const Matrix4x4 & mat) const
		{
			Matrix4x4 res(*this);

			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					res.m[i][j] += mat.m[i][j];

			return res;
		}
		const Matrix4x4 Matrix4x4::operator-(const Matrix4x4 & mat) const
		{
			Matrix4x4 res(*this);

			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					res.m[i][j] -= mat.m[i][j];

			return res;
		}
		const Matrix4x4 Matrix4x4::operator*(const Matrix4x4 & mat) const
		{
			return Multiply((*this), mat);
		}
		const Matrix4x4 Matrix4x4::operator*(float f) const
		{
			Matrix4x4 res(*this);

			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					res.m[i][j] *= f;

			return res;
		}
		const Matrix4x4 Matrix4x4::operator/(float f) const
		{
			Matrix4x4 res(*this);

			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					res.m[i][j] /= f;

			return res;
		}
		const Vector2 Matrix4x4::operator*(const Vector2 & v) const
		{
			Vector4 res(v.x, v.y, 1.0f, 1.0f);
			res = (*this) * res;

			return Vector2(res.x, res.y);
		}
		const Vector3 Matrix4x4::operator*(const Vector3 & v) const
		{
			Vector4 res(v.x, v.y, v.z, 1.0f);
			res = (*this) * res;

			return Vector3(res.x, res.y, res.z);
		}
		const Vector4 Matrix4x4::operator*(const Vector4 & v) const
		{
			Vector4 res;
			res.x = m00 * v.x + m01 * v.y + m02 * v.z + m03 * v.w;
			res.y = m10 * v.x + m11 * v.y + m12 * v.z + m13 * v.w;
			res.z = m20 * v.x + m21 * v.y + m22 * v.z + m23 * v.w;
			res.w = m30 * v.x + m31 * v.y + m32 * v.z + m33 * v.w;
			return res;

			return res;
		}
		void Matrix4x4::Set(float _00, float _01, float _02, float _03,
							float _10, float _11, float _12, float _13,
							float _20, float _21, float _22, float _23,
							float _30, float _31, float _32, float _33)
		{
			m[0][0] = _00; m[0][1] = _01; m[0][2] = _02; m[0][3] = _03;
			m[1][0] = _10; m[1][1] = _11; m[1][2] = _12; m[1][3] = _13;
			m[2][0] = _20; m[2][1] = _21; m[2][2] = _22; m[2][3] = _23;
			m[3][0] = _30; m[3][1] = _31; m[3][2] = _32; m[3][3] = _33;
		}
		Vector3 Matrix4x4::MultiplyVector(const Vector3 & vector)
		{
			Vector3 res;
			res.x = this->m00 * vector.x + this->m01 * vector.y + this->m02 * vector.z;
			res.y = this->m10 * vector.x + this->m11 * vector.y + this->m12 * vector.z;
			res.z = this->m20 * vector.x + this->m21 * vector.y + this->m22 * vector.z;
			return res;
		}
		Vector3 Matrix4x4::MultiplyPoint(const Vector3 & point)
		{
			Vector3 res;
			float w;
			res.x = this->m00 * point.x + this->m01 * point.y + this->m02 * point.z + this->m03;
			res.y = this->m10 * point.x + this->m11 * point.y + this->m12 * point.z + this->m13;
			res.z = this->m20 * point.x + this->m21 * point.y + this->m22 * point.z + this->m23;
			w = this->m30 * point.x + this->m31 * point.y + this->m32 * point.z + this->m33;

			w = 1.0f / w;
			res.x *= w;
			res.y *= w;
			res.z *= w;
			return res;
		}
		Matrix4x4 Matrix4x4::Multiply(const Matrix4x4 & lhs, const Matrix4x4 & rhs)
		{
			Matrix4x4 res;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					float f = 0.0f;
					for (int k = 0; k < 4; ++k)
					{
						f += lhs.m[i][k] * rhs.m[k][j];
					}

					res.m[i][j] = f;
				}
			}

			return res;
		}
		Matrix4x4 Matrix4x4::Transpose(const Matrix4x4 & mat)
		{
			return Matrix4x4(	mat.m00, mat.m10, mat.m20, mat.m30,
								mat.m01, mat.m11, mat.m21, mat.m31,
								mat.m02, mat.m12, mat.m22, mat.m32,
								mat.m03, mat.m13, mat.m23, mat.m33);
		}
		Matrix4x4 Matrix4x4::Inverse(const Matrix4x4 & mat)
		{
			float A2323 = mat.m22 * mat.m33 - mat.m23 * mat.m32;
			float A1323 = mat.m21 * mat.m33 - mat.m23 * mat.m31;
			float A1223 = mat.m21 * mat.m32 - mat.m22 * mat.m31;
			float A0323 = mat.m20 * mat.m33 - mat.m23 * mat.m30;
			float A0223 = mat.m20 * mat.m32 - mat.m22 * mat.m30;
			float A0123 = mat.m20 * mat.m31 - mat.m21 * mat.m30;
			float A2313 = mat.m12 * mat.m33 - mat.m13 * mat.m32;
			float A1313 = mat.m11 * mat.m33 - mat.m13 * mat.m31;
			float A1213 = mat.m11 * mat.m32 - mat.m12 * mat.m31;
			float A2312 = mat.m12 * mat.m23 - mat.m13 * mat.m22;
			float A1312 = mat.m11 * mat.m23 - mat.m13 * mat.m21;
			float A1212 = mat.m11 * mat.m22 - mat.m12 * mat.m21;
			float A0313 = mat.m10 * mat.m33 - mat.m13 * mat.m30;
			float A0213 = mat.m10 * mat.m32 - mat.m12 * mat.m30;
			float A0312 = mat.m10 * mat.m23 - mat.m13 * mat.m20;
			float A0212 = mat.m10 * mat.m22 - mat.m12 * mat.m20;
			float A0113 = mat.m10 * mat.m31 - mat.m11 * mat.m30;
			float A0112 = mat.m10 * mat.m21 - mat.m11 * mat.m20;

			float det = mat.m00 * (mat.m11 * A2323 - mat.m12 * A1323 + mat.m13 * A1223)
				- mat.m01 * (mat.m10 * A2323 - mat.m12 * A0323 + mat.m13 * A0223)
				+ mat.m02 * (mat.m10 * A1323 - mat.m11 * A0323 + mat.m13 * A0123)
				- mat.m03 * (mat.m10 * A1223 - mat.m11 * A0223 + mat.m12 * A0123);
			det = 1 / det;
			float	_00 = det * (mat.m11 * A2323 - mat.m12 * A1323 + mat.m13 * A1223),
					_01 = det * -(mat.m01 * A2323 - mat.m02 * A1323 + mat.m03 * A1223),
					_02 = det * (mat.m01 * A2313 - mat.m02 * A1313 + mat.m03 * A1213),
					_03 = det * -(mat.m01 * A2312 - mat.m02 * A1312 + mat.m03 * A1212),
					_10 = det * -(mat.m10 * A2323 - mat.m12 * A0323 + mat.m13 * A0223),
					_11 = det * (mat.m00 * A2323 - mat.m02 * A0323 + mat.m03 * A0223),
					_12 = det * -(mat.m00 * A2313 - mat.m02 * A0313 + mat.m03 * A0213),
					_13 = det * (mat.m00 * A2312 - mat.m02 * A0312 + mat.m03 * A0212),
					_20 = det * (mat.m10 * A1323 - mat.m11 * A0323 + mat.m13 * A0123),
					_21 = det * -(mat.m00 * A1323 - mat.m01 * A0323 + mat.m03 * A0123),
					_22 = det * (mat.m00 * A1313 - mat.m01 * A0313 + mat.m03 * A0113),
					_23 = det * -(mat.m00 * A1312 - mat.m01 * A0312 + mat.m03 * A0112),
					_30 = det * -(mat.m10 * A1223 - mat.m11 * A0223 + mat.m12 * A0123),
					_31 = det * (mat.m00 * A1223 - mat.m01 * A0223 + mat.m02 * A0123),
					_32 = det * -(mat.m00 * A1213 - mat.m01 * A0213 + mat.m02 * A0113),
					_33 = det * (mat.m00 * A1212 - mat.m01 * A0212 + mat.m02 * A0112);

			return Matrix4x4(
				_00, _01, _02, _03,
				_10, _11, _12, _13,
				_20, _21, _22, _23,
				_30, _31, _32, _33);
		}
		Matrix4x4 Matrix4x4::Identity()
		{
			return Matrix4x4(	1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 1.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 1.0f, 0.0f, 
								0.0f, 0.0f, 0.0f, 1.0f);
		}
		Matrix4x4 Matrix4x4::Translate(const Vector3 & vector)
		{
			Matrix4x4 m;
			m.m00 = 1.0f; m.m01 = 0.0f; m.m02 = 0.0f; m.m03 = vector.x;
			m.m10 = 0.0f; m.m11 = 1.0f; m.m12 = 0.0f; m.m13 = vector.y;
			m.m20 = 0.0f; m.m21 = 0.0f; m.m22 = 1.0f; m.m23 = vector.z;
			m.m30 = 0.0f; m.m31 = 0.0f; m.m32 = 0.0f; m.m33 = 1.0f;
			return m;
		}
		Matrix4x4 Matrix4x4::Scale(const Vector3 & vector)
		{
			Matrix4x4 m;
			m.m00 = vector.x;	m.m01 = 0.0f;		m.m02 = 0.0f;		m.m03 = 0.0f;
			m.m10 = 0.0f;		m.m11 = vector.y;	m.m12 = 0.0f;		m.m13 = 0.0f;
			m.m20 = 0.0f;		m.m21 = 0.0f;		m.m22 = vector.z;	m.m23 = 0.0f;
			m.m30 = 0.0f;		m.m31 = 0.0f;		m.m32 = 0.0f;		m.m33 = 1.0f;
			return m;
		}
		Matrix4x4 Matrix4x4::Rotate(const Quaternion& quat)
		{
			float x = quat.x * 2.0f;
			float y = quat.y * 2.0f;
			float z = quat.z * 2.0f;
			float xx = quat.x * x;
			float yy = quat.y * y;
			float zz = quat.z * z;
			float xy = quat.x * y;
			float xz = quat.x * z;
			float yz = quat.y * z;
			float wx = quat.w * x;
			float wy = quat.w * y;
			float wz = quat.w * z;


			Matrix4x4 m;
			m.m00 = 1.0f - (yy + zz);	m.m10 = xy + wz;			m.m20 = xz - wy;			m.m30 = 0.0f;
			m.m01 = xy - wz;			m.m11 = 1.0f - (xx + zz);	m.m21 = yz + wx;			m.m31 = 0.0f;
			m.m02 = xz + wy;			m.m12 = yz - wx;			m.m22 = 1.0f - (xx + yy);	m.m32 = 0.0f;
			m.m03 = 0.0f;				 m.m13 = 0.0f;				m.m23 = 0.0f;				m.m33 = 1.0f;
			return m;
		}
	}
}