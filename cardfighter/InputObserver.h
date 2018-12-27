#pragma once
#include <SFML/Graphics.hpp>

class InputObserver
{
public:
	virtual bool inputKeyPressed(sf::Keyboard::Key) = 0;
	virtual bool inputKeyReleased(sf::Keyboard::Key) = 0;

	virtual bool inputMouseButtonPressed(sf::Mouse::Button) = 0;
	virtual bool inputMouseButtonReleased(sf::Mouse::Button) = 0;
	virtual bool inputMouseHovered(sf::Vector2i& position) = 0;

	virtual bool inputJoystickButtonPressed(int joystickIndex, int joystickButton) = 0;
	virtual bool inputJoystickAxisMoved(int joystickIndex, int joystickAxis, int axisValue) = 0;

	bool operator==(const InputObserver& observer)
	{
		return this == &observer;
	}

private:

};