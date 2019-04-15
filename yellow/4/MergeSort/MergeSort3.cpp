#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

	if (distance(range_begin, range_end) < 2) {
		return;
	}

	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	auto first = begin(elements);
	auto second = begin(elements);
	
	advance(first, distance(begin(elements), end(elements)) / 3);
	advance(second, distance(begin(elements), end(elements)) * 2 / 3);

	if (distance(begin(elements), first) > 1) {
		MergeSort(begin(elements), first);
	}

	if (distance(first, second) > 1) {
		MergeSort(first, second);
	}

	if (distance(second, end(elements)) > 1) {
		MergeSort(second, end(elements));
	}

	vector<typename RandomIt::value_type> temp;

	merge(begin(elements), first, first, second, back_inserter(temp));

	merge(begin(temp), end(temp), second, end(elements), range_begin);
}


int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
