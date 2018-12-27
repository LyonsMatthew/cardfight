#include "catch.hpp"
#define private public
#include "InputManager.h"
#include "TestInputObserver.h"

TEST_CASE("InputManager registers observers", "[InputManager]")
{
	InputManager manager;
	InputObserver* test1 = new TestInputObserver(4);
	InputObserver* test2 = new TestInputObserver(7);
	manager.register_observer(*test1);
	manager.register_observer(*test2);
	REQUIRE(manager.input_observers.size() == 2);

}

TEST_CASE("InputManager unregisters observers", "[InputManager]")
{
	InputManager manager;
	InputObserver* test1 = new TestInputObserver(4);
	InputObserver* test2 = new TestInputObserver(7);
	manager.register_observer(*test1);
	manager.register_observer(*test2);
	manager.unregister_observer(*test1);
	REQUIRE(manager.input_observers.size() == 1);
}

TEST_CASE("InputObserver operator==", "[InputObserver]")
{
	InputManager manager;
	InputObserver* test1 = new TestInputObserver(4);
	manager.register_observer(*test1);
	REQUIRE(manager.input_observers.at(0) == test1);
}