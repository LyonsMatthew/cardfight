#include "InputManager.h"	

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::register_observer(InputObserver& observer)
{
	input_observers.push_back(&observer);
}

void InputManager::unregister_observer(InputObserver& observer)
{
	input_observers.erase(std::remove(input_observers.begin(), input_observers.end(), &observer), input_observers.end()); 
}