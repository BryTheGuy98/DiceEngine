#include "Random.h"
#include <stack>

class Dice {
public:
	const int sides;
	virtual int getRoll() = 0;
	int result() {
		return getRoll();
	}
	int resultAdv() {
		int x = getRoll();
		int y = getRoll();
		return (x > y) ? x : y;
	}
	int resultDis() {
		int x = getRoll();
		int y = getRoll();
		return (x > y) ? x : y;
	}
	int resultSum(int numRolls) {
		int sum = 0;
		while (numRolls-- > 0) {
			sum += getRoll();
		}
		return sum;
	}
protected:
	Random r;
	Dice(int s) : sides(s) {
		r = Random();
	}
};

class rDice : public Dice {			// True Random
public:
	rDice(int s, bool c) : Dice(s), gCrits(c) {
	}
	rDice(int s) : Dice(s), gCrits(false)  {
	}
private:
	const bool gCrits;
	int numRolls = 0;
	int getRoll() override {
		int roll;
		if (gCrits && numRolls == sides-1) {
			roll = sides;
		}
		else {
			roll = r.rand(1, sides);
		}
		if (gCrits) {
			if (roll == sides) {
				numRolls = 0;
			}
			else {
				numRolls++;
			}
		}
		return roll;
	}
};

class cDice : public Dice {			// Competitive
public:
	cDice(int s) : Dice(s) {
		populate();
	}
private:
	std::stack<int> rolls;
	void populate() {
		int* nums = new int[sides];
		for (int i = 0; i < sides; ++i) {
			nums[i] = i + 1;
		}
		shuffle(nums);
		for (int i = 0; i < sides; ++i) {
			rolls.push(nums[i]);
		}
		delete[] nums;
	}
	void shuffle(int nums[]) {
		for (int i = 0; i < sides; ++i) {
			std::swap(nums[i], nums[r.rand(0, sides-1)]);
		}
	}
	int getRoll() override {
		if (rolls.empty()) {
			populate();
		}
		int i = rolls.top();
		rolls.pop();
		return i;
	}
};

class kDice : public Dice {		// Karmatic
public:
	kDice(int s) : Dice(s), gCrits(false) {}
	kDice(int s, bool c) : Dice(s), gCrits(c) {}
private:
	const bool gCrits;
	int numRolls = 0;
	int bRolls = 0;
	int getRoll() override {
		int roll = 0;
		if (gCrits && numRolls == sides - 1) {
			roll = sides;
		}
		else {
			roll = r.rand(1, sides); 
			if (bRolls > 0 && roll <= sides / 2) {
				int newRoll = 0;
				for (int c = bRolls; c > 0; --c) {
					int newRoll = r.rand(1, sides);
					if (newRoll > roll) {
						roll = newRoll;
						if (roll == sides) { break; }
					}
				}
			}
		}
		if (roll <= sides / 2) { bRolls++; }
		else { bRolls = 0; }
		if (gCrits) {
			if (roll == sides) { numRolls = 0; }
			else { numRolls++; }
		}
		return roll;
	}
};