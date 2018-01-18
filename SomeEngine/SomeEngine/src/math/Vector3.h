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
		static inline const Vector3& Forward()
		{
			static const Vector3 v3(0, 0, 1);
			return v3;
		}
		static inline const Vector3& Up()
		{
			static const Vector3 v3(0, 1, 0);
			return v3;
		}
		static inline const Vector3& Right()
		{
			static const Vector3 v3(1, 0, 0);
			return v3;
		}
		static inline const Vector3& Back()
		{
			static const Vector3 v3 = Forward() * -1;
			return v3;
		}
		static inline const Vector3& Down()
		{
			static const Vector3 v3 = Up() * -1;
			return v3;
		}
		static inline const Vector3& Left()
		{
			static const Vector3 v3 = Right() * -1;
			return v3;
		}


		float length();
		float dot(const Vector3& right) const;
		Vector3 cross(Vector3& right) const;

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