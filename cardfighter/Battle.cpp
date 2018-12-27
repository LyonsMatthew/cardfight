#include "Battle.h"

Battle::Battle()
	: p1(p2), p2(p1)
{
	Battle::register_resources();
	Battle::use_resources();
	Battle::register_invokers();
	DrawInvoker::initialize_draw_queue(*this);
	DrawInvoker::reverse_invokers(p2);
}

Battle::~Battle()
{

}

void Battle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
}

void Battle::register_resources()
{
	Battle::register_texture("background", "assets/background.png");
}

void Battle::use_resources()
{
	background.setTexture(ResourceManager::use_texture("background"));
}

void Battle::execute_draw_phase()
{
}

void Battle::execute_play_phase()
{
}

void Battle::execute_action_phase()
{
}

void Battle::execute_end_phase()
{
}

void Battle::reverse()
{
}



void Battle::register_invokers()
{
	Battle::register_invoker(p1);
	Battle::register_invoker(p2);
}
