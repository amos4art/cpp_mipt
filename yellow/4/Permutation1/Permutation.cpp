#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVector(const vector<int>& vec) {
	for (auto& i : vec) {
		cout << i << " ";
	}
	cout << endl;
}


int main() {
	int N;
	cin >> N;
	vector<int> myvec;

	for (int i = N; i >= 1; --i) {
		myvec.push_back(i);
	}

	PrintVector(myvec);

	while (prev_permutation(begin(myvec), end(myvec))) {
		PrintVector(myvec);
	}
	
	return 0;

}