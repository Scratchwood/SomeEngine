#pragma once
#include <array>
#include <initializer_list>
#include "vector2.h"

namespace engine::math {

	class Matrix3
	{
	protected:
		std::array<float, 9> m_Values;

#define M00 0
#define M01 1
#define M02 3
#define M10 4
#define M11 5
#define M12 6
#define M20 7
#define M21 8
#define M22 9

	public:
		Matrix3();
		Matrix3(const std::initializer_list<float> list);
		~Matrix3();

		inline float* getArray()
		{
			return m_Values.data();
		}
		Matrix3& identity();
		Matrix3& zero();

		Matrix3& multiply(Matrix3& multiply);

		Matrix3& translate(float x, float y);
		Matrix3& translate(Vector2& translation);
		Matrix3& scale(float x, float y);
		Matrix3& scale(Vector2& scale);
		Matrix3& scalar(float scalar);

		Matrix3& operator*=(Matrix3& multiply);
		bool operator==(Matrix3& toCompare);
		void operator=(Matrix3& toCopy);
		void operator=(const std::initializer_list<float> list);
		float& operator[](int index);

		friend std::ostream& operator<<(std::ostream& stream, Matrix3& vector);
	};
}
