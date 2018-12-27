#pragma once
#include <SFML/Graphics.hpp>


class Settings
{
public:
	//screen dimensions
	static int WIDTH;
	static int HEIGHT;

	//battlefield proportions
	static float PADDING;
	static float MIN_CARD_SPACING;
	static float CARD_HEIGHT;
	static float CARD_HEIGHT_TO_WIDTH_RATIO;
	static float CARD_WIDTH;
	static float WIDGET_OUTLINE_THICKNESS;
	static float CARD_OUTLINE_THICKNESS;
	static float WIDGET_HEIGHT;
	static float DISCARD_WIDTH;
	static float DECK_WIDTH;
	static float HAND_WIDTH;
	static float PLAY_WIDTH;

	//battlefield positions
	static sf::Vector2f DISCARD_POSITION;
	static sf::Vector2f HAND_POSITION;
	static sf::Vector2f DECK_POSITION;
	static sf::Vector2f PLAY_POSITION;

private:

};