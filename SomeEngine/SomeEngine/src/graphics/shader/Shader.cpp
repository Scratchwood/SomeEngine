#include "Shader.h"
#include <GL\glew.h>
#include <vector>
namespace engine::graphics
{
	Shader::Shader()
	{
	}

	Shader::Shader(std::string fragSource, std::string vertSource)
	{
		m_Id = glCreateProgram();
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		m_VertexId = compileShader(vertexShader, vertSource, m_Id);
		m_FragmentId = compileShader(fragmentShader, fragSource, m_Id);

		// TODO: Error handling
		/*
		if (vertexCompiled == 0 || fragmentCompiled == 0)
		{
			return nullptr;
		}
		*/

		glLinkProgram(m_Id);
		glValidateProgram(m_Id);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


		glBindAttribLocation(m_Id, PositionLoc, "position");
		glBindAttribLocation(m_Id, TextureLoc, "uv");
		glBindAttribLocation(m_Id, NormalLoc, "normal");
		glBindAttribLocation(m_Id, ColorLoc, "color");
	}


	Shader::Shader(unsigned int id, unsigned int vertexId, unsigned int fragmentId)
		: m_Id(id), m_VertexId(vertexId), m_FragmentId(fragmentId)
	{
		glBindAttribLocation(m_Id, PositionLoc, "position");
		glBindAttribLocation(m_Id, TextureLoc, "uv");
		glBindAttribLocation(m_Id, NormalLoc, "normal");
		glBindAttribLocation(m_Id, ColorLoc, "color");
	}

	void Shader::enable() const
	{
		glUseProgram(m_Id);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

	void Shader::setUniform(const std::string & name, const float value)
	{
		glUniform1f(getLocation(name), value);
	}

	void Shader::setUniform(const std::string & name, const int value)
	{
		glUniform1i(getLocation(name), value);
	}

	void Shader::setUniform(const std::string & name, const unsigned int count, const float * value)
	{
		glUniform1fv(getLocation(name), count, value);
	}

	void Shader::setUniform(const std::string & name, const unsigned int count, const int * value)
	{
		glUniform1iv(getLocation(name), count, value);
	}

	void Shader::setUniform(const std::string & name, const engine::math::Matrix4 & value)
	{
		glUniformMatrix4fv(getLocation(name), 1, GL_FALSE, value.getArray());
	}

	void Shader::setUniform(const std::string & name, const engine::math::Vector2 & value)
	{
		glUniform2f(getLocation(name), value.x, value.y);
	}

	void Shader::setUniform(const std::string & name, const engine::math::Vector3 & value)
	{
		glUniform3f(getLocation(name), value.x, value.y, value.z);
	}

	void Shader::setUniform(const std::string & name, const engine::math::Vector4 & value)
	{
		glUniform4f(getLocation(name), value.x, value.y, value.z, value.w);
	}

	unsigned int Shader::getLocation(const std::string & name)
	{
		// since glGetUniformLocation is rather slow we cache it
		if (m_LocationMap[name] == NULL) {
			m_LocationMap[name] = glGetUniformLocation(m_Id, name.c_str());
		}
		return m_LocationMap[name];
	}

	const unsigned int Shader::compileShader(unsigned int shader, std::string & src, unsigned int programId)
	{
		const char* cSrc = src.c_str();
		glShaderSource(shader, 1, &cSrc, NULL);
		glCompileShader(shader);

		GLint result;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
			std::vector<char> error(len);
			glGetShaderInfoLog(shader, len, &len, &error[0]);
			std::string errorMsg(begin(error), end(error));
			std::cout << "Error compiling: " << std::endl << errorMsg << std::endl;
			glDeleteShader(shader);
			return 0;
		}
		glAttachShader(programId, shader);
		return 1;
	}
	

}
