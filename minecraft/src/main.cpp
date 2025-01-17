#include <iostream>

#include <core/rendercontext.h>

using namespace engine::core;

int main(int argc, char** argv)
{
	RenderContext rCtx({"Minecraft"});

	do 
	{

	} while (rCtx.SwapBuffer());

	std::cout << "Hello world" << std::endl;
	return 0;
}