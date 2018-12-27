#include "Card.h"
#include "Player.h"

Card::Card(int id, Player& player, Player& enemy)
	: id(id), player(player), enemy(enemy)
{
	set_initial_card_properties();
}

Card::~Card()
{
}

void Card::set_initial_card_properties()
{
	Card::card_rectangle.setOutlineThickness(-1 * Settings::CARD_OUTLINE_THICKNESS);
	Card::card_rectangle.setOutlineColor(sf::Color());
	Card::card_rectangle.setFillColor(sf::Color(255,255,255,255));
	Card::set_size(sf::Vector2f(Settings::CARD_WIDTH, Settings::CARD_HEIGHT));
}

void Card::set_position(sf::Vector2f position)
{
	card_rectangle.setPosition(position);
}

void Card::set_size(sf::Vector2f size)
{
	card_rectangle.setSize(size);
	Card::card_rectangle.setOrigin(sf::Vector2f(card_rectangle.getSize().x/2, card_rectangle.getSize().y/2));
}

void Card::hover()
{
	Card::card_rectangle.setOutlineThickness(Settings::CARD_OUTLINE_THICKNESS*2);
}

void Card::unhover()
{
	Card::card_rectangle.setOutlineThickness(Settings::CARD_OUTLINE_THICKNESS);
}

sf::FloatRect Card::card_bounds()
{
	return card_rectangle.getGlobalBounds();
}

void Card::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(card_rectangle);
}

void Card::reverse()
{
	sf::Vector2f pos = Card::card_rectangle.getPosition();
	Card::card_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

void Card::register_invokers()
{
}
