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
	float getAverage() {
		float sum = (float)getSum();
		return sum / (float)dataSize;
	}
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
