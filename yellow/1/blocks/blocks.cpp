#include <iostream>

using namespace std;

int main() {
	int n, r;
	uint64_t w, h, d;
	//uint16_t w, h, d;
	uint64_t m = 0;

	cin >> n >> r;

	for (int i = 0; i < n; ++i) {
		cin >> w >> h >> d;
		m += w * h * d * r;
	}

	cout << m << endl;

	return 0;
}