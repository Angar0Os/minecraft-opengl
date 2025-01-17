#ifndef MINECRAFT__ENGINE_CORE_INPUTACTION_H
#define MINECRAFT__ENGINE_CORE_INPUTACTION_H
#pragma once

#include <functional>
#include <vector>
#include <game/gametimehandler.h>

using namespace game;
using f_tHandler = std::function<void(GameTimeHandler)>;

namespace engine::core
{
	enum EInputType
	{
		E_Keyboard,
		E_Mouse
	};

	class InputAction
	{
	private:
		std::vector<f_tHandler> pressAction;
		std::vector<f_tHandler> pressDownAction;
		std::vector<f_tHandler> releaseAction;
		std::vector<f_tHandler> releaseUpAction;

		
	public:
		unsigned int Key;
		EInputType InputType;

		inline void BindPressAction(f_tHandler action)
		{
			pressAction.push_back(action);
		}
		inline void BindPressDownAction(f_tHandler action)
		{
			pressDownAction.push_back(action);
		}
		inline void BindReleaseAction(f_tHandler action)
		{
			releaseAction.push_back(action);
		}
		inline void BindReleaseUpAction(f_tHandler action)
		{
			releaseUpAction.push_back(action);
		}
	};
}

#endif //MINECRAFT__ENGINE_CORE_INPUTACTION_H
