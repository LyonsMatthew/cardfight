#include "AZone.h"

AZone::AZone()
{
	AZone::set_zone_properties();
}

AZone::~AZone()
{
}

void AZone::update()
{
}

void AZone::set_zone_properties()
{
	AZone::size_percent = 0.4f;
	AZone::zone_rectangle.setSize(sf::Vector2f(Settings::PLAY_WIDTH*AZone::size_percent, Settings::WIDGET_HEIGHT));
	AZone::zone_rectangle.setOrigin(zone_rectangle.getSize().x/2, zone_rectangle.getSize().y/2);
	AZone::zone_rectangle.setPosition(sf::Vector2f(Settings::PADDING + AZone::zone_rectangle.getSize().x/2 + 
		Settings::WIDGET_OUTLINE_THICKNESS, Settings::PLAY_POSITION.y));
}

void AZone::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(zone_rectangle);
}

Card * AZone::hover_card(sf::Vector2i position)
{
	return nullptr;
}

void AZone::reverse()
{
	sf::Vector2f pos = AZone::zone_rectangle.getPosition();
	AZone::zone_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

void AZone::register_invokers()
{
}
