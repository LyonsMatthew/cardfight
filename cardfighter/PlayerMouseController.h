#pragma once
#include "PlayerController.h"

class PlayerMouseController : public InputManager
{
public:
	PlayerMouseController();
	~PlayerMouseController();

	bool delegate(sf::Event& event) override;

	bool input_mouse_button_pressed(sf::Event& event) override;
	bool input_mouse_moved(sf::Event& event) override;

	static bool mouse_in(sf::Vector2i& position, sf::FloatRect bounds);

private:
};