#include "DrawCard.h"
#include "Player.h"

DrawCard::DrawCard(int number, Player& target)
	: number(number), target(target)
{
}

DrawCard::~DrawCard()
{
}

void DrawCard::trigger()
{
	for(int i=0;i<number;i++)
		target.draw_card(); //target draws cards equal to number
}
