#include "Player.h"

Player::Player(Player& enemy)
	: enemy(enemy), pa(*this, enemy), pc(pa, *this)
{
	Player::register_invokers();
	for(int i=0;i<100;i++)
	{
		Player::deck.create_card_at_bottom(new TestAttack(3*i, *this, enemy));
		Player::deck.create_card_at_bottom(new TestDefend(3*i+1, *this, enemy));
		Player::deck.create_card_at_bottom(new TestItem(3*i+2, *this, enemy));
	}
}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Player::reverse()
{
}

void Player::take_damage(int damage)
{
}

void Player::heal_damage(int damage)
{
}

void Player::block_damage(int block)
{
	//gain block
}

void Player::draw_card()
{
	pa.draw_card();
}

void Player::register_invokers()
{
	Player::register_invoker(hand);
	Player::register_invoker(discard);
	Player::register_invoker(deck);
	Player::register_invoker(playzone);
}

std::forward_list<Card*> Player::get_cards_meeting_restriction(Restriction r)
{
	std::forward_list<Card*> valid_cards;
	std::forward_list<Card*> hand_cards = hand.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), hand_cards.begin(), hand_cards.end());
	std::forward_list<Card*> deck_cards = deck.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), deck_cards.begin(), deck_cards.end());
	std::forward_list<Card*> discard_cards = discard.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), discard_cards.begin(), discard_cards.end());
	std::forward_list<Card*> playzone_cards = playzone.get_cards_matching_restriction(r);
	valid_cards.insert_after(valid_cards.end(), playzone_cards.begin(), playzone_cards.end());
	return valid_cards;
}