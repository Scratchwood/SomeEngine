#pragma once
#include <iostream>
namespace engine::math
{
	struct Vector2 
	{
		float x, y;
			
		Vector2();
		Vector2(const float x, const float y);
		Vector2(const Vector2& v);

		float length();
		float dot(const Vector2& right) const;

		void normalize();

		friend Vector2 operator+(Vector2 left, const Vector2& right);
		friend Vector2 operator-(Vector2 left, const Vector2& right);
		friend Vector2 operator*(Vector2 left, const Vector2& right);
		friend Vector2 operator*(Vector2 left, const float right);
		friend Vector2 operator/(Vector2 left, const Vector2& right);
		friend Vector2 operator/(Vector2 left, const float right);

		Vector2& operator+=(const Vector2& right);
		Vector2& operator-=(const Vector2& right);
		Vector2& operator*=(const Vector2& right);
		Vector2& operator/=(const Vector2& right);

		bool operator==(const Vector2& right);
		bool operator!=(const Vector2& right);

		void operator=(const Vector2& right);

		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
	};
}