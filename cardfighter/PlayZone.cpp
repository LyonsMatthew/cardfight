#include "PlayZone.h"

PlayZone::PlayZone()
{
	PlayZone::register_invokers();
}

PlayZone::~PlayZone()
{
}

void PlayZone::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
}

void PlayZone::destroy(Card & card)
{
}

void PlayZone::bounce(Card & card)
{
}

std::forward_list<Card*> PlayZone::get_cards_matching_restriction(Restriction r)
{
	std::forward_list<Card*> valid_cards;
	std::forward_list<Card*> azone_cards = azone.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), azone_cards.begin(), azone_cards.end());
	std::forward_list<Card*> dzone_cards = dzone.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), dzone_cards.begin(), dzone_cards.end());
	std::forward_list<Card*> izone_cards = izone.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), izone_cards.begin(), izone_cards.end());
	return valid_cards;
}

void PlayZone::reverse()
{
}

void PlayZone::register_invokers()
{
	register_invoker(izone);
	register_invoker(dzone);
	register_invoker(azone);
}
