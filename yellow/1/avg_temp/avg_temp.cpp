#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int high = 0;
	int64_t avg;
	int64_t summ = 0;
	vector<int64_t> high_vector;

	cin >> n;

	vector<int64_t> temp(n);

	for (int64_t& t : temp) {
		cin >> t;
		summ += t;
	}

	avg = summ / n;


	for (unsigned i = 0; i < temp.size(); ++i) {
		if (temp[i] > avg) {
			++high;
			high_vector.push_back(i);
		}
	}

	cout << high << endl;

	for (auto& h : high_vector) {
		cout << h << " ";
	}

	return 0;
}