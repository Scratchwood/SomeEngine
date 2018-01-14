#pragma once
#include "math\Vector2.h"
#include "math\Vector3.h"
#include "math\Vector4.h"
#include <map>
#include <string>
namespace engine::graphics
{
	class Shader
	{
	private:
#define PositionLoc 0
#define TextureLoc 1
#define NormalLoc 2
#define ColorLoc 3
		unsigned int m_Id, m_VertexId, m_FragmentId;
		std::map<std::string, unsigned int> m_LocationMap;

	public:
		Shader();
		Shader(std::string fragSource, std::string vertSource);
		Shader(unsigned int id, unsigned int vertexId, unsigned int fragmentId);

		void enable() const;
		void disable() const;

		inline const unsigned int getId() const { return m_Id; };

		void setUniform(const std::string& name, const float value);
		void setUniform(const std::string& name, const int value);
		void setUniform(const std::string& name, const unsigned int count, const float* value);
		void setUniform(const std::string& name, const unsigned int count, const int* value);
		//void setUniform(const std::string& name, const maths::Matrix4& value);
		void setUniform(const std::string& name, const engine::math::Vector2& value);
		void setUniform(const std::string& name, const engine::math::Vector3& value);
		void setUniform(const std::string& name, const engine::math::Vector4& value);

	private:
		unsigned int getLocation(const std::string& name);
		const unsigned int compileShader(unsigned int shader, std::string & src, unsigned int programId);
	};
}
