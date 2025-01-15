#include <Core/rendercontext.h>
#include <Graphics/shader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

using namespace engine::graphics;

int main(int argc, char** argv)
{
	RenderContext	rCtx({ "MinecraftfGL", {800, 600} });
	Shader			shader;

	do
	{

	} while (rCtx.SwapBuffer());

	glfwTerminate();
	return 0;
}