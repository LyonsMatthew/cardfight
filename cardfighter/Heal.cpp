#include "Heal.h"
#include "Player.h"

Heal::Heal(int heal, Player& target)
	: heal(heal), target(target)
{
}

Heal::~Heal()
{
}

void Heal::trigger()
{
	target.heal_damage(Heal::heal);
}
