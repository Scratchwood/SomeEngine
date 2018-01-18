#include "CameraFree.h"
#include "math\MathsUtil.h"


namespace engine::core
{
	CameraFree::CameraFree(engine::math::Vector3 pos, engine::math::Vector3 forward, engine::math::Vector3 up, engine::math::Vector3 right, 
		engine::math::Vector3 worldUp, float pitch, float yaw, float speed) : m_Position(pos), m_Forward(forward), m_Up(up), m_Right(right),
		m_WorldUp(worldUp), m_Pitch(pitch), m_Yaw(yaw), m_Speed(speed)
	{
		recombobulate();
		m_View = engine::math::Matrix4();
		m_View.lookAt(m_Position, m_Position + m_Forward, m_Up);
	}

	void CameraFree::recombobulate()
	{
		m_Forward.x = cos(engine::math::MathsUtil::toRadians(m_Yaw)) * cos(engine::math::MathsUtil::toRadians(m_Pitch));
		m_Forward.y = sin(engine::math::MathsUtil::toRadians(m_Pitch));
		m_Forward.z = sin(engine::math::MathsUtil::toRadians(m_Yaw)) * cos(engine::math::MathsUtil::toRadians(m_Pitch));
		m_Forward.normalize();
		m_Right = m_Forward.cross(m_WorldUp);
		m_Right.normalize();
		m_Up = m_Right.cross(m_Forward);
		m_Up.normalize();
	}
}

