#pragma once
#include "PlayerAvatar.h"
#include "PlayerStats.h"
#include "PlayerAction.h"
#include "PlayerController.h"
#include "PlayerMouseController.h"
#include "Deck.h"
#include "Hand.h"
#include "Discard.h"
#include "PlayZone.h"
#include "AZone.h"
#include "DZone.h"
#include "IZone.h"
#include "DrawInvoker.h"
#include "Restriction.h"
#include "CommonFist.h"


class Player : public DrawInvoker
{
public:
	Player(Player& enemy);
	~Player();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void reverse() override;

	std::forward_list<Card*> get_cards_meeting_restriction(Restriction r);

	void take_damage(int damage);
	void heal_damage(int damage);
	void block_damage(int block);
	void draw_card();

	//zones on the game field
	Deck deck;
	Hand hand;
	Discard discard;
	PlayZone playzone;

protected:
	void register_invokers() override;

private:
	Player& enemy;
	PlayerAvatar pv;
	PlayerStats ps;
	PlayerAction pa;
	PlayerController pc;
};