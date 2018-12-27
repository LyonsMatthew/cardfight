#include "ICard.h"

ICard::ICard(int card_id, Player& player, Player& enemy)
	: Card(card_id, player, enemy)
{
	ICard::set_card_color();
}

ICard::~ICard()
{
}

void ICard::play()
{
}

void ICard::set_card_color()
{
	ICard::card_rectangle.setFillColor(sf::Color(255, 255, 0, 255));
}

bool ICard::use()
{
	uses -= 1;
	return (uses <= 0);
}
