#include "Zone.h"

Zone::Zone()
{
	set_initial_zone_properties();
}

Zone::~Zone()
{
	for (Card* card : cards)
	{
		delete card;
	}
}

void Zone::move_card_to(Card& card, Zone& zone)
{
	card.set_size(sf::Vector2f(Settings::CARD_WIDTH, Settings::CARD_HEIGHT));
	unregister_invoker(card);
	cards.erase(std::remove(cards.begin(), cards.end(), &card), cards.end());
	update();
	zone.register_invoker(card);
	zone.cards.push_back(&card);
	zone.update();
}

void Zone::set_initial_zone_properties()
{
	Zone::zone_rectangle.setOutlineThickness(-1 * Settings::WIDGET_OUTLINE_THICKNESS);
	Zone::zone_rectangle.setOutlineColor(sf::Color());
	Zone::zone_rectangle.setFillColor(sf::Color(255,255,255,255));
}

sf::FloatRect Zone::zone_bounds()
{
	return Zone::zone_rectangle.getGlobalBounds();
}

void Zone::unhover_cards()
{
	for (Card* card : cards) card->unhover();
}

std::forward_list<Card*> Zone::get_cards_matching_restriction(Restriction r)
{
	std::forward_list<Card*> valid_cards;
	for (Card* c : cards)
	{
		if (r.is_satisfied(*c))
		{
			valid_cards.insert_after(valid_cards.end(), c);
		}
	}
	return valid_cards;
}

int Zone::card_count()
{
	return cards.size();
}
