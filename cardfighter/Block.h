#pragma once
#include "Effect.h"

class Player;

class Block : public Effect
{
public:
	Block(int block, Player& target);
	~Block();

	void trigger() override;

private:
	Player& target;
	int block;

};