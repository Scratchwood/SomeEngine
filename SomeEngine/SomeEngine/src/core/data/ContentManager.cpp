#include "ContentManager.h"
#include <GL\glew.h>
#include <fstream>
#include <sstream>
#include <vector>

namespace engine
{
	namespace core
	{
		ContentManager::ContentManager()
		{
		}


		ContentManager::~ContentManager()
		{
		}

		engine::graphics::Shader ContentManager::loadShader(const std::string & fragPath, const std::string & vertPath)
		{
			GLuint id = glCreateProgram();
			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertexSourceStr = loadFileToString(vertPath);
			std::string fragmentSourceStr = loadFileToString(fragPath);

			GLuint vertexCompiled = compileShader(vertexShader, vertexSourceStr, id);
			GLuint fragmentCompiled = compileShader(fragmentShader, fragmentSourceStr, id);
			if (vertexCompiled == 0 || fragmentCompiled == 0) 
			{
				return engine::graphics::Shader();
			}

			glLinkProgram(id);
			glValidateProgram(id);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return engine::graphics::Shader(id, vertexShader, fragmentShader);;
		}

		std::string& ContentManager::loadFileToString(const std::string& filepath)
		{
			std::ifstream file;
			file.open(filepath);
			std::stringstream stream;
			stream << file.rdbuf();
			std::string result = stream.str();
			file.close();
			return result;
		}

		const unsigned int ContentManager::compileShader(unsigned int shader, std::string & src, unsigned int programId)
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
}
