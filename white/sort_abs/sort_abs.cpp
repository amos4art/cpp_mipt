#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(const vector<int>& arr) {
	for (const auto& i : arr) {
		cout << i << " ";
	}
}

int main() {
	int n;
	vector<int> myarray;

	cin >> n;
	myarray.resize(n);

	for (auto& i : myarray) {
		cin >> i;
	}

	sort(begin(myarray), end(myarray), [](int x, int y) {return abs(x) <= abs(y); });
	Print(myarray);

	return 0;
}