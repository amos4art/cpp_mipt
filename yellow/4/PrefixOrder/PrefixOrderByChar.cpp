#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, 
	RandomIt range_end, char prefix) {

	RandomIt it_le = lower_bound(range_begin, range_end, prefix, [](const string& i, const char& v) {return i[0] < v; });
	
	RandomIt it_ge = upper_bound(range_begin, range_end, prefix, [](const char& v, const string& i) {return v < i[0]; });
	
	return make_pair(it_le, it_ge);
}

/*
int main() {
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

	const auto m_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto p_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " <<
		(p_result.second - begin(sorted_strings)) << endl;

	const auto z_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " <<
		(z_result.second - begin(sorted_strings)) << endl;

	return 0;
}
*/