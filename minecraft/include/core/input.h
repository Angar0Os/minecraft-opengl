#ifndef MINECRAFT__ENGINE_CORE_INPUT_H
#define MINECRAFT__ENGINE_CORE_INPUT_H
#pragma once

#include <vector>
#include <unordered_map>
#include <functional>

#include <core/inputaction.h>

using namespace game;

namespace game { struct GameTimeHandler; }

namespace engine::core
{
	class RenderContext;

	class Inputs
	{
	public:
		explicit Inputs();
		~Inputs() noexcept;

		void UpdateInputs(RenderContext* window, GameTimeHandler timer);

		InputAction* CreateInputAction(const char* name, unsigned int key, EInputType inputType = E_Keyboard);
		InputAction* GetInputByName(const char* name);

		void BindMouseDeltaPosition(std::function<void(float, float, GameTimeHandler)> action);

	private:
		double m_MouseX, m_MouseY;
		std::unordered_map<const char*, InputAction*> m_inputs;
		std::vector<std::function<void(float, float, GameTimeHandler)>> m_mouseDeltaChangedActions;

		void UpdateMousePosition(class GLFWwindow* window, GameTimeHandler timer);
	};
}

#endif //MINECRAFT__ENGINE_CORE_INPUT_H
