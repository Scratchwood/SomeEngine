#pragma once
#include "graphics\data\VertexTextureNormalColor.h"
#include <GL\glew.h>
#include <vector>


namespace engine::graphics
{
	struct Mesh
	{
		std::vector<GLuint> indices;
		std::vector<VertexTextureNormalColor> vertices;

		GLuint vao, vbo, ebo;

		Mesh() {};
		Mesh(std::vector<GLuint> i, std::vector<VertexTextureNormalColor> v)
		{
			this->indices = i;
			this->vertices = v;

			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			glGenBuffers(1, &vbo);
			glGenBuffers(1, &ebo);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexTextureNormalColor), &vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureNormalColor), (const GLvoid*)0);

			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexTextureNormalColor), (const GLvoid*)offsetof(VertexTextureNormalColor, VertexTextureNormalColor::uv));

			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureNormalColor), (const GLvoid*)offsetof(VertexTextureNormalColor, VertexTextureNormalColor::normal));

			glEnableVertexAttribArray(3);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureNormalColor), (const GLvoid*)offsetof(VertexTextureNormalColor, VertexTextureNormalColor::color));

			glBindVertexArray(0);
		}
	};
}