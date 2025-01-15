#ifndef MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
#define MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
#pragma once

#include <glm/glm.hpp>

struct GLFWwindow;

namespace engine::Core
{
	struct RenderContextDescriptor
	{
		const char* title = "Minecraft";
		glm::ivec2	size = { 800, 600};
		bool		fullscreen = false;
		bool		resizable = true;
	};

	class RenderContext
	{
	private:
		GLFWwindow* m_window;



	public:
		explicit RenderContext(const RenderContextDescriptor& desc);
		~RenderContext() noexcept;

		GLFWwindow* GetWindow();

		bool		SwapBuffer();
		void		MouseCallback(GLFWwindow* window, double xpos, double ypos);
		void		ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		void		ProcessInput(GLFWwindow* window);
	};
}

#endif //MINECRAFT__CORE_RENDERCONTEXT_H