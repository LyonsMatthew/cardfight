#include "ModifyCooldown.h"
#include "Player.h"

ModifyCooldown::ModifyCooldown(int cooldown, Restriction& r)
	: cooldown(cooldown), r(r)
{
}

ModifyCooldown::~ModifyCooldown()
{
}

void ModifyCooldown::trigger()
{
}
