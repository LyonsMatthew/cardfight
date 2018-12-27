#include "CommonFist.h"

TestAttack::TestAttack(int id, Player& player, Player& enemy)
	: ACard(id, player, enemy)
{
	set_card_properties();
}

std::queue<std::shared_ptr<Effect>> TestAttack::activate()
{
	std::vector<std::shared_ptr<RestrictionStrategy>> restrictions;
	restrictions.push_back(std::make_shared<WeaponCategoryRestriction>("Fist"));
	Restriction r = Restriction(restrictions);

	std::queue<std::shared_ptr<Effect>> effects;
	effects.push(std::make_shared<Damage>(5, TestAttack::enemy)); //deal 5 damage to enemy
	effects.push(std::make_shared<Heal>(4, TestAttack::player)); //heal self for 4 health
	effects.push(std::make_shared<Untap>(r)); //untap a "Fist"-category card
	return effects;
}

void TestAttack::set_card_properties()
{
}

TestDefend::TestDefend(int id, Player& player, Player& enemy)
	: DCard(id, player, enemy)
{
	set_card_properties();
}

std::queue<std::shared_ptr<Effect>> TestDefend::activate()
{
	std::queue<std::shared_ptr<Effect>> effects;
	effects.push(std::make_shared<Block>(7, TestDefend::player)); //block 7 damage
	return effects;
}

std::queue<std::shared_ptr<Effect>> TestDefend::on_block()
{
	std::queue<std::shared_ptr<Effect>> effects;
	effects.push(std::make_shared<Heal>(3, TestDefend::player)); //heal 3 damage
	return effects;
}

void TestDefend::set_card_properties()
{
}

TestItem::TestItem(int id,Player & player,Player & enemy)
	: ICard(id, player, enemy)
{
	TestItem::uses = 3;
}

std::queue<std::shared_ptr<Effect>> TestItem::activate()
{
	std::queue<std::shared_ptr<Effect>> effects;
	effects.push(std::make_shared<Heal>(1, TestItem::player)); //heal 1 damage
	ICard::use(); //destroy code not written yet :D
	return effects;
}

std::queue<std::shared_ptr<Effect>> TestItem::on_destroy()
{
	std::queue<std::shared_ptr<Effect>> effects;
	effects.push(std::make_shared<DrawCard>(1, TestItem::player)); //heal 3 damage
	return effects;
}

void TestItem::set_card_properties()
{
}
