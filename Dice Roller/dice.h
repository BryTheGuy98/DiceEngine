#include <random>
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
	std::random_device rd;
	std::mt19937 gen = std::mt19937(rd());
	int getRandom(int min, int max) {
		std::uniform_int_distribution<> distrib(min, max);
		return distrib(gen);
	}
	Dice(int s) : sides(s) {}
};

class rDice : public Dice {			// True Random
public:
	rDice(int s, bool c) : Dice(s), gCrits(c) {}
	rDice(int s) : Dice(s), gCrits(false)  {}
private:
	const bool gCrits;
	int numRolls = 0;
	int getRoll() override {
		int roll;
		if (gCrits && numRolls == sides-1) {
			roll = sides;
		}
		else {
			roll = getRandom(1, sides);
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
			std::swap(nums[i], nums[getRandom(0, sides-1)]);
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
	const int ranMax = 100000;
	int getRoll() override {
		int roll = 0;
		if (gCrits && numRolls == sides - 1) {
			roll = sides;
		}
		else {
			const int ran = getRandom(1, ranMax);
			for (int i = 1; i < sides; ++i) {
				if (ran < ((ranMax / sides) * i) - ((ranMax / sides) * bRolls)) {
					roll = i;
					break;
				}
			}
			if (roll == 0) { roll = sides; }
		}
		if (roll <= sides / 2) { bRolls++; }
		else { bRolls = 0; }
		if (roll == sides) { numRolls = 0; }
		else { numRolls++; }
		return roll;
	}
};