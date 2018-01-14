#pragma once
#include "graphics\shader\Shader.h"
#include <string>
#include <vector>
#include <memory>

namespace engine::core
{
	class ContentManager
	{
	private:
#define MaxShaders 8

#define ShaderPtr std::unique_ptr<engine::graphics::Shader>

		std::vector<engine::graphics::Shader> m_Shaders;

	public:
		ContentManager();
		~ContentManager();

		ShaderPtr loadShader(const std::string& fragPath, const std::string& vertPath);
	private:
		std::string loadFileToString(const std::string& filepath);
		const unsigned int compileShader(unsigned int shader, std::string& src, unsigned int programId);
	};
}


