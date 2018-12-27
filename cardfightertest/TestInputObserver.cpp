#include "TestInputObserver.h"

TestInputObserver::TestInputObserver()
{
	cat = 0;
}

TestInputObserver::TestInputObserver(int cat)
{
	TestInputObserver::cat = cat;
}

bool TestInputObserver::inputKeyPressed(sf::Keyboard::Key)
{
	return false;
}

bool TestInputObserver::inputKeyReleased(sf::Keyboard::Key)
{
	return false;
}

bool TestInputObserver::inputMouseButtonPressed(sf::Mouse::Button)
{
	return false;
}

bool TestInputObserver::inputMouseButtonReleased(sf::Mouse::Button)
{
	return false;
}

bool TestInputObserver::inputMouseHovered(sf::Vector2i & position)
{
	return false;
}

bool TestInputObserver::inputJoystickButtonPressed(int joystickIndex,int joystickButton)
{
	return false;
}

bool TestInputObserver::inputJoystickAxisMoved(int joystickIndex,int joystickAxis,int axisValue)
{
	return false;
}