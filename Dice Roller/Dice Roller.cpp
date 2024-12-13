#include <iostream>
#include "dice.h"

void tRandom() {
	std::cout << "Enable Guarenteed Crits? [Y/N]" << std::endl;
	std::cout << std::endl << "Input: ";
	char input = 'a';
	std::cin >> input;
	std::cout << std::endl;
	bool gCrit;
	switch (input) {
	case 'y': gCrit = true; break;
	case 'Y': gCrit = true; break;
	case 'n': gCrit = false; break;
	case 'N': gCrit = false; break;
	}
	rDice d4(4);
	rDice d6(6);
	rDice d8(8);
	rDice d10(10);
	rDice d12(12);
	rDice d20(20, gCrit);
	rDice d100(100);

	bool quit = false;
	int numInput = 1;
	std::cout << "Select the dice number of the dice you'd like to roll (6, 20, 100, etc). Input 0 to exit." << std::endl << std::endl;
	while (!quit) {
		std::cout << "Input: ";
		std::cin >> numInput;
		std::cout << std::endl;
		switch (numInput) {
		case 0: quit = true; break;
		case 4: std::cout << "Roll: " << d4.result() << std::endl; break;
		case 6: std::cout << "Roll: " << d6.result() << std::endl; break;
		case 8: std::cout << "Roll: " << d8.result() << std::endl; break;
		case 10: std::cout << "Roll: " << d10.result() << std::endl; break;
		case 12: std::cout << "Roll: " << d12.result() << std::endl; break;
		case 20: std::cout << "Roll: " << d20.result() << std::endl; break;
		case 100: std::cout << "Roll: " << d100.result() << std::endl; break;
		}
	}
}

 void competitive() {
	 cDice d4(4);
	 cDice d6(6);
	 cDice d8(8);
	 cDice d10(10);
	 cDice d12(12);
	 cDice d20(20);
	 cDice d100(100);

	 bool quit = false;
	 int numInput = 1;
	 std::cout << "Select the dice number of the dice you'd like to roll (6, 20, 100, etc). Input 0 to exit." << std::endl << std::endl;
	 while (!quit) {
		 std::cout << "Input: ";
		 std::cin >> numInput;
		 std::cout << std::endl;
		 switch (numInput) {
		 case 0: quit = true; break;
		 case 4: std::cout << "Roll: " << d4.result() << std::endl; break;
		 case 6: std::cout << "Roll: " << d6.result() << std::endl; break;
		 case 8: std::cout << "Roll: " << d8.result() << std::endl; break;
		 case 10: std::cout << "Roll: " << d10.result() << std::endl; break;
		 case 12: std::cout << "Roll: " << d12.result() << std::endl; break;
		 case 20: std::cout << "Roll: " << d20.result() << std::endl; break;
		 case 100: std::cout << "Roll: " << d100.result() << std::endl; break;
		 }
	 }
}

 void demo() {
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

	std::cout << "Competitive Rolls:" << std::endl;
	for (int i = 0; i < 20; ++i) {
		std::cout << cd20.result() << " ";
	}
}

 int main() {
	 std::cout << "Select a dice type." << std::endl;
	 std::cout << "Available types:" << std::endl << std::endl;
	 std::cout << "R: True Random - Every roll is fully randomized." << std::endl;
	 std::cout << "C: Competitive - Every possible value must appear once before repeat values may appear." << std::endl;
	 std::cout << "D: run a demo of each dice type." << std::endl;
	 std::cout << "Q: quit program." << std::endl;

	 char input = 'a';
	 bool quit = false;
	 while (!quit) {
		std::cout << std::endl << "Input: ";
		std::cin >> input;
		std::cout << std::endl;
		switch (input) {
		case 'd': demo(); break;
		case 'D': demo(); break;
		case 'r': tRandom(); quit = true; break;
		case 'R': tRandom(); quit = true; break;
		case 'c': competitive(); quit = true; break;
		case 'C': competitive(); quit = true; break;
		case 'q': quit = true;  break;
		case 'Q': quit = true; break;
		}
 }
 }