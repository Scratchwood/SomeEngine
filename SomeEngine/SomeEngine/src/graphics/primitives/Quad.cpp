#include "Quad.h"

engine::graphics::Quad::Quad()
{

}

engine::graphics::Quad::Quad(engine::math::Vector3 topRight, engine::math::Vector3 bottomRight, engine::math::Vector3 bottomLeft, engine::math::Vector3 topLeft)
{
	std::vector<VertexTextureNormalColor> vertices;

	VertexTextureNormalColor vertex1;
	vertex1.vertex = topRight;
	vertex1.uv = engine::math::Vector2(0, 0);
	vertex1.normal = engine::math::Vector3(0, 0, -1);
	vertex1.color = engine::math::Vector3(1, 0, 1);

	VertexTextureNormalColor vertex2;
	vertex2.vertex = bottomRight;
	vertex2.uv = engine::math::Vector2(0, 0);
	vertex2.normal = engine::math::Vector3(0, 0, -1);
	vertex2.color = engine::math::Vector3(1, 1, 0);

	VertexTextureNormalColor vertex3;
	vertex3.vertex = bottomLeft;
	vertex3.uv = engine::math::Vector2(0, 0);
	vertex3.normal = engine::math::Vector3(0, 0, -1);
	vertex3.color = engine::math::Vector3(1, 0, 0);

	VertexTextureNormalColor vertex4;
	vertex4.vertex = topLeft;
	vertex4.uv = engine::math::Vector2(0, 0);
	vertex4.normal = engine::math::Vector3(0, 0, -1);
	vertex4.color = engine::math::Vector3(1, 1, 1);
	
	vertices = { vertex1, vertex2, vertex3, vertex4 };
	std::vector<GLuint> indices = { 0, 3, 1, 3, 2, 1 };
	m_Mesh = Mesh(indices, vertices);
}

engine::graphics::Quad::Quad(float * floatArr)
{
	// to be continued...
}
