#include "Color.h"

namespace engine::graphics
{
	Color::Color() : r(1), g(1), b(1), a(1)
	{
	}

	Color::Color(int hex, const float a) : a(a)
	{
		setHex(hex);
	}

	Color::Color(const float r, const float g, const float b, const float a) : r(r), g(g), b(b), a(a)
	{
	}


	Color::~Color()
	{
	}

	void Color::setHex(const int hex)
	{
		r = ((hex >> 16) & 0xFF) / 255.f;
		g = ((hex >> 8) & 0xFF) / 255.f;
		b = ((hex) & 0xFF) / 255.f;
	}

	void Color::setRGB(const float r, const float g, const float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	void Color::setRGBA(const float r, const float g, const float b, const float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	std::ostream & operator<<(std::ostream & stream, const Color & color)
	{
		return stream << "Color(R: " << color.r << ", G: " << color.g << ", B: " << color.b << ", A: " << color.a << ")";
	}
}

