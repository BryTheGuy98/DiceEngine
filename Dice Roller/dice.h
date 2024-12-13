#include <random>
#include <stack>

class Dice {
public:
	int sides;
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

class cDice : public Dice {
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