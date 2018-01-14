#include "Window.h"
#include <iostream>
#include <vector>

engine::window::Window::Window(std::string & name, int width, int height)
	: m_Name(name), m_Width(width), m_Height(height), m_ClearColor(0.39f, 0.58f, 0.92f, 1.0f)
{
	if (!initialize())
	{
		glfwTerminate();
	}
}

engine::window::Window::~Window()
{
	glfwTerminate();
}

void engine::window::Window::clear() const
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void engine::window::Window::update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

bool engine::window::Window::initialize()
{
	if (!glfwInit())
	{
		std::cout << "failed to initiate glfw" << std::endl;
		return false;
	}
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE); // add toggle for non-debug..
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Name.c_str(), NULL, NULL);
	if (!m_Window)
	{
		std::cout << "failed to create GLFW Window" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(0); // VSYNC
	glfwSetFramebufferSizeCallback(m_Window, onWindowResize);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "failed to initialize GLEW" << std::endl;
		return false;
	}
	std::cout << "GL Version: " << glGetString(GL_VERSION) << std::endl;
	//glfw callbacks
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetKeyCallback(m_Window, onKeyChange);
	glfwSetMouseButtonCallback(m_Window, onMouseChange);
	glfwSetCursorPosCallback(m_Window, onMouseMove);
	// gl options
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(openglCallbackFunction, nullptr);
	GLuint unusedIds = 0;
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE,	0, &unusedIds, true);
	glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
	return true;
}

void APIENTRY engine::window::openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	std::string errorMsg;
	errorMsg = "Type: ";
	switch (type) {
	case GL_DEBUG_TYPE_ERROR:
		errorMsg += "ERROR";
		break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		errorMsg += "DEPRECATED_BEHAVIOR";
		break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		errorMsg += "UNDEFINED_BEHAVIOR";
		break;
	case GL_DEBUG_TYPE_PORTABILITY:
		errorMsg += "PORTABILITY";
		break;
	case GL_DEBUG_TYPE_PERFORMANCE:
		errorMsg += "PERFORMANCE";
		break;
	case GL_DEBUG_TYPE_OTHER:
		errorMsg += "OTHER";
		break;
	}
	errorMsg += "\nMessage: ";
	errorMsg.append(message);

	errorMsg += "\nId: " + id;
	errorMsg += "\nSeverity: ";
	switch (severity) {
	case GL_DEBUG_SEVERITY_LOW:
		errorMsg += "LOW";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		errorMsg += "MEDIUM";
		break;
	case GL_DEBUG_SEVERITY_HIGH:
		errorMsg += "HIGH";
		break;
	}
	std::cout << errorMsg << std::endl; // replace with some logger
}


void engine::window::onWindowResize(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Width = width;
	win->m_Height = height;
}

void engine::window::onKeyChange(GLFWwindow * window, int key, int scancode, int action, int mods)
{

}

void engine::window::onMouseMove(GLFWwindow * window, double mx, double my)
{

}

void engine::window::onMouseChange(GLFWwindow * window, int button, int action, int mods)
{

}
