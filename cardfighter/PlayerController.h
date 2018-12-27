#pragma once
#include "Card.h"
#include "Zone.h"
#include "InputMaster.h"
#include "Deck.h"
#include "Hand.h"
#include "Discard.h"
#include "PlayZone.h"

class Player;
class PlayerAction;

class PlayerController : public InputObserver
{
public:
	PlayerController(PlayerAction& pa, Player& player);
	~PlayerController();

	bool inputKeyPressed(sf::Keyboard::Key) override { return false; }
	bool inputKeyReleased(sf::Keyboard::Key) override { return false; }

	bool inputMouseButtonPressed(sf::Mouse::Button) override;
	bool inputMouseButtonReleased(sf::Mouse::Button) override;
	bool inputMouseHovered(sf::Vector2i& position) override;

	bool inputJoystickButtonPressed(int joystickIndex, int joystickButton) override { return false; }
	bool inputJoystickAxisMoved(int joystickIndex, int joystickAxis, int axisValue) override { return false; }

private:
	PlayerAction& pa;
	std::shared_ptr<InputManager> input_manager;

	Card* hovered_card;
	Zone* hovered_zone;

	void hover_card(Card* card);
	void unhover_card();
	void hover_zone(Zone* zone);
	void unhover_zone();

	Deck* deck;
	Hand* hand;
	Discard* discard;
	PlayZone* playzone;

};