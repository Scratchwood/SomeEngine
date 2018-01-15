#include "Matrix3.h"

namespace engine::math
{

	Matrix3::Matrix3() : m_Values({
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
		})
	{
	}

	Matrix3::Matrix3(const std::initializer_list<float> list)
	{
		this->operator=(list);
	}

	Matrix3::~Matrix3()
	{
	}

	Matrix3& Matrix3::identity()
	{
		m_Values = {
			1, 0, 0,
			0, 1, 0,
			0, 0, 1
		};
		return *this;
	}

	Matrix3& Matrix3::zero()
	{
		memset(&m_Values, 0, sizeof(float) * 9);
		return *this;
	}

	Matrix3& Matrix3::multiply(Matrix3& multiply)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & b00 = multiply.m_Values[M00];
		const float & b01 = multiply.m_Values[M01];
		const float & b02 = multiply.m_Values[M02];
		const float & b10 = multiply.m_Values[M10];
		const float & b11 = multiply.m_Values[M11];
		const float & b12 = multiply.m_Values[M12];
		const float & b20 = multiply.m_Values[M20];
		const float & b21 = multiply.m_Values[M21];
		const float & b22 = multiply.m_Values[M22];
		m_Values = {
			(a00 * b00) + (a01 * b10) + (a02 * b20),
			(a00 * b01) + (a01 * b11) + (a02 * b21),
			(a00 * b02) + (a01 * b12) + (a02 * b22),
			(a10 * b00) + (a11 * b10) + (a12 * b20),
			(a10 * b01) + (a11 * b11) + (a12 * b21),
			(a10 * b02) + (a11 * b12) + (a12 * b22),
			(a20 * b00) + (a21 * b10) + (a22 * b20),
			(a20 * b01) + (a21 * b11) + (a22 * b21),
			(a20 * b02) + (a21 * b12) + (a22 * b22)
		};
		return *this;
	}

	Matrix3& Matrix3::translate(float x, float y)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		m_Values = {
			(a00)+(a02 * x),
			(a01)+(a02 * y),
			(a02),
			(a10)+(a12 * x),
			(a11)+(a12 * y),
			(a12),
			(a20)+(a22 * x),
			(a21)+(a22 * y),
			(a22)
		};
		return *this;
	}

	Matrix3& Matrix3::translate(Vector2& translation)
	{
		return translate(translation.x, translation.y, translation.z);
	}

	Matrix3& Matrix3::scale(float x, float y)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		m_Values = {
			(a00 * x),
			(a01 * y),
			(a02),
			(a10 * x),
			(a11 * y),
			(a12),
			(a20 * x),
			(a21 * y),
			(a22)
		};
		return *this;
	}

	Matrix3& Matrix3::scale(Vector3& scale)
	{
		return this->scale(scale.x, scale.y);
	}

	Matrix3& Matrix3::scalar(float scalar)
	{
		m_Values[M00] *= scalar;
		m_Values[M01] *= scalar;
		m_Values[M02] *= scalar;
		m_Values[M10] *= scalar;
		m_Values[M11] *= scalar;
		m_Values[M12] *= scalar;
		m_Values[M20] *= scalar;
		m_Values[M21] *= scalar;
		m_Values[M22] *= scalar;
		return *this;
	}

	Matrix3& Matrix3::operator*=(Matrix3& multiply)
	{
		return this->multiply(multiply);
	}

	bool Matrix3::operator==(Matrix3& toCompare)
	{
		return memcmp(&m_Values, &toCompare.m_Values, 9 * sizeof(float)) == 0;
	}
	void Matrix3::operator=(Matrix3& toCopy)
	{
		memcpy(&m_Values, &toCopy, 9 * sizeof(float));
	}
	void Matrix3::operator=(const std::initializer_list<float> list)
	{
		int count = 0;
		for (float value : list)
		{
			m_Values[++count] = value;
		}
	}
	float& Matrix3::operator[](int index)
	{
		return m_Values[index];
	}

	std::ostream & operator<<(std::ostream & stream, Matrix3 & matrix)
	{
		stream << "Matrix3(\r\n";
		for (int i = 0; i < 9; i += 3)
		{
			stream << "\t" << matrix[i] << ", " << matrix[i + 1] << ", " << matrix[i + 2] << "\r\n";
		}
		stream << ")";
		return stream;
	}
}
