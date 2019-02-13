#include <iostream>

using namespace std;

int main() {
	int n, r;
	uint64_t w, h, d;
	//uint16_t w, h, d;  // in this case we need type casting 
	uint64_t v = 0;
	uint64_t m;

	cin >> n >> r;

	for (int i = 0; i < n; ++i) {
		cin >> w >> h >> d;
		v += w * h * d;
	}

	m = v * r;

	cout << m << endl;

	return 0;
}