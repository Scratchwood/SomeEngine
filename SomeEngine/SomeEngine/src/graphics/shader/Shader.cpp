#include "Shader.h"
#include <GL\glew.h>

engine::graphics::Shader::Shader()
{
}

engine::graphics::Shader::Shader(unsigned int id, unsigned int vertexId, unsigned int fragmentId)
	: m_Id(id), m_VertexId(vertexId), m_FragmentId(fragmentId)
{
	glBindAttribLocation(m_Id, PositionLoc, "position");
	glBindAttribLocation(m_Id, TextureLoc, "texCoords");
	glBindAttribLocation(m_Id, NormalLoc, "normal");
	glBindAttribLocation(m_Id, ColorLoc, "color");
}

void engine::graphics::Shader::enable() const
{
	glUseProgram(m_Id);
}

void engine::graphics::Shader::disable() const
{
	glUseProgram(0);
}

void engine::graphics::Shader::setUniform(const std::string & name, const float value)
{
	glUniform1f(getLocation(name), value);
}

void engine::graphics::Shader::setUniform(const std::string & name, const int value)
{
	glUniform1i(getLocation(name), value);
}

void engine::graphics::Shader::setUniform(const std::string & name, const unsigned int count, const float * value)
{
	glUniform1fv(getLocation(name), count, value);
}

void engine::graphics::Shader::setUniform(const std::string & name, const unsigned int count, const int * value)
{
	glUniform1iv(getLocation(name), count, value);
}

void engine::graphics::Shader::setUniform(const std::string & name, const engine::math::Vector2 & value)
{
	glUniform2f(getLocation(name), value.x, value.y);
}

void engine::graphics::Shader::setUniform(const std::string & name, const engine::math::Vector3 & value)
{
	glUniform3f(getLocation(name), value.x, value.y, value.z);
}

void engine::graphics::Shader::setUniform(const std::string & name, const engine::math::Vector4 & value)
{
	glUniform4f(getLocation(name), value.x, value.y, value.z, value.w);
}

unsigned int engine::graphics::Shader::getLocation(const std::string & name)
{
	// since glGetUniformLocation is rather slow we cache it
	if (m_LocationMap[name] == NULL) {
		m_LocationMap[name] = glGetUniformLocation(m_Id, name.c_str());
	}
	return m_LocationMap[name];
}
