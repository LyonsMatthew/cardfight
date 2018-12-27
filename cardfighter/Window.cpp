#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Settings.h"

Window::Window()
{
	Window::initialize_default_values();
	sf::ContextSettings settings = window.getSettings();
}

Window::Window(const sf::Vector2u& size, const std::string& title)
{
	Window::initialize_default_values();
	Window::set_size(size);
	Window::set_title(title);
	Window::create();
}

Window::~Window()
{
	Window::destroy();
}

void Window::create()
{
	if (is_fullscreen)
	{
		Window::window.create(sf::VideoMode::getFullscreenModes().at(0), Window::title, 
			sf::Style::Fullscreen);
	}
	else
	{
		Window::window.create(sf::VideoMode(Window::size.x, Window::size.y), Window::title,
			(sf::Style::Titlebar | sf::Style::Close));
	}
}

void Window::destroy()
{
	Window::close();
}

void Window::initialize_default_values()
{
	Window::set_size(sf::Vector2u(Settings::WIDTH, Settings::HEIGHT));
	Window::set_title("Default Title");
	Window::set_framerate(60);
	Window::is_fullscreen = false;
}

void Window::close()
{
	Window::window.close();
}

void Window::update()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window::close();
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			toggle_fullscreen();
		}
	}
}

void Window::input()
{
	//all window input is handled through events rather than real-time query; see Window::update()
}

void Window::toggle_fullscreen()
{
	is_fullscreen = !is_fullscreen;
	destroy();
	create();
}

void Window::invoke_draw(DrawInvoker& invoker)
{
	for (DrawInvoker* invoker : DrawInvoker::draw_queue)
	{
		window.draw(*invoker);
	}
}

bool Window::poll_event(sf::Event& event)
{
	return window.pollEvent(event);
}

void Window::set_size(const sf::Vector2u& size)
{
	Window::size = size;
}

void Window::set_title(const std::string& title)
{
	Window::title = title;
}

void Window::set_framerate(int framerate)
{
	Window::framerate = framerate;
	window.setFramerateLimit(framerate);
}

bool Window::is_open()
{
	return window.isOpen();
}

void Window::clear()
{
	window.clear();
}

void Window::draw(sf::Drawable& drawable)
{
	window.draw(drawable);
}

void Window::display()
{
	window.display();
}
