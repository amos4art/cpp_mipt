#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {

	vector<string> res = {};

	auto it = begin(s);

	while (it != end(s)) {

		auto next_it = find_if(it, end(s), [](const char& i) {return i == ' '; });

		res.push_back(string(it, next_it));

		if (next_it != end(s)) {
			it = next_it + 1;
		}
		else {
			it = next_it;
		}		
	}

	return res;
}


int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}
