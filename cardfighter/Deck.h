#pragma once
#include "DrawInvoker.h"
#include "Zone.h"


class Deck : public Zone
{
public:
	Deck();
	~Deck();

	void update();

	void set_zone_properties() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Card* hover_card(sf::Vector2i position) override;

	void reverse() override;

	Card* draw_card();
	void search_card(Card& card);
	void scry(int number_to_scry);
	void shuffle();

	void create_card_at_bottom(Card* card);

protected:
	void register_invokers() override;

private:

};