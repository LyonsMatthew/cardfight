#pragma once
#include <string>
#include <vector>
#include "Effect.h"
#include "Restriction.h"

class Player;

class ModifyCooldown : public Effect
{
public:
	ModifyCooldown(int cooldown, Restriction& r);
	~ModifyCooldown();

	void trigger() override;

private:
	Restriction& r;
	int cooldown;
	std::vector<std::string> valid_targets;

};