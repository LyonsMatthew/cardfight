#include "DZone.h"

DZone::DZone()
{
	DZone::set_zone_properties();
}

DZone::~DZone()
{
}

void DZone::update()
{
}

void DZone::set_zone_properties()
{
	DZone::size_percent = 0.4f;
	DZone::zone_rectangle.setSize(sf::Vector2f(Settings::PLAY_WIDTH*DZone::size_percent, Settings::WIDGET_HEIGHT));
	DZone::zone_rectangle.setOrigin(zone_rectangle.getSize().x/2, zone_rectangle.getSize().y/2);
	DZone::zone_rectangle.setPosition(sf::Vector2f(Settings::WIDTH - (Settings::PADDING + 
	DZone::zone_rectangle.getSize().x/2 + Settings::WIDGET_OUTLINE_THICKNESS), Settings::PLAY_POSITION.y));
}

void DZone::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(zone_rectangle);
}

Card* DZone::hover_card(sf::Vector2i position)
{
	return nullptr;
}

void DZone::reverse()
{
	sf::Vector2f pos = DZone::zone_rectangle.getPosition();
	DZone::zone_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

void DZone::register_invokers()
{
}
