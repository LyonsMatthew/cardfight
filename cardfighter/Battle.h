#pragma once
#include "Player.h"
#include "ResourceUser.h"
#include "DrawInvoker.h"

enum class BattleState
{
	DRAW,
	PLAY,
	ACTION,
	END
};

class Battle : public ResourceUser, public DrawInvoker
{
public:
	Battle();
	~Battle();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void reverse() override;

protected:
	void register_invokers() override;
	void register_resources() override;
	void use_resources() override;

private:
	void execute_draw_phase();
	void execute_play_phase();
	void execute_action_phase();
	void execute_end_phase();

	sf::Sprite background;

	Player p1;
	Player p2;
	bool p1_init;
	//music
};