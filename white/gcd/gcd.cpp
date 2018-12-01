#include <iostream>

using namespace std;

int main() {
	int a, b, limit, divisor;
	cin >> a >> b;

	if (a < b) {
		limit = a;
	}
	else {
		limit = b;
	}

	for (int i = 1; i <= limit; ++i) {
		if (a % i == 0 && b % i == 0) {
			divisor = i;
		}
	}

	cout << divisor;

	return 0;
}