#pragma once
#include "graphics\shader\Shader.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <any>
namespace engine::core
{
	class ContentManager
	{
	private:
#define MaxShaders 8

#define ShaderPtr std::unique_ptr<engine::graphics::Shader>

		std::vector<engine::graphics::Shader> m_Shaders;
		std::unordered_map < std::string, std::vector<std::any>> m_Cache;

	public:
		ContentManager();
		~ContentManager();

		/*
			Accepts a unspecified number of parameters, which are loaded and passed into the specified file.
		*/
		template <typename T, typename... Targs>
		std::unique_ptr<T> load(Targs... args)
		{
			// TODO: check what way is preferred, this looks hacky, the below one is a bit nicer
			/* 
			std::string tId = typeid(T).name();
			m_Cache[tId].push_back(std::any(T(loadFileToString(args)...)));
			// auto pointer = std::make_unique<T>(loadFileToString(args)...);
			// TODO: Store cached copy of 
			return std::make_unique<T>(std::any_cast<T>(m_Cache[tId].back()));
			*/
			std::string tId = typeid(T).name();
			// TODO: lookup file content type and load binary or to string depending on type.
			// for instance, a texture file should probably be loaded into a buffer of numbers.
			T instance(loadFileToString(args)...);
			m_Cache[tId].push_back(&instance);
			return std::make_unique<T>(instance);
		}
		ShaderPtr loadShader(const std::string& fragPath, const std::string& vertPath);
	private:
		std::string loadFileToString(const std::string& filepath);
		const unsigned int compileShader(unsigned int shader, std::string& src, unsigned int programId);
	};
}


