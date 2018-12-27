#include "Damage.h"
#include "Player.h"

Damage::Damage(int damage, Player& target)
	: damage(damage), target(target)
{
}

Damage::~Damage()
{
}

void Damage::trigger()
{
	target.take_damage(Damage::damage);
}
