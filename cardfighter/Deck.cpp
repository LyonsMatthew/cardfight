#include "Deck.h"
#include "PlayerMouseController.h"

Deck::Deck()
{
	Deck::set_zone_properties();
}

Deck::~Deck()
{
}

void Deck::update()
{
}

void Deck::set_zone_properties()
{
	Deck::zone_rectangle.setSize(sf::Vector2f(Settings::DECK_WIDTH, Settings::WIDGET_HEIGHT));
	Deck::zone_rectangle.setOrigin(zone_rectangle.getSize().x/2, zone_rectangle.getSize().y/2);
	Deck::zone_rectangle.setPosition(Settings::DECK_POSITION);
}

void Deck::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(zone_rectangle);
}

Card* Deck::hover_card(sf::Vector2i position)
{
	if (cards.empty()) return nullptr;
	if (PlayerMouseController::mouse_in(position, cards.at(0)->card_bounds()))
		return cards.back();
	return nullptr;
}

void Deck::reverse()
{
	sf::Vector2f pos = Deck::zone_rectangle.getPosition();
	Deck::zone_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

Card* Deck::draw_card()
{
	if (cards.empty()) return nullptr;
	Card* card = cards.front();
	return card;
}

void Deck::search_card(Card& card)
{
}

void Deck::scry(int number_to_scry)
{
}

void Deck::shuffle()
{
}

void Deck::create_card_at_bottom(Card* card)
{
	cards.push_back(card);
	register_invoker(*card);
	sf::Vector2f pos = Deck::zone_rectangle.getPosition();
	card->set_position(sf::Vector2f(pos.x, pos.y));
}

void Deck::register_invokers()
{
}
