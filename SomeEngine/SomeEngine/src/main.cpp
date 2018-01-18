#include "math\Vector2.h"
#include "math\Matrix4.h"
#include "graphics\shader\Shader.h"
#include "core\data\ContentManager.h"
#include "graphics\primitives\Quad.h"
#include "window\Window.h"
#include <iostream>
#include <string>


using namespace engine;
using namespace engine::math;
using namespace engine::window;
using namespace engine::graphics;
using namespace engine::core;

void main() 
{
	Vector2 v1 = Vector2(1, 1);
	Vector2 v2 = Vector2(2, 2);
	Vector2 v3 = v1 + v2;
	std::cout << v3 << std::endl;

	Matrix4 mat;
	mat.scale(2.0f, 2.0f, 2.0f);
	std::cout << mat << std::endl;

	std::string name = "SomeEngine";
	Window w = Window(name, 800, 600);
	ContentManager cm = ContentManager();
	auto shader = cm.load<Shader>("resources/shaders/basic.frag", "resources/shaders/basic.vert");
	// auto string = cm.load<std::string>("resources/shaders/basic.frag");

	Quad quad = Quad(Vector3(0.5f, 0.5f, 0.0f), Vector3(0.5f, -0.5f, 0.0f), Vector3(-0.5f, -0.5f, 0.0f), Vector3(-0.5f, 0.5f, 0.0f));
	// #define EMILTRAMS
	double d = M_PI_2;
	float f = static_cast<float>(M_PI_2);
	
	std::cout << "math_define: " << M_PI_2 << std::endl;
	std::cout << "float: " << static_cast<float>(M_PI_2) << std::endl;

#ifdef EMILTRAMS
	shader->enable();
	GLuint indices[6]{
		0, 3, 1,
		3, 2, 1
	};
	
	GLfloat vertices[12] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint vao;
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);
	glGenVertexArrays(1, &vao);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, quad.getMesh().indices.size() * sizeof(GLuint), &quad.getMesh().indices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	glBindVertexArray(vao);
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	}
	glBindVertexArray(NULL);
#endif

	while (!w.isClosed())
	{
		w.clear();
		shader->enable();
#ifdef EMILTRAMS
		// glBindBuffer(GL_ARRAY_BUFFER, m_GLBuffers[BUFFER_INSTANCE]);
		// glBufferSubData(GL_ARRAY_BUFFER, 0, m_Count * ((3 * 3) + 4 + 1) * sizeof(GL_FLOAT), m_InstanceDataArray);
		glBindVertexArray(vao);
		//draw 3 vertices as triangles
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
		glBindVertexArray(NULL);
#endif

		glBindVertexArray(quad.getMesh().vao);
		glBindBuffer(GL_ARRAY_BUFFER, quad.getMesh().vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad.getMesh().ebo);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		shader->disable();
		w.update();
	}
}