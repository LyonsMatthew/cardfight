#pragma once
#include "Card.h"

class DCard : public Card
{
public:
	DCard(int id, Player& player, Player& enemy);
	~DCard();

	void play() override;

	void set_card_color();

private:

};