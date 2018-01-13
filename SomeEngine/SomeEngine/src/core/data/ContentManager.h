#pragma once
#include "graphics\shader\Shader.h"
#include <string>

namespace engine
{
	namespace core
	{
		class ContentManager
		{
		private:

		public:
			ContentManager();
			~ContentManager();

			engine::graphics::Shader loadShader(const std::string& fragPath, const std::string& vertPath);
		private:
			std::string& loadFileToString(const std::string& filepath);
			const unsigned int compileShader(unsigned int shader, std::string& src, unsigned int programId);
		};
	}
}

