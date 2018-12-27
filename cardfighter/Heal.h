#pragma once
#include "Effect.h"

class Player;

class Heal : public Effect
{
public:
	Heal(int heal, Player& target);
	~Heal();

	void trigger() override;

private:
	Player& target;
	int heal;

};