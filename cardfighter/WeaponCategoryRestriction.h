#pragma once
#include <string>
#include "RestrictionStrategy.h"


class WeaponCategoryRestriction : public RestrictionStrategy
{
public:
	WeaponCategoryRestriction(std::string);
	WeaponCategoryRestriction(std::string, std::shared_ptr<RestrictionStrategy> and_strategy);

	bool is_satisfied(Card& card) override;

private:
	std::string weapon_category;

};