#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <memory>
#include <SFML/Graphics.hpp>
#include "DrawInvoker.h"

class Window
{
public:
	Window();
	Window(const sf::Vector2u& size, const std::string& title);
	~Window();

	void create();

	void input();
	void update();
	void invoke_draw(DrawInvoker& invoker);

	bool poll_event(sf::Event& event);

	void clear();
	void draw(sf::Drawable& drawable);
	void display();

	void set_size(const sf::Vector2u& size);
	void set_title(const std::string& title);
	void set_framerate(int framerate);

	bool is_open();

	void toggle_fullscreen();

private:
	void destroy();
	void initialize_default_values();

	void build_draw_queue(DrawInvoker& invoker, std::queue<DrawInvoker*>& queue);

	void close();
	
	sf::RenderWindow window;

	sf::Vector2u size;
	std::string title;
	int framerate;
	bool is_fullscreen;
};