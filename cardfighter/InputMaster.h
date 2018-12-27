#pragma once
#include "InputManager.h"


class InputMaster
{
public:
	static void register_manager(InputManager& manager);
	static void unregister_manager(InputManager& manager);

	static bool input(sf::Event& event);

private:
	static std::vector<InputManager*> input_managers;
};