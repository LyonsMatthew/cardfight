#include "Discard.h"
#include <iostream>

Discard::Discard()
{
	set_zone_properties();
}

Discard::~Discard()
{
}

void Discard::update()
{
}

void Discard::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(zone_rectangle);
}

Card * Discard::hover_card(sf::Vector2i position)
{
	return nullptr;
}

void Discard::reverse()
{
	sf::Vector2f pos = Discard::zone_rectangle.getPosition();
	Discard::zone_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

void Discard::set_zone_properties()
{
	Discard::zone_rectangle.setSize(sf::Vector2f(Settings::DISCARD_WIDTH, Settings::WIDGET_HEIGHT));
	Discard::zone_rectangle.setOrigin(zone_rectangle.getSize().x/2, zone_rectangle.getSize().y/2);
	Discard::zone_rectangle.setPosition(Settings::DISCARD_POSITION);
}

void Discard::register_invokers()
{
}
