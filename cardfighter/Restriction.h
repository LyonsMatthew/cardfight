#pragma once
#include <vector>
#include "RestrictionStrategy.h"

class Restriction
{
public:
	Restriction(std::vector<std::shared_ptr<RestrictionStrategy>> restrictions);

	bool is_satisfied(Card& card);

private:
	std::vector<std::shared_ptr<RestrictionStrategy>> restrictions;
};