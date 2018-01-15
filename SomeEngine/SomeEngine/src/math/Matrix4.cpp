#include "Matrix4.h"
#include <cmath>
namespace engine::math
{

	Matrix4::Matrix4() : m_Values({
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		})
	{
	}

	Matrix4::Matrix4(const std::initializer_list<float> list)
	{
		this->operator=(list);
	}

	Matrix4::~Matrix4()
	{
	}

	Matrix4& Matrix4::identity()
	{
		m_Values = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
		return *this;
	}

	Matrix4& Matrix4::zero()
	{
		memset(&m_Values, 0, sizeof(float) * 16);
		return *this;
	}

	Matrix4& Matrix4::projection(float fovRadians, float aspect, float near, float far)
	{
		float f = tanf(M_PI_2 * 0.5f - 0.5f * fovRadians);
		float rangeInverted = 1.0f / (near - far);
		m_Values = {
			f/aspect, 0, 0, 0,
			0, f, 0, 0,
			0, 0, (near + far) * rangeInverted, -1,
			0, 0, near * far * rangeInverted * 2.f, 0
		};
		return *this;
	}

	Matrix4& Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		m_Values = {
			2.f / (right - left), 0, 0, 0,
			0, 2.f / (top - bottom), 0, 0,
			0, 0, 2.f / (near - far), 0,

			// last row offset this way for better readability.
			(left + right) / (left - right),
			(bottom + top) / (bottom - top),
			(near + far) / (near - far),
			1,
		};
		return *this;
	}

	Matrix4& Matrix4::multiply(Matrix4& multiply)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a03 = m_Values[M03];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a13 = m_Values[M13];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & a23 = m_Values[M23];
		const float & a30 = m_Values[M30];
		const float & a31 = m_Values[M31];
		const float & a32 = m_Values[M32];
		const float & a33 = m_Values[M33];
		const float & b00 = multiply.m_Values[M00];
		const float & b01 = multiply.m_Values[M01];
		const float & b02 = multiply.m_Values[M02];
		const float & b03 = multiply.m_Values[M03];
		const float & b10 = multiply.m_Values[M10];
		const float & b11 = multiply.m_Values[M11];
		const float & b12 = multiply.m_Values[M12];
		const float & b13 = multiply.m_Values[M13];
		const float & b20 = multiply.m_Values[M20];
		const float & b21 = multiply.m_Values[M21];
		const float & b22 = multiply.m_Values[M22];
		const float & b23 = multiply.m_Values[M23];
		const float & b30 = multiply.m_Values[M30];
		const float & b31 = multiply.m_Values[M31];
		const float & b32 = multiply.m_Values[M32];
		const float & b33 = multiply.m_Values[M33];
		m_Values = {
			(a00 * b00) + (a01 * b10) + (a02 * b20) + (a03 * b30),
			(a00 * b01) + (a01 * b11) + (a02 * b21) + (a03 * b31),
			(a00 * b02) + (a01 * b12) + (a02 * b22) + (a03 * b32),
			(a00 * b03) + (a01 * b13) + (a02 * b23) + (a03 * b33),
			(a10 * b00) + (a11 * b10) + (a12 * b20) + (a13 * b30),
			(a10 * b01) + (a11 * b11) + (a12 * b21) + (a13 * b31),
			(a10 * b02) + (a11 * b12) + (a12 * b22) + (a13 * b32),
			(a10 * b03) + (a11 * b13) + (a12 * b23) + (a13 * b33),
			(a20 * b00) + (a21 * b10) + (a22 * b20) + (a23 * b30),
			(a20 * b01) + (a21 * b11) + (a22 * b21) + (a23 * b31),
			(a20 * b02) + (a21 * b12) + (a22 * b22) + (a23 * b32),
			(a20 * b03) + (a21 * b13) + (a22 * b23) + (a23 * b33),
			(a30 * b00) + (a31 * b10) + (a32 * b20) + (a33 * b30),
			(a30 * b01) + (a31 * b11) + (a32 * b21) + (a33 * b31),
			(a30 * b02) + (a31 * b12) + (a32 * b22) + (a33 * b32),
			(a30 * b03) + (a31 * b13) + (a32 * b23) + (a33 * b33)
		};
		return *this;
	}

	Matrix4& Matrix4::translate(float x, float y, float z)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a03 = m_Values[M03];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a13 = m_Values[M13];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & a23 = m_Values[M23];
		const float & a30 = m_Values[M30];
		const float & a31 = m_Values[M31];
		const float & a32 = m_Values[M32];
		const float & a33 = m_Values[M33];
		m_Values = {
			(a00)+(a03 * x),
			(a01)+(a03 * y),
			(a02)+(a03 * z),
			(a03),
			(a10)+(a13 * x),
			(a11)+(a13 * y),
			(a12)+(a13 * z),
			(a13),
			(a20)+(a23 * x),
			(a21)+(a23 * y),
			(a22)+(a23 * z),
			(a23),
			(a30)+(a33 * x),
			(a31)+(a33 * y),
			(a32)+(a33 * z),
			(a33)
		};
		return *this;
	}

	Matrix4& Matrix4::translate(Vector3& translation)
	{
		return translate(translation.x, translation.y, translation.z);
	}

	Matrix4& Matrix4::scale(float x, float y, float z)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a03 = m_Values[M03];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a13 = m_Values[M13];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & a23 = m_Values[M23];
		const float & a30 = m_Values[M30];
		const float & a31 = m_Values[M31];
		const float & a32 = m_Values[M32];
		const float & a33 = m_Values[M33];
		m_Values = {
			(a00 * x),
			(a01 * y),
			(a02 * z),
			(a03),
			(a10 * x),
			(a11 * y),
			(a12 * z),
			(a13),
			(a20 * x),
			(a21 * y),
			(a22 * z),
			(a23),
			(a30 * x),
			(a31 * y),
			(a32 * z),
			(a33)
		};
		return *this;
	}

	Matrix4& Matrix4::scale(Vector3& scale)
	{
		return this->scale(scale.x, scale.y, scale.z);
	}

	Matrix4& Matrix4::scalar(float scalar)
	{
		m_Values[M00] *= scalar;
		m_Values[M01] *= scalar;
		m_Values[M02] *= scalar;
		m_Values[M03] *= scalar;
		m_Values[M10] *= scalar;
		m_Values[M11] *= scalar;
		m_Values[M12] *= scalar;
		m_Values[M13] *= scalar;
		m_Values[M20] *= scalar;
		m_Values[M21] *= scalar;
		m_Values[M22] *= scalar;
		m_Values[M23] *= scalar;
		m_Values[M30] *= scalar;
		m_Values[M31] *= scalar;
		m_Values[M32] *= scalar;
		m_Values[M33] *= scalar;
		return *this;
	}

	Matrix4& Matrix4::rotateX(float radians)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a03 = m_Values[M03];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a13 = m_Values[M13];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & a23 = m_Values[M23];
		const float & a30 = m_Values[M30];
		const float & a31 = m_Values[M31];
		const float & a32 = m_Values[M32];
		const float & a33 = m_Values[M33];
		const float c = cosf(radians);
		const float s = sinf(radians);
		m_Values = {
			(a00),
			(a01 * c) + (a02 * -s),
			(a01 * s) + (a02 * c),
			(a03),
			(a10),
			(a11 * c) + (a12 * -s),
			(a11 * s) + (a12 * c),
			(a13),
			(a20),
			(a21 * c) + (a22 * -s),
			(a21 * s) + (a22 * c),
			(a23),
			(a30),
			(a31 * c) + (a32 * -s),
			(a31 * s) + (a32 * c),
			(a33)
		};
		return *this;
	}

	Matrix4& Matrix4::rotateY(float radians)
	{
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a03 = m_Values[M03];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a13 = m_Values[M13];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & a23 = m_Values[M23];
		const float & a30 = m_Values[M30];
		const float & a31 = m_Values[M31];
		const float & a32 = m_Values[M32];
		const float & a33 = m_Values[M33];
		const float c = cosf(radians);
		const float s = sinf(radians);
		m_Values = {
			(a00 * c) + (a02 * s),
			(a01),
			(a00 * -s) + (a02 * c),
			(a03),
			(a10 * c) + (a12 * s),
			(a11),
			(a10 * -s) + (a12 * c),
			(a13),
			(a20 * c) + (a22 * s),
			(a21),
			(a20 * -s) + (a22 * c),
			(a23),
			(a30 * c) + (a32 * s),
			(a31),
			(a30 * -s) + (a32 * c),
			(a33)
		};
		return *this;
	}

	Matrix4& Matrix4::rotateZ(float radians)
	{
		
		const float & a00 = m_Values[M00];
		const float & a01 = m_Values[M01];
		const float & a02 = m_Values[M02];
		const float & a03 = m_Values[M03];
		const float & a10 = m_Values[M10];
		const float & a11 = m_Values[M11];
		const float & a12 = m_Values[M12];
		const float & a13 = m_Values[M13];
		const float & a20 = m_Values[M20];
		const float & a21 = m_Values[M21];
		const float & a22 = m_Values[M22];
		const float & a23 = m_Values[M23];
		const float & a30 = m_Values[M30];
		const float & a31 = m_Values[M31];
		const float & a32 = m_Values[M32];
		const float & a33 = m_Values[M33];
		const float c = cosf(radians);
		const float s = sinf(radians);
		m_Values = {
			(a00 * c) + (a01 * -s),
			(a00 * s) + (a01 * c),
			(a02),
			(a03),
			(a10 * c) + (a11 * -s),
			(a10 * s) + (a11 * c),
			(a12),
			(a13),
			(a20 * c) + (a21 * -s),
			(a20 * s) + (a21 * c),
			(a22),
			(a23),
			(a30 * c) + (a31 * -s),
			(a30 * s) + (a31 * c),
			(a32),
			(a33)
		};
		return *this;
	}

	Matrix4& Matrix4::operator*=(Matrix4& multiply)
	{
		return this->multiply(multiply);
	}

	bool Matrix4::operator==(Matrix4& toCompare)
	{
		return memcmp(&m_Values, &toCompare.m_Values, 16 * sizeof(float)) == 0;
	}
	void Matrix4::operator=(Matrix4& toCopy)
	{
		memcpy(&m_Values, &toCopy, 16 * sizeof(float));
	}
	void Matrix4::operator=(const std::initializer_list<float> list)
	{
		int count = 0;
		for (float value : list)
		{
			m_Values[count++] = value;
		}
	}
	float& Matrix4::operator[](int index)
	{
		return m_Values[index];
	}

	std::ostream & operator<<(std::ostream & stream, Matrix4 & matrix)
	{
		stream << "Matrix4(\r\n";
		for (int i = 0; i < 16; i += 4)
		{
			stream << "\t" << matrix[i] << ", " << matrix[i + 1] << ", " << matrix[i + 2] << ", " << matrix[i + 3] << "\r\n";
		}
		stream << ")";
		return stream;
	}
}
