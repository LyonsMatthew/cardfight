#include "Restriction.h"

Restriction::Restriction(std::vector<std::shared_ptr<RestrictionStrategy>> restrictions)
	: restrictions(restrictions)
{
}

bool Restriction::is_satisfied(Card & card)
{
	for (std::shared_ptr<RestrictionStrategy> r : restrictions)
	{
		if ((*r).is_satisfied(card)) return true;
	}
	return false;
}
