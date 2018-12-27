#include "PlayerController.h"
#include "PlayerAction.h"
#include "PlayerMouseController.h"
#include "Player.h"

PlayerController::PlayerController(PlayerAction& pa, Player& player)
	: pa(pa)
{
	PlayerController::input_manager = std::make_shared<PlayerMouseController>();
	deck = &player.deck;
	hand = &player.hand;
	discard = &player.discard;
	playzone = &player.playzone;
	input_manager->register_observer(*this);
}

PlayerController::~PlayerController()
{
}

bool PlayerController::inputMouseButtonPressed(sf::Mouse::Button)
{
	bool event_handled = true;
	if (hovered_zone == deck) {
		pa.draw_card();
	} else {
		event_handled = false;
	}
	return event_handled;
}

bool PlayerController::inputMouseButtonReleased(sf::Mouse::Button)
{
	return false;
}

bool PlayerController::inputMouseHovered(sf::Vector2i& position)
{
	bool event_handled = true;
	if (PlayerMouseController::mouse_in(position, deck->zone_bounds())) { 
		hover_card(deck->hover_card(position)); hover_zone(deck);
	} else if (PlayerMouseController::mouse_in(position, hand->zone_bounds())) {
		hover_card(hand->hover_card(position)); hover_zone(hand);
	} else {
		unhover_card(); unhover_zone(); event_handled = false;
	}
	return event_handled;
}

void PlayerController::hover_card(Card* card)
{
	unhover_card();
	if (card == nullptr) return;
	hovered_card = card;
	card->hover();
}

void PlayerController::unhover_card()
{
	if (hovered_card != nullptr) { hovered_card->unhover(); }
	hovered_card = nullptr;
}

void PlayerController::hover_zone(Zone * zone)
{
	unhover_zone();
	hovered_zone = zone;
}

void PlayerController::unhover_zone()
{
	hovered_zone = nullptr;
}
