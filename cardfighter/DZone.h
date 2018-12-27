#pragma once
#include "DIAZone.h"


class DZone : public DIAZone
{
public:
	DZone();
	~DZone();

	void update();

	void set_zone_properties() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Card* hover_card(sf::Vector2i position) override;

	void reverse() override;

protected:
	void register_invokers() override;

private:

};