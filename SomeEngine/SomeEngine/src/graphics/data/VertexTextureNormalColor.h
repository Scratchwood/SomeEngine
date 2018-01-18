#pragma once

#include "math\Vector3.h"
#include "math\Vector2.h"

namespace engine::graphics
{
	struct VertexTextureNormalColor
	{
		engine::math::Vector3 vertex;
		engine::math::Vector2 uv;
		engine::math::Vector3 normal;
		engine::math::Vector3 color;
	};
}