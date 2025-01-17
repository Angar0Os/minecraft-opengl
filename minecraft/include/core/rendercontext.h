#ifndef MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
#define MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
#pragma once

#include <glm/glm.hpp>

struct GLFWwindow;

namespace engine::core
{
	struct RenderContextDescriptor
	{
		const char* title		= "Minecraft";
		glm::ivec2	size		= { 1600, 900 };
		bool		fullscreen	= false;
		bool		resizable	= true;
	};

	class RenderContext
	{
	private:
		GLFWwindow* m_window = nullptr;

		void ProcessKeyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods);
	public:
		explicit RenderContext(const RenderContextDescriptor& desc);
		~RenderContext() noexcept;

		inline GLFWwindow* GetWindow() const { return m_window; }

		bool SwapBuffer();
	};
}

#endif //MINECRAFT__ENGINE_CORE_RENDERCONTEXT_H
