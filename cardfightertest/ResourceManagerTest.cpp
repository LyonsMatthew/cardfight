#include "catch.hpp"
#define private public
#include "../CardFighter/ResourceManager.h"
#include "../CardFighter/ResourceManager.cpp"
#include "../CardFighterTest/TestResourceUser.h"

TEST_CASE("ResourceUser registers texture resource", "[ResourceManager]")
{
	TestResourceUser user;
	user.register_texture("background", "assets/background.png");
	REQUIRE(ResourceManager::textures.at("background").getSize().x == 1920);
	ResourceManager::reset();
}

TEST_CASE("ResourceUser registers many texture resources", "[ResourceManager]")
{
	TestResourceUser user;
	user.register_texture("background", "assets/background.png");
	user.register_texture("background2", "assets/background.png");
	user.register_texture("background3", "assets/background.png");
	REQUIRE(ResourceManager::textures.size() == 3);
	ResourceManager::reset();
}

TEST_CASE("ResourceUser unregisters texture resource", "[ResourceManager]")
{
	TestResourceUser user;
	user.register_texture("background", "assets/background.png");
	user.unregister_texture("background");
	REQUIRE(ResourceManager::textures.size() == 0);
	ResourceManager::reset();
}

TEST_CASE("ResourceUser registers font resource", "[ResourceManager]")
{
	TestResourceUser user;
	user.register_font("lobster", "assets/Lobster_1.3.ttf");
	REQUIRE(ResourceManager::fonts.size() == 1);
	ResourceManager::reset();
}

TEST_CASE("Resources don't outlast ResourceUser's scope", "[ResourceUser]")
{
	do
	{
		TestResourceUser user;
		user.register_texture("background", "assets/background.png");
		user.register_texture("background2", "assets/background.png");
	} while (false);
	REQUIRE(ResourceManager::textures.size() == 0);
}