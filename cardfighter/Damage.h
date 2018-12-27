#pragma once
#include "Effect.h"

class Player;

class Damage : public Effect
{
public:
	Damage(int damage, Player& target);
	~Damage();

	void trigger() override;

private:
	Player& target;
	int damage;

};