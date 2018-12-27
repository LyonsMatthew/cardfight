#pragma once
#include "Settings.h"
#include "DrawInvoker.h"
#include "Zone.h"


class Hand : public Zone
{
public:
	Hand();
	~Hand();

	void update();

	void set_zone_properties() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Card* hover_card(sf::Vector2i position) override;

	void reverse() override;

	Card* play_card(Card* card);

protected:
	void register_invokers() override;

private:
	unsigned max_cards = static_cast<unsigned>((Settings::HAND_WIDTH - Settings::MIN_CARD_SPACING) / (Settings::CARD_WIDTH + Settings::MIN_CARD_SPACING));
	unsigned rows = 1;
	void set_card_positions();
};