#include <set>
#include <iostream>

using namespace std;


set<int>::const_iterator FindNearestElement(
	const set<int>& numbers,
	int border) {

	if (numbers.size() == 0) {
		return end(numbers);
	}


	set<int>::const_iterator it = numbers.find(border);
	if (it != end(numbers)) {
		return it;
	}

	set<int>::const_iterator l_it = numbers.lower_bound(border);

	if (l_it == numbers.begin()) {
		return l_it;
	}

	set<int>::const_iterator l_it_prev = prev(l_it);

	if (l_it != end(numbers)) {
		return border - *l_it_prev <= *l_it - border ? l_it_prev : l_it;
	}
	else {
		return l_it_prev;
	}
}




int main() {
	set<int> numbers = { 1, 4, 6 };
	cout <<
		*FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 6) << " " <<
		*FindNearestElement(numbers, 100) << endl;

	set<int> empty_set;

	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}