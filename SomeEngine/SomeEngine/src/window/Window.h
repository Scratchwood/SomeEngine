#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>

namespace engine::window
 {
	/// Provides a wrapper for a GLFW Window
	class Window
	{
	private:
		int m_Width, m_Height;
		std::string m_Name;
		GLFWwindow* m_Window;

	public:
		Window(std::string& name, int width, int height);
		~Window();

		void clear() const;
		void update();

		inline bool isClosed() const { return glfwWindowShouldClose(m_Window) == 1; }
		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

	private:
		bool initialize();
		friend static void APIENTRY openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
		friend static void onWindowResize(GLFWwindow* window, int width, int height);
		friend static void onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void onMouseMove(GLFWwindow* window, double mx, double my);
		friend static void onMouseChange(GLFWwindow* window, int button, int action, int mods);
	};
}