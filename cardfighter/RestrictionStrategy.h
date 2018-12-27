#pragma once
#include "Card.h"

class NoRestriction;

class RestrictionStrategy
{
public:
	RestrictionStrategy();
	RestrictionStrategy(std::shared_ptr<RestrictionStrategy> and_strategy);

	virtual bool is_satisfied(Card& card) = 0;

protected:
	std::shared_ptr<RestrictionStrategy> and_strategy;

};