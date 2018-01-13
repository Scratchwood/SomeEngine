#include "Vector2.h"

namespace engine::math 
{
	Vector2::Vector2() :x(0), y(0)
	{

	}

	Vector2::Vector2(const float x, const float y) : x(x), y(y)
	{

	}

	Vector2::Vector2(const Vector2 & v) : x(v.x), y(v.y)
	{

	}

	float Vector2::length()
	{
		return sqrtf((x*x) + (y*y));
	}

	float Vector2::dot(const Vector2 & right) const
	{
		return (x * right.x) + (y * right.y);
	}

	void Vector2::normalize()
	{
		float l = length();
		x /= l;
		y /= l;
	}

	Vector2 & Vector2::operator+=(const Vector2 & right)
	{
		x += right.x;
		y += right.y;
		return *this;
	}

	Vector2 & Vector2::operator-=(const Vector2 & right)
	{
		x -= right.x;
		y -= right.y;
		return *this;
	}

	Vector2 & Vector2::operator*=(const Vector2 & right)
	{
		x *= right.x;
		y *= right.y;
		return *this;
	}

	Vector2 & Vector2::operator/=(const Vector2 & right)
	{
		x /= right.x;
		y /= right.y;
		return *this;
	}

	bool Vector2::operator==(const Vector2 & right)
	{
		return (x == right.x) && (y == right.y);
	}

	bool Vector2::operator!=(const Vector2 & right)
	{
		return !(*this==right);
	}
	Vector2 operator+(Vector2 left, const Vector2 & right)
	{
		return Vector2(left.x + right.x, left.y + right.y);
	}

	Vector2 operator-(Vector2 left, const Vector2 & right)
	{
		return Vector2(left.x - right.x, left.y - right.y);
	}

	Vector2 operator*(Vector2 left, const Vector2 & right)
	{
		return Vector2(left.x * right.x, left.y * right.y);
	}

	Vector2 operator*(Vector2 left, const float right)
	{
		return Vector2(left.x * right, left.y * right);
	}

	Vector2 operator/(Vector2 left, const Vector2 & right)
	{
		return Vector2(left.x / right.x, left.y / right.y);
	}

	Vector2 operator/(Vector2 left, const float right)
	{
		return Vector2(left.x / right, left.y / right);
	}

	void Vector2::operator=(const Vector2& right)
	{
		x = right.x;
		y = right.y;
	}

	std::ostream & operator<<(std::ostream & stream, const Vector2 & vector)
	{
		return stream << "Vector2(X: " << vector.x << ", Y: " << vector.y << ")";
	}
}