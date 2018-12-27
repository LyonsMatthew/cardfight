#pragma once
#include <string>
#include "RestrictionStrategy.h"


class NoRestriction : public RestrictionStrategy
{
public:
	bool is_satisfied(Card& card) override;
};