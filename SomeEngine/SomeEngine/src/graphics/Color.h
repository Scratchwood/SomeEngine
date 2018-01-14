#pragma once
#include <iostream>
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

		friend std::ostream& operator<<(std::ostream& stream, const Color& color);
	};
}
