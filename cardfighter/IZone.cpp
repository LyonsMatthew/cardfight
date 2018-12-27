#include "IZone.h"

IZone::IZone()
{
	IZone::set_zone_properties();
}

IZone::~IZone()
{
}

void IZone::update()
{
}

void IZone::set_zone_properties()
{
	IZone::size_percent = 0.2f;
	IZone::zone_rectangle.setSize(sf::Vector2f(Settings::PLAY_WIDTH*IZone::size_percent, Settings::WIDGET_HEIGHT));
	IZone::zone_rectangle.setOrigin(zone_rectangle.getSize().x/2, zone_rectangle.getSize().y/2);
	IZone::zone_rectangle.setPosition(sf::Vector2f(Settings::PLAY_POSITION.x, Settings::PLAY_POSITION.y));
}

void IZone::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(zone_rectangle);
}

Card * IZone::hover_card(sf::Vector2i position)
{
	return nullptr;
}

void IZone::reverse()
{
	sf::Vector2f pos = IZone::zone_rectangle.getPosition();
	IZone::zone_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

void IZone::register_invokers()
{
}
