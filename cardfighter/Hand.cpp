#include "Hand.h"
#include "PlayerMouseController.h"

Hand::Hand()
{
	Hand::set_zone_properties();
}

Hand::~Hand()
{
}

void Hand::update()
{
	set_card_positions();
}

void Hand::set_zone_properties()
{
	Hand::zone_rectangle.setSize(sf::Vector2f(Settings::HAND_WIDTH, Settings::WIDGET_HEIGHT));
	Hand::zone_rectangle.setOrigin(zone_rectangle.getSize().x/2, zone_rectangle.getSize().y/2);
	Hand::zone_rectangle.setPosition(Settings::HAND_POSITION);
}

void Hand::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
	target.draw(zone_rectangle);
}

Card* Hand::hover_card(sf::Vector2i position)
{
	for (Card* card : cards)
	{
		if (PlayerMouseController::mouse_in(position, card->card_bounds()))
			return card;
	}
	return nullptr;
}

void Hand::reverse()
{
	sf::Vector2f pos = Hand::zone_rectangle.getPosition();
	Hand::zone_rectangle.setPosition(pos.x, Settings::HEIGHT - pos.y);
}

Card* Hand::play_card(Card* card)
{
	return card;
}

void Hand::register_invokers()
{
}

void Hand::set_card_positions()
{
	while (Hand::cards.size() > (max_cards*rows*rows))
	{
		rows += 1;
	}
	float hand_pos_y = Hand::zone_rectangle.getPosition().y;
	float hand_pos_x = Hand::zone_rectangle.getPosition().x;

	float card_height = Settings::CARD_HEIGHT / rows;
	float card_width = card_height / Settings::CARD_HEIGHT_TO_WIDTH_RATIO;
	for (Card* card : cards) card->set_size(sf::Vector2f(card_width, card_height));

	float card_spacing_y = (Settings::WIDGET_HEIGHT - card_height*rows) / (rows+1);
	float card_spacing_x = (Settings::HAND_WIDTH - Hand::max_cards*rows*card_width) / (Hand::max_cards*rows + 1);
	float base_y = hand_pos_y - Settings::WIDGET_HEIGHT/2 + card_spacing_y + card_height/2;
	float base_x = hand_pos_x - Settings::HAND_WIDTH/2 + card_spacing_x + card_width/2;

	float y_inc = card_height + card_spacing_y;
	float x_inc = card_width + card_spacing_x;

	for (unsigned i=0;i<Hand::cards.size();)
	{
		for (unsigned j=0 ; j < rows && i < Hand::cards.size() ; j++, i++)
		{
			float x = base_x + (i-j)*x_inc/rows;
			float y = base_y + j*y_inc;
			Hand::cards.at(i)->set_position(sf::Vector2f(x, y));
		}
	}
}
