#pragma once
#include <stack>
#include "Effect.h"
#include "Restriction.h"

class Player;

class PlayerAction
{
public:
	PlayerAction(Player& player, Player& enemy);

	void parse_effects(std::stack<Effect> effects);

	void play(Restriction r);

	void draw_card();
	void play_card(Card* card);

private:
	Player& player;
	Player& enemy;


};