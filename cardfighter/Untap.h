#pragma once
#include <string>
#include <vector>
#include "Effect.h"
#include "Restriction.h"

class Player;

class Untap : public Effect
{
public:
	Untap(Restriction& r);
	~Untap();

	void trigger() override;

private:
	Restriction& r;

};