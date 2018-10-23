#pragma once
#include "math_func.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

namespace shootingStar
{
	namespace math
	{
		class Vector2;
		class Vector3;
		class Vector4;
		class Quaternion;

		class Matrix4x4
		{
		public:
			Matrix4x4() {};
			Matrix4x4(
				float _00, float _01, float _02, float _03,
				float _10, float _11, float _12, float _13,
				float _20, float _21, float _22, float _23,
				float _30, float _31, float _32, float _33);
			Matrix4x4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3);

		public:
			bool				operator != (const Matrix4x4& mat) const;
			bool				operator == (const Matrix4x4& mat) const;

			Matrix4x4&			operator+= (const Matrix4x4& mat);
			Matrix4x4&			operator-= (const Matrix4x4& mat);
			Matrix4x4&			operator*= (const Matrix4x4& mat);
			Matrix4x4&			operator*= (float f);
			Matrix4x4&			operator/= (float f);

			const Matrix4x4		operator+ (const Matrix4x4& mat) const;
			const Matrix4x4		operator- (const Matrix4x4& mat) const;
			const Matrix4x4		operator* (const Matrix4x4& mat) const;
			const Matrix4x4		operator* (float f) const;
			const Matrix4x4		operator/ (float f) const;

			const Vector2		operator* (const Vector2& v) const;
			const Vector3		operator* (const Vector3& v) const;
			const Vector4		operator* (const Vector4& v) const;

			friend Matrix4x4	operator*(float lhs, const Matrix4x4& rhs) { return rhs * lhs; }
			friend Vector4		operator*(const Vector4 &lhs, const Matrix4x4& rhs) { return rhs * lhs; }
			friend Vector3		operator*(const Vector3 &lhs, const Matrix4x4& rhs) { return rhs * lhs; }
			friend Vector4&		operator*=(Vector4 &lhs, const Matrix4x4& rhs) { lhs = rhs * lhs; return lhs; }
			friend Vector3&		operator*=(Vector3 &lhs, const Matrix4x4& rhs) { lhs = rhs * lhs; return lhs; }

		public:
			static Matrix4x4 Multiply(const Matrix4x4& lhs, const Matrix4x4& rhs);
			static Matrix4x4 Transpose(const Matrix4x4& mat);
			static Matrix4x4 Inverse(const Matrix4x4& mat);
			static Matrix4x4 Identity();
			static Matrix4x4 Translate(const Vector3& vector);
			static Matrix4x4 Scale(const Vector3& vector);
			static Matrix4x4 Rotate(const Quaternion& quat);

			static Matrix4x4 Orthographic(float left, float right, float bottom, float top, float nearD, float farD);
			static Matrix4x4 Perspective(float fov, float aspectRatio, float nearD, float farD);
			static Matrix4x4 LookAt(const Vector3& camera, const Vector3& object, const Vector3& up);

		public:
			void Set(
				float _00, float _01, float _02, float _03,
				float _10, float _11, float _12, float _13,
				float _20, float _21, float _22, float _23,
				float _30, float _31, float _32, float _33);

			Vector3 MultiplyVector(const Vector3& vector);
			Vector3 MultiplyPoint(const Vector3& point);
		public:
			union
			{
				struct
				{
					float        m00, m01, m02, m03;
					float        m10, m11, m12, m13;
					float        m20, m21, m22, m23;
					float        m30, m31, m32, m33;
				};

				float m[4][4] = { 0.0f, };
				Vector4 rows[4];
			};
		};
	}

}
