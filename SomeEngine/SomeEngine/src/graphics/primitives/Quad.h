#pragma once
#include "graphics\data\Mesh.h"

namespace engine::graphics
{
	class Quad
	{
	private:
		Mesh m_Mesh;
	public:
		Quad();
		Quad(engine::math::Vector3 topRight, engine::math::Vector3 bottomRight, engine::math::Vector3 bottomLeft, engine::math::Vector3 topLeft);
		Quad(float* floatArr);

		inline Mesh& getMesh() { return m_Mesh; }
	};
}