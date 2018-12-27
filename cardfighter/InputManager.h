#pragma once
#include <vector>
#include "InputObserver.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void register_observer(InputObserver& observer);
	void unregister_observer(InputObserver& observer);

	virtual bool delegate(sf::Event& event) = 0;

	virtual bool input_mouse_button_pressed(sf::Event& event) = 0;
	virtual bool input_mouse_moved(sf::Event& event) = 0;

protected:
	std::vector<InputObserver*> input_observers;
};