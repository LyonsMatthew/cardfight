#pragma once
#include "Card.h"

class ACard : public Card
{
public:
	ACard(int id, Player& player, Player& enemy);
	~ACard();

	void play() override;

	void set_card_color();

private:

};

class AttackPower
{
public:

private:

};