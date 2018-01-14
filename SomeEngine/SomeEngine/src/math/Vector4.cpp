#include "Vector4.h"



namespace engine::math
{
	Vector4::Vector4() :x(0), y(0), z(0), w(0)
	{

	}

	Vector4::Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w)
	{

	}

	Vector4::Vector4(const Vector4 & v) : x(v.x), y(v.y), z(v.z), w(v.w)
	{

	}

	float Vector4::length()
	{
		return sqrtf((x*x) + (y*y) + (z*z) + (w*w));
	}

	float Vector4::dot(const Vector4 & right) const
	{
		return (x * right.x) + (y * right.y) + (x * right.z) + (w * right.w);
	}

	void Vector4::normalize()
	{
		float l = length();
		x /= l;
		y /= l;
		z /= l;
		w /= l;
	}

	Vector4 & Vector4::operator+=(const Vector4 & right)
	{
		x += right.x;
		y += right.y;
		z += right.z;
		w += right.w;
		return *this;
	}

	Vector4 & Vector4::operator-=(const Vector4 & right)
	{
		x -= right.x;
		y -= right.y;
		z -= right.z;
		w -= right.w;
		return *this;
	}

	Vector4 & Vector4::operator*=(const Vector4 & right)
	{
		x *= right.x;
		y *= right.y;
		z *= right.z;
		w *= right.w;
		return *this;
	}

	Vector4 & Vector4::operator/=(const Vector4 & right)
	{
		x /= right.x;
		y /= right.y;
		z /= right.z;
		w /= right.w;
		return *this;
	}

	bool Vector4::operator==(const Vector4 & right)
	{
		return (x == right.x) && (y == right.y) && (z == right.z) && (w == right.w);
	}

	bool Vector4::operator!=(const Vector4 & right)
	{
		return !(*this == right);
	}
	Vector4 operator+(Vector4 left, const Vector4 & right)
	{
		return Vector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	}

	Vector4 operator-(Vector4 left, const Vector4 & right)
	{
		return Vector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	}

	Vector4 operator*(Vector4 left, const Vector4 & right)
	{
		return Vector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
	}

	Vector4 operator*(Vector4 left, const float right)
	{
		return Vector4(left.x * right, left.y * right, left.z * right, left.w * right);
	}

	Vector4 operator/(Vector4 left, const Vector4 & right)
	{
		return Vector4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
	}

	Vector4 operator/(Vector4 left, const float right)
	{
		return Vector4(left.x / right, left.y / right, left.z / right, left.w / right);
	}

	void Vector4::operator=(const Vector4& right)
	{
		x = right.x;
		y = right.y;
		z = right.z;
		w = right.w;
	}

	std::ostream & operator<<(std::ostream & stream, const Vector4 & vector)
	{
		return stream << "Vector4(X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << ", W: " << vector.w << ")";
	}
}