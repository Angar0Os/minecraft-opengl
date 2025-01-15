#ifndef MINECRAFT__RENDERCONTEXT_H
#define MINECRAFT__RENDERCONTEXT_H

#include <glm/glm.hpp>

struct GLFWwindow;

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
	GLFWwindow* m_window;

public:
	explicit RenderContext(const RenderContextDescriptor& desc);
	~RenderContext() noexcept;

	GLFWwindow* GetWindow();
	bool		SwapBuffer();
};

#endif //MINECRAFT__RENDERCONTEXT_H