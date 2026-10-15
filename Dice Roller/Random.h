#include <string>
#include <ctime>
#include <iostream>
class Random {
private:
	int seed;

	int rng() {
		const long long max = INT_MAX;
		const long long range = max - 1;
		long long state = (static_cast<long long>(seed) % range + range) % range + 1;
		state = (state * 48271) % max;
		seed = static_cast<int>(state);
		return seed;
	}
	int stringToInt(std::string input) {
		int output = 0;
		for (char character : input) {
			output += character;
		}
		return output;
	}
public:
	Random() : seed(static_cast<int>(std::time(nullptr))) {}
	Random(std::string input) : seed(stringToInt(input)) {}
	void resetSeed(std::string newSeed) { seed = stringToInt(newSeed); }
	void resetSeed() { seed = (static_cast<int>(std::time(nullptr))); }

	int rand() { return rng(); } // returns a random number between 1 and 2,147,483,646 (INT_MAX - 1)
	int rand(int min, int max) { // returns a random number between the inputted min and max values, inclusive
		if (min >= max) {
			std::cout << "\nError in RNG class - invalid minimum/maximum values: " << min << ", " << max << "\n";
			return -1;
		}
		int random = rng();
		random = (random % (max - min + 1)) + min;
		return random;
	}
	float randf() { // returns a random float between 0.00 and 1.00
		return static_cast<float>(rng() - 1) / static_cast<float>(INT_MAX - 2);
	}
};