#pragma once
#include "../CardFighter/InputObserver.h"

class TestInputObserver : public InputObserver
{
public:
	TestInputObserver();
	TestInputObserver(int cat);

	bool inputKeyPressed(sf::Keyboard::Key) override;
	bool inputKeyReleased(sf::Keyboard::Key) override;

	bool inputMouseButtonPressed(sf::Mouse::Button) override;
	bool inputMouseButtonReleased(sf::Mouse::Button) override;
	bool inputMouseHovered(sf::Vector2i& position) override;

	bool inputJoystickButtonPressed(int joystickIndex, int joystickButton) override;
	bool inputJoystickAxisMoved(int joystickIndex, int joystickAxis, int axisValue) override;

	int cat;

private:
};