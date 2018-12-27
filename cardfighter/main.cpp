#include<string>
#include "Window.h"
#include "Battle.h"
#include "InputMaster.h"

void initialize_window(Window& window)
{
	window.set_title("Cardfight");
	window.create();
}

void game_loop()
{
	Window window;
	Battle battle;
	initialize_window(window);
	sf::Event event;
	while(window.is_open())
	{
		while(window.poll_event(event))
		{
			InputMaster::input(event);
		}
		/*Trinity::game()->handle_input();
		Trinity::game()->update();
		Trinity::game()->render();
		Trinity::game()->restartClock();*/
		window.update();
		window.clear();
		window.invoke_draw(battle);
		window.display();
	}
}

int main()
{
	game_loop();
	return 0;
}