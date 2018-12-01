#include <iostream>
#include <string>

using namespace std;

int main() {
	string min, a, b;
	cin >> min >> a >> b;

	if (a < min) {
		min = a;
	}
	if (b < min) {
		min = b;
	}

	cout << min;

	return 0;
}