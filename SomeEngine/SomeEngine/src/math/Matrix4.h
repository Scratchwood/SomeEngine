#pragma once
#include <array>
#include <initializer_list>
#include "vector3.h"

namespace engine::math {

	class Matrix4
	{
	protected:
		std::array<float, 16> m_Values;

#define M00 0
#define M01 1
#define M02 2
#define M03 3
#define M10 4
#define M11 5
#define M12 6
#define M13 7
#define M20 8
#define M21 9
#define M22 10
#define M23 11
#define M30 12
#define M31 13
#define M32 14
#define M33 15

	public:
		Matrix4();
		Matrix4(const std::initializer_list<float> list);
		~Matrix4();

		inline float* getArray()
		{
			return m_Values.data();
		}
		Matrix4& identity();
		Matrix4& zero();

		Matrix4& multiply(Matrix4& multiply);

		Matrix4& translate(float x, float y, float z);
		Matrix4& translate(Vector3& translation);
		Matrix4& scale(float x, float y, float z);
		Matrix4& scale(Vector3& scale);
		Matrix4& scalar(float scalar);
		
		Matrix4& operator*=(Matrix4& multiply);
		bool operator==(Matrix4& toCompare);
		void operator=(Matrix4& toCopy);
		void operator=(const std::initializer_list<float> list);
		float& operator[](int index);

		friend std::ostream& operator<<(std::ostream& stream, Matrix4& vector);
	};
}
