class StatClass {
	// roll - 1 = index
	// index + 1 = roll
public:
	StatClass() { init(); }
	void addStat(int roll) {
		counter[roll - 1]++;
		dataSize++;
	}
	void clearStats() {
		init();
		dataSize = 0;
	}
	float getAvg() {
		if (dataSize == 0) { return 0.0f; }
		float sum = (float)getSum();
		return sum / dataSize;
	}
	float getVar() {
		if (dataSize == 0) { return 0.0f; }
		float avg = getAvg();
		float squaredDiffSum = 0.0f;

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < counter[i]; ++j) {
				float diff = (i + 1) - avg;
				squaredDiffSum += diff * diff;
			}
		}
		return squaredDiffSum / dataSize;

	}
	float getStDv() { return std::sqrt(getVar()); }

private:
	void init() {
		for (int i = 0; i < 20; i++) {
			counter[i] = 0;
		}
	}
	int counter[20];
	int dataSize = 0;
	int getSum() {
		int sum = 0;
		for (int i = 0; i < 20; i++) {
			sum += counter[i] * (i+1);
		}
		return sum;
	}
	bool isEmpty() const {
		for (int i = 0; i < 20; i++) {
			if (counter[i] != 0) { return false; }
		}
		return true;
	}
};
