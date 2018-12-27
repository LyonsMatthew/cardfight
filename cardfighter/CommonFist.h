#pragma once
#include "Restriction.h"
#include "WeaponCategoryRestriction.h"
#include "ACard.h"
#include "DCard.h"
#include "ICard.h"
#include "Damage.h"
#include "Heal.h"
#include "Untap.h"
#include "Block.h"
#include "DrawCard.h"

class TestAttack : public ACard
{
public:
	TestAttack(int id, Player& player, Player& enemy);
	std::queue<std::shared_ptr<Effect>> activate() override;
	std::queue<std::shared_ptr<Effect>> on_activate() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_play() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_hit() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_block() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_draw() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_bounce() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_revive() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_shuffle() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_destroy() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_discard() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_transform() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_turn_end() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_other() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	void set_card_properties() override; //loads the card sprite and text and applies it
private:
	int cooldown = 2;
};

class TestDefend : public DCard
{
public:
	TestDefend(int id, Player& player, Player& enemy);
	std::queue<std::shared_ptr<Effect>> activate() override;
	std::queue<std::shared_ptr<Effect>> on_activate() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_play() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_hit() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_block() override;
	std::queue<std::shared_ptr<Effect>> on_draw() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_bounce() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_revive() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_shuffle() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_destroy() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_discard() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_transform() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_turn_end() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_other() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	void set_card_properties() override; //loads the card sprite and text and applies it
private:
	int cooldown = 2;
};

class TestItem : public ICard
{
public:
	TestItem(int id, Player& player, Player& enemy);
	std::queue<std::shared_ptr<Effect>> activate() override;
	std::queue<std::shared_ptr<Effect>> on_activate() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_play() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_hit() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_block() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_draw() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_bounce() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_revive() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_shuffle() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_destroy() override;
	std::queue<std::shared_ptr<Effect>> on_discard() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_transform() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_turn_end() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	std::queue<std::shared_ptr<Effect>> on_other() override { std::queue<std::shared_ptr<Effect>> queue; return queue; }
	void set_card_properties() override; //loads the card sprite and text and applies it
private:
	int cooldown = 2;
};