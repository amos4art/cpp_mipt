#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		mylist.push_back(s);

	}
	vector<string> GetSortedStrings() {
		vector<string> s_temp;
		s_temp = mylist;
		sort(begin(s_temp), end(s_temp));
		return s_temp;
	}
private:
	vector<string> mylist;
};
