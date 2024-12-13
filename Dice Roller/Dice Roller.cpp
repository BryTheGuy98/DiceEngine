#include <iostream>
#include "dice.h"

int main()
{
	cDice d20(20);

	std::cout <<  "Rolls: ";
	
	for (int i = 0; i < 20; ++i) {
		std::cout << d20.result();
		std::cout << " ";
	}
	
}