#include "InputMaster.h"

void InputMaster::register_manager(InputManager& manager)
{
	input_managers.push_back(&manager);
}

void InputMaster::unregister_manager(InputManager& manager)
{
	input_managers.erase(std::remove(input_managers.begin(), input_managers.end(), &manager), input_managers.end()); 
}

bool InputMaster::input(sf::Event& event)
{
	unsigned i = 0;
	bool event_handled = false;
	while (!event_handled && i < input_managers.size())
	{
		event_handled = InputMaster::input_managers.at(i)->delegate(event);
		i++;
	}
	return event_handled;
}

std::vector<InputManager*> InputMaster::input_managers = std::vector<InputManager*>();