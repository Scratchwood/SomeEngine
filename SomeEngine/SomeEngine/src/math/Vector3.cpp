#include "Vector3.h"

namespace engine::math
{
	Vector3::Vector3() :x(0), y(0), z(0)
	{

	}

	Vector3::Vector3(const float x, const float y, const float z) : x(x), y(y), z(z)
	{

	}

	Vector3::Vector3(const Vector3 & v) : x(v.x), y(v.y), z(v.z)
	{

	}

	float Vector3::length()
	{
		return sqrtf((x*x) + (y*y) + (z*z));
	}

	float Vector3::dot(const Vector3 & right) const
	{
		return (x * right.x) + (y * right.y) + (x * right.z);
	}

	Vector3 Vector3::cross(Vector3 & right) const
	{
		Vector3 result;
		result.x = y * right.z - z * right.y;
		result.y = z * right.x - x * right.z;
		result.z = x * right.y - y * right.x;
		return result;
	}

	void Vector3::normalize()
	{
		float l = length();
		x /= l;
		y /= l;
		z /= l;
	}

	Vector3 & Vector3::operator+=(const Vector3 & right)
	{
		x += right.x;
		y += right.y;
		z += right.z;
		return *this;
	}

	Vector3 & Vector3::operator-=(const Vector3 & right)
	{
		x -= right.x;
		y -= right.y;
		z -= right.z;
		return *this;
	}

	Vector3 & Vector3::operator*=(const Vector3 & right)
	{
		x *= right.x;
		y *= right.y;
		z *= right.z;
		return *this;
	}

	Vector3 & Vector3::operator/=(const Vector3 & right)
	{
		x /= right.x;
		y /= right.y;
		z /= right.z;
		return *this;
	}

	bool Vector3::operator==(const Vector3 & right)
	{
		return (x == right.x) && (y == right.y) && (z == right.z);
	}

	bool Vector3::operator!=(const Vector3 & right)
	{
		return !(*this == right);
	}
	Vector3 operator+(Vector3 left, const Vector3 & right)
	{
		return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	Vector3 operator-(Vector3 left, const Vector3 & right)
	{
		return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	Vector3 operator*(Vector3 left, const Vector3 & right)
	{
		return Vector3(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	Vector3 operator*(Vector3 left, const float right)
	{
		return Vector3(left.x * right, left.y * right, left.z * right);
	}

	Vector3 operator/(Vector3 left, const Vector3 & right)
	{
		return Vector3(left.x / right.x, left.y / right.y, left.z / right.z);
	}

	Vector3 operator/(Vector3 left, const float right)
	{
		return Vector3(left.x / right, left.y / right, left.z / right);
	}

	void Vector3::operator=(const Vector3& right)
	{
		x = right.x;
		y = right.y;
		z = right.z;
	}

	std::ostream & operator<<(std::ostream & stream, const Vector3 & vector)
	{
		return stream << "Vector3(X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << ")";
	}
}