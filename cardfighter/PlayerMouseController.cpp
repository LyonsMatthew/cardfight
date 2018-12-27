#include "PlayerMouseController.h"
#include "Player.h"

PlayerMouseController::PlayerMouseController()
{
	InputMaster::register_manager(*this);
}

PlayerMouseController::~PlayerMouseController()
{
	InputMaster::unregister_manager(*this);
}

bool PlayerMouseController::delegate(sf::Event& event)
{
	switch(event.type)
	{
	case sf::Event::MouseButtonPressed:
		return PlayerMouseController::input_mouse_button_pressed(event);
	case sf::Event::MouseMoved:
		return PlayerMouseController::input_mouse_moved(event);
	}
	return false;
}

bool PlayerMouseController::input_mouse_button_pressed(sf::Event & event)
{
	unsigned i = 0;
	bool event_handled = false;
	while (!event_handled && i < input_observers.size())
	{
		event_handled = input_observers.at(i)->inputMouseButtonPressed(event.mouseButton.button);
		i++;
	} 
	return event_handled;
}

bool PlayerMouseController::input_mouse_moved(sf::Event& event)
{
	unsigned i = 0;
	sf::Vector2i mouse_pos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
	bool event_handled = false;
	while (!event_handled && i < input_observers.size())
	{
		event_handled = input_observers.at(i)->inputMouseHovered(mouse_pos);
		i++;
	} 
	return event_handled;
}

bool PlayerMouseController::mouse_in(sf::Vector2i& position, sf::FloatRect bounds)
{
	return (position.x > bounds.left && position.x < bounds.left+bounds.width
		&& position.y > bounds.top && position.y < bounds.top+bounds.height);
}