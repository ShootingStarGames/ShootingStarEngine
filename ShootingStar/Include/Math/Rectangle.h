#pragma once
#include "Vector2.h"

namespace shootingStar
{
	namespace math
	{
		class Vector2;

		class Rectangle
		{
		public:
			Rectangle();
			Rectangle(const Vector2& position, const Vector2& size);
			Rectangle(float x, float y, float width, float height);

			bool operator==(const Rectangle& other) const;
			bool operator!=(const Rectangle& other) const;

			bool Intersects(const Rectangle& other) const;
			bool Contains(const Vector2& point) const;

			inline Vector2 GetLeftDown() const { return position - size; }
			inline Vector2 GetRightUp() const { return position + size; }

		public:
			union
			{
				Vector2 position;
				struct {
					float x;
					float y;
				};
			};
			union
			{
				Vector2 size;
				struct {
					float width;
					float height;
				};
			};
		};
	}
}
