#include <iostream>

using namespace std;

int main() {
	int a, b;
	int g = 1;
	cin >> a >> b;
	
	if (a == 0) {
		cout << b;
		return 0;
	}

	if (b == 0) {
		cout << a;
		return 0;
	}

	while (a % 2 == 0 && b % 2 == 0) {
		a = double(a) / 2;
		b = double(b) / 2;
		g *= 2;
	}

	int u = a;
	int v = b;

	while (u != 0) {

		if (u % 2 == 0) {
			u = double(u) / 2;
		}

		if (v % 2 == 0) {
			v = double(v) / 2;
		}

		if (u >= v) {
			u -= v;
		}
		else {
			v -= u;
		}
	}
	
	cout << g * v;
	
	return 0;
}