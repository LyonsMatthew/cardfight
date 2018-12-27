#pragma once
#include "Card.h"

class ICard : public Card
{
public:
	ICard(int id, Player& player, Player& enemy);
	~ICard();

	void play() override;

	void set_card_color();

	bool use(); //returns true if item is out of uses
	int uses;

private:

};