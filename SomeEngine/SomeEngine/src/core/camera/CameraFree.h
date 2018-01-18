#pragma once
#include "math\Vector3.h"
#include "math\Matrix4.h"

namespace engine::core
{
	class CameraFree
	{
	private:
		float m_Yaw, m_Pitch, m_Speed;
		engine::math::Vector3 m_Forward, m_Up, m_Right, m_Position, m_WorldUp;
		engine::math::Matrix4 m_View;
	public:
		CameraFree(engine::math::Vector3 pos = engine::math::Vector3(), engine::math::Vector3 forward = engine::math::Vector3::Forward(), engine::math::Vector3 up = engine::math::Vector3::Up(),
			engine::math::Vector3 right = engine::math::Vector3::Right(), engine::math::Vector3 worldUp = engine::math::Vector3::Up(), float pitch = 0.0f, float yaw = 0.0f, float speed = 1.0f);

	private:
		void recombobulate();

	};
}