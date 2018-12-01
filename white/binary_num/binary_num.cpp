#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x;
	vector<int> binary;
	cin >> x;

	while (x > 0) {
		binary.push_back(x % 2);
		x = x / 2;
	}

	for (int i = binary.size() - 1; i >= 0; --i) {
		cout << binary[i];
	}

	return 0;
}