#pragma once
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include "Effect.h"
#include "DrawInvoker.h"

class Player;

class Card : public DrawInvoker
{
public:
	Card(int id, Player& player, Player& enemy);
	~Card();

	virtual void play() = 0;
	virtual void set_card_properties() = 0;
	void set_initial_card_properties();
	void set_position(sf::Vector2f position);
	void set_size(sf::Vector2f size);

	void hover();
	void unhover();

	sf::FloatRect card_bounds();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//effects; most cards will only have one or two of these,
	//but polymorphism requires that every card implement every single one.
	//adding new ones sucks, so try not to!
	virtual std::queue<std::shared_ptr<Effect>> activate() = 0; //the card's normal effect
	virtual std::queue<std::shared_ptr<Effect>> on_activate() = 0; //activated immediately when the card is activated
	virtual std::queue<std::shared_ptr<Effect>> on_play() = 0; //activated when the card is moved from hand to field
	virtual std::queue<std::shared_ptr<Effect>> on_hit() = 0; //activated if the opponent's take_damage() returns a value greater than 0
	virtual std::queue<std::shared_ptr<Effect>> on_block() = 0; //activated if your take_damage() returns 0
	virtual std::queue<std::shared_ptr<Effect>> on_draw() = 0; //activated when the card is moved from deck to hand
	virtual std::queue<std::shared_ptr<Effect>> on_bounce() = 0; //activated when the card is moved from field or discard to hand
	virtual std::queue<std::shared_ptr<Effect>> on_revive() = 0; //activated when the card is moved from the discard to the field
	virtual std::queue<std::shared_ptr<Effect>> on_shuffle() = 0; //activated when the card is moved to the deck (from anywhere)
	virtual std::queue<std::shared_ptr<Effect>> on_destroy() = 0; //activated when the card is moved to the discard from the field
	virtual std::queue<std::shared_ptr<Effect>> on_discard() = 0; //activated when the card is moved from the hand or deck to the field
	virtual std::queue<std::shared_ptr<Effect>> on_transform() = 0; //activated when the card is moved from one playzone to another
	virtual std::queue<std::shared_ptr<Effect>> on_turn_end() = 0; //activated at the end of the turn if the card is on the field
	virtual std::queue<std::shared_ptr<Effect>> on_other() = 0; //never know when you'll need something like this

	//card data
	int id; //id, also the position in the sorted deck (i.e. in the deckbuilder)
	int cooldown; //cooldown when the card is activated
	int current_cooldown; //can be activated when this is 0; decreases by 1 each turn
	int tier; //the card tier; higher means stronger, but harder to play
	std::string name; //displayed at the top of the card
	std::string description; //the effect text in the card body
	std::string weapon_source; //the exact weapon this card belongs to, e.g. "Shark Knuckles"
	std::string weapon_category; //the weapon family this card belongs to, e.g. "Fist"

	Player& player;
	Player& enemy;

	void reverse() override;
	
protected:
	sf::RectangleShape card_rectangle;

	void register_invokers() override;

private:

};