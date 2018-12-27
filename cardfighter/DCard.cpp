#include "DCard.h"

DCard::DCard(int card_id, Player& player, Player& enemy)
	: Card(card_id, player, enemy)
{
	DCard::set_card_color();
}

DCard::~DCard()
{
}

void DCard::play()
{
}

void DCard::set_card_color()
{
	DCard::card_rectangle.setFillColor(sf::Color(0, 0, 255, 255));
}
