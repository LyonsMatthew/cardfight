#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Zone.h"
#include "DrawInvoker.h"


class Discard : public Zone
{
public:
	Discard();
	~Discard();

	void update();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Card* hover_card(sf::Vector2i position) override;

	void reverse() override;

	void set_zone_properties() override;

protected:
	void register_invokers() override;

private:

};