#pragma once
#include <iostream>
#include "math\Vector4.h"
namespace engine::graphics
{
	struct Color
	{
		float r, g, b, a;

		Color();
		Color(int hex, const float a = 1.0f);
		Color(const float r, const float g, const float b, const float a = 1.0f);
		~Color();

		void setHex(const int hex);
		void setRGB(const float r, const float g, const float b);
		void setRGBA(const float r, const float g, const float b, const float a = 1.0f);

		const inline engine::math::Vector4 toVector4() const { return engine::math::Vector4(r, g, b, a); };

		friend std::ostream& operator<<(std::ostream& stream, const Color& color);
	};
}
