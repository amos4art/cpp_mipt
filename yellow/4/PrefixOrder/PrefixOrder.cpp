#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end,
	const string& prefix){

	auto len = prefix.length();

	RandomIt it_le = lower_bound(range_begin, range_end, prefix, [len](const string& i, const string& v) {return i.substr(0, len) < v; });

	RandomIt it_ge = upper_bound(range_begin, range_end, prefix, [len](const string& v, const string& i) {return v < i.substr(0,len); });

	return make_pair(it_le, it_ge);
}


int main() {
	const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << endl;

	return 0;
}