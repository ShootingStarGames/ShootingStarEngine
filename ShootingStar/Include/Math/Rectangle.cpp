#include "../stdafx.h"
#include "Rectangle.h"

namespace shootingStar
{
	namespace math
	{
		Rectangle::Rectangle()
		{
			position = Vector2();
			size = Vector2();
		}
		Rectangle::Rectangle(const Vector2 & position, const Vector2 & size)
			: x(position.x), y(position.y), width(size.x), height(size.y)
		{
		}
		Rectangle::Rectangle(float x, float y, float width, float height)
			: x(x), y(y), width(width), height(height)
		{
		}
		bool Rectangle::operator==(const Rectangle & other) const
		{
			return position == other.position && size == other.size;
		}
		bool Rectangle::operator!=(const Rectangle & other) const
		{
			return !((*this) == other);
		}
		bool Rectangle::Intersects(const Rectangle & other) const
		{
			return (size > other.position && position < other.size) || (position > other.size && size < other.position);
		}
		bool Rectangle::Contains(const Vector2 & point) const
		{
			return point > GetLeftDown() && point < GetRightUp();
		}
	}
}
