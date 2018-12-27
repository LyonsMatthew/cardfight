#include "WeaponCategoryRestriction.h"

WeaponCategoryRestriction::WeaponCategoryRestriction(std::string category)
	: weapon_category(category)
{
}

WeaponCategoryRestriction::WeaponCategoryRestriction(std::string category, std::shared_ptr<RestrictionStrategy> and_strategy)
	: weapon_category(category), RestrictionStrategy(and_strategy)
{
}

bool WeaponCategoryRestriction::is_satisfied(Card& card)
{
	return (card.weapon_category == WeaponCategoryRestriction::weapon_category && and_strategy->is_satisfied(card));
}