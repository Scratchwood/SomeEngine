#pragma once
#include <iostream>
namespace engine::math
{
	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(const float x, const float y, const float z);
		Vector3(const Vector3& v);

		static inline Vector3 FORWARD()
		{
			return Vector3(0, 0, 1);
		}
		static inline Vector3 BACK()
		{
			return Vector3(0, 0, -1);
		}
		static inline Vector3 UP()
		{
			return Vector3(0, 1, 0);
		}
		static inline Vector3 DOWN()
		{
			return Vector3(0, -1, 0);
		}
		static inline Vector3 LEFT()
		{
			return Vector3(-1, 0, 0);
		}
		static inline Vector3 RIGHT()
		{
			return Vector3(1, 0, 0);
		}

		float length();
		float dot(const Vector3& right) const;

		void normalize();

		friend Vector3 operator+(Vector3 left, const Vector3& right);
		friend Vector3 operator-(Vector3 left, const Vector3& right);
		friend Vector3 operator*(Vector3 left, const Vector3& right);
		friend Vector3 operator*(Vector3 left, const float right);
		friend Vector3 operator/(Vector3 left, const Vector3& right);
		friend Vector3 operator/(Vector3 left, const float right);

		Vector3& operator+=(const Vector3& right);
		Vector3& operator-=(const Vector3& right);
		Vector3& operator*=(const Vector3& right);
		Vector3& operator/=(const Vector3& right);
				  
		bool operator==(const Vector3& right);
		bool operator!=(const Vector3& right);

		void operator=(const Vector3& right);

		friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);
	};
}