#include "Settings.h"

//screen dimensions
int Settings::WIDTH = 1600;
int Settings::HEIGHT = 900;

//battlefield proportions
float Settings::PADDING = Settings::HEIGHT*0.05f;
float Settings::MIN_CARD_SPACING = Settings::HEIGHT*0.02f;
float Settings::WIDGET_OUTLINE_THICKNESS = 5.f;
float Settings::CARD_OUTLINE_THICKNESS = 3.f;
float Settings::WIDGET_HEIGHT = (Settings::HEIGHT - Settings::PADDING*2) / 4;
float Settings::CARD_HEIGHT = Settings::WIDGET_HEIGHT - Settings::MIN_CARD_SPACING*2;
float Settings::CARD_HEIGHT_TO_WIDTH_RATIO = 1.4f;
float Settings::CARD_WIDTH = Settings::CARD_HEIGHT / Settings::CARD_HEIGHT_TO_WIDTH_RATIO;

float Settings::DISCARD_WIDTH = Settings::WIDGET_HEIGHT / Settings::CARD_HEIGHT_TO_WIDTH_RATIO;
float Settings::DECK_WIDTH = Settings::DISCARD_WIDTH;
float Settings::HAND_WIDTH = Settings::WIDTH - (Settings::DISCARD_WIDTH) - (Settings::DECK_WIDTH) - (Settings::PADDING*2);
float Settings::PLAY_WIDTH = Settings::WIDTH - Settings::PADDING*2;

//battlefield positions
sf::Vector2f Settings::HAND_POSITION = sf::Vector2f(Settings::WIDTH/2.f, 
	Settings::HEIGHT - Settings::PADDING - WIDGET_HEIGHT/2 - 3*Settings::WIDGET_OUTLINE_THICKNESS/2);
sf::Vector2f Settings::DISCARD_POSITION = sf::Vector2f(Settings::HAND_POSITION.x - Settings::HAND_WIDTH/2 - 
	Settings::DISCARD_WIDTH/2 + Settings::WIDGET_OUTLINE_THICKNESS,
	Settings::HAND_POSITION.y);
sf::Vector2f Settings::DECK_POSITION = sf::Vector2f(Settings::WIDTH - Settings::DISCARD_POSITION.x, 
	Settings::HAND_POSITION.y);
sf::Vector2f Settings::PLAY_POSITION = sf::Vector2f(Settings::WIDTH/2.f,
	Settings::HAND_POSITION.y - Settings::WIDGET_HEIGHT + Settings::WIDGET_OUTLINE_THICKNESS);