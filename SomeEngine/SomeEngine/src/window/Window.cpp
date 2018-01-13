#include "Window.h"
#include <iostream>
#include <vector>

engine::window::Window::Window(std::string & name, int width, int height)
	: m_Name(name), m_Width(width), m_Height(height)
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
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		std::cout << "GL ERROR: " << error << std::endl;
		getDebugMessages(1);
	}
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
	glEnable(GL_DEBUG_OUTPUT);
	glClearColor(0.2f, 0.7f, 0.5f, 1.0f);
	return true;
}

void engine::window::Window::getDebugMessages(GLuint count)
{
	GLint maxMsgLen = 0;
	glGetIntegerv(GL_MAX_DEBUG_MESSAGE_LENGTH, &maxMsgLen);

	std::vector<GLchar> msgData(count * maxMsgLen);
	std::vector<GLenum> sources(count);
	std::vector<GLenum> types(count);
	std::vector<GLenum> severities(count);
	std::vector<GLuint> ids(count);
	std::vector<GLsizei> lengths(count);

	GLuint numFound = glGetDebugMessageLog(count, msgData.size(), &sources[0], &types[0], &ids[0], &severities[0], &lengths[0], &msgData[0]);

	sources.resize(numFound);
	types.resize(numFound);
	severities.resize(numFound);
	ids.resize(numFound);
	lengths.resize(numFound);

	std::vector<std::string> messages;
	messages.reserve(numFound);

	std::vector<GLchar>::iterator currPos = msgData.begin();
	for (size_t msg = 0; msg < lengths.size(); ++msg)
	{
		messages.push_back(std::string(currPos, currPos + lengths[msg] - 1));
		currPos = currPos + lengths[msg];
	}
	for (size_t i = 0; i < messages.size(); i++) {
		std::cout << messages.at(i).c_str() << std::endl;
	}
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
