#pragma once
#include "Effect.h"

class Player;

class DrawCard : public Effect
{
public:
	DrawCard(int number, Player& target);
	~DrawCard();

	void trigger() override;

private:
	Player& target;
	int number;

};