#pragma once
#include <iostream>

namespace engine::math
{
	struct Vector4
	{
		float x, y, z, w;

		Vector4();
		Vector4(const float x, const float y, const float z, const float w);
		Vector4(const Vector4& v);

		float length();
		float dot(const Vector4& right) const;

		void normalize();

		friend Vector4 operator+(Vector4 left, const Vector4& right);
		friend Vector4 operator-(Vector4 left, const Vector4& right);
		friend Vector4 operator*(Vector4 left, const Vector4& right);
		friend Vector4 operator*(Vector4 left, const float right);
		friend Vector4 operator/(Vector4 left, const Vector4& right);
		friend Vector4 operator/(Vector4 left, const float right);

		Vector4& operator+=(const Vector4& right);
		Vector4& operator-=(const Vector4& right);
		Vector4& operator*=(const Vector4& right);
		Vector4& operator/=(const Vector4& right);

		bool operator==(const Vector4& right);
		bool operator!=(const Vector4& right);

		void operator=(const Vector4& right);

		friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector);

	};
}

