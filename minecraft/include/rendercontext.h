#ifndef MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
#define MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
#pragma once

#include <glm/glm.hpp>

struct GLFWwindow;

namespace engine::core
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
	};
}

#endif //MINECRAFT__CORE_RENDERCONTEXT_H