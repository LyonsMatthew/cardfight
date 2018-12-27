#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main()
{
	Catch::Session().run();
	
	std::string s;
	std::cin >> s;

	return 0;
}