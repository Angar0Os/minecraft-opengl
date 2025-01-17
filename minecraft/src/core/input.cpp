#include <core/input.h>
#include <core/rendercontext.h>

#include <game/gametimehandler.h>

#include <iostream>

#include <GLFW/glfw3.h>

using namespace game;
using namespace engine::core;

Inputs::Inputs()
{

}

Inputs::~Inputs()
{

}

void Inputs::UpdateInputs(RenderContext* window, GameTimeHandler timer)
{

}

InputAction* Inputs::CreateInputAction(const char* name, unsigned int key, EInputType inputType)
{
	InputAction* newInputAction = new InputAction();
	newInputAction->Key = key;
	newInputAction->InputType = inputType;

	m_inputs[name] = newInputAction;
	return newInputAction;
}

InputAction* Inputs::GetInputByName(const char* name)
{
	return m_inputs[name];
}

void Inputs::BindMouseDeltaPosition(std::function<void(float, float, GameTimeHandler)> action)
{
	m_mouseDeltaChangedActions.push_back(action);
}

void Inputs::UpdateMousePosition(GLFWwindow* window, GameTimeHandler timer)
{
	double mX, mY;
	glfwGetCursorPos(window, &mX, &mY);

	float deltaMouseX = mX - m_MouseX;
	float deltaMouseY = mY - m_MouseY;

	if (deltaMouseX + deltaMouseY != 0.0f)
	{
		for (auto& action : m_mouseDeltaChangedActions)
		{
			action(deltaMouseX, deltaMouseY, timer);
		}
	}

	m_MouseX = mX;
	m_MouseY = mY;
}