#include "RestrictionStrategy.h"
#include "NoRestriction.h"

RestrictionStrategy::RestrictionStrategy()
{
	and_strategy = std::make_shared<NoRestriction>();
}

RestrictionStrategy::RestrictionStrategy(std::shared_ptr<RestrictionStrategy> and_strategy)
	: and_strategy(and_strategy)
{
}
