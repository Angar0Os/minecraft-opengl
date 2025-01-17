#include <core/rendercontext.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")

using namespace engine::core;

RenderContext::RenderContext(const RenderContextDescriptor& desc)
{
	if (!glfwInit())
	{
		std::cerr << "Window did not openned properly" << std::endl;
		glfwTerminate();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	m_window = glfwCreateWindow(desc.size.x, desc.size.y, desc.title, nullptr, nullptr);

	if (!m_window)
	{
		std::cerr << "Window or OpenGL context creation failed." << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Unable to initialize GLEW." << std::endl;
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int w, int h)
		{
			glViewport(0, 0, w, h);
		});
}

RenderContext::~RenderContext()
{
	glfwDestroyWindow(m_window);
}

bool RenderContext::SwapBuffer()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();

	return !glfwWindowShouldClose(m_window);
}