#pragma once
#include <math.h>

namespace engine::math
{
	class MathsUtil
	{
	public:
		static inline float toRadians(float degrees)
		{
			return static_cast<float>(degrees * (M_PI / 180.0f));
		}
	};
}