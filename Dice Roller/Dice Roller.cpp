#include <iostream>
#include "dice.h"

int main()
{
	rDice rd20(20, false);
	rDice rd20c(20, true);
	cDice cd20(20);

	std::cout << "True Random Rolls without Guarenteed Crits:" << std::endl;
	for (int i = 0; i < 20; ++i) {
		std::cout << rd20.result() << " ";
	}
	std::cout << std::endl;

	std::cout << "True Random Rolls with Guarenteed Crits:" << std::endl;
	for (int i = 0; i < 20; ++i) {
		std::cout << rd20c.result() << " ";
	}
	std::cout << std::endl;

	std::cout <<  "Competitive Rolls:" << std::endl;
	for (int i = 0; i < 20; ++i) {
		std::cout << cd20.result() << " ";
	}
	
}