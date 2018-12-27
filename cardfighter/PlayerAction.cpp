#include "PlayerAction.h"
#include "Player.h"

PlayerAction::PlayerAction(Player& player, Player& enemy)
	: player(player), enemy(enemy)
{
}

void PlayerAction::parse_effects(std::stack<Effect>)
{
}

void PlayerAction::play(Restriction r)
{
}

void PlayerAction::draw_card()
{
	Card* card = player.deck.draw_card();
	player.deck.move_card_to(*card, player.hand);
}

void PlayerAction::play_card(Card* card)
{
	Card* card = player.hand.play_card(card);
}
