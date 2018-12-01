using namespace std;

int Factorial(int x) {
	if (x < 0) {
		return 1;
	}
	else {
		int result = 1;
		for (int i = 1; i <= x; ++i) {
			result *= i;
		}
		return result;
	}
}
