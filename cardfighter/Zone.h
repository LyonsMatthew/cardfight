#pragma once
#include <vector>
#include <forward_list>
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Card.h"
#include "Restriction.h"
#include "DrawInvoker.h"
#include "InputObserver.h"


class Zone : public DrawInvoker
{
public:
	Zone();
	~Zone();

	void move_card_to(Card& card, Zone& zone);

	virtual void update() = 0;

	virtual void set_zone_properties() = 0;
	void set_initial_zone_properties();
	sf::FloatRect zone_bounds();

	virtual Card* hover_card(sf::Vector2i position) = 0;
	void unhover_cards();

	std::forward_list<Card*> get_cards_matching_restriction(Restriction r);

	int card_count();

protected:
	std::vector<Card*> cards;
	sf::RectangleShape zone_rectangle;

private:
	
};