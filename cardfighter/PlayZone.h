#pragma once
#include "Zone.h"
#include "DrawInvoker.h"
#include "AZone.h"
#include "DZone.h"
#include "IZone.h"


class PlayZone : public DrawInvoker
{
public:
	PlayZone();
	~PlayZone();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void destroy(Card& card);
	void bounce(Card& card);

	std::forward_list<Card*> get_cards_matching_restriction(Restriction r);

	void reverse() override;

protected:
	void register_invokers() override;

private:
	AZone azone;
	DZone dzone;
	IZone izone;
};