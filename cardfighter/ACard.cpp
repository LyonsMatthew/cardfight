#include "ACard.h"

ACard::ACard(int card_id, Player& player, Player& enemy)
	: Card(card_id, player, enemy)
{
	ACard::set_card_color();
}

ACard::~ACard()
{
}

void ACard::play()
{
}

void ACard::set_card_color()
{
	ACard::card_rectangle.setFillColor(sf::Color(255, 0, 0, 255));
}
