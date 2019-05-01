#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


string CutDigits(string& input) {
	string result;
	copy_if(input.begin(), input.end(), back_inserter(result), [](char c) { return '0' <= c && c <= '9'; });
	auto itErase = remove_if(input.begin(), input.end(), [](char c) { return '0' <= c && c <= '9'; });
	input.erase(itErase, input.end());
	return result;
}


int main() {
	int x;
	string y;
	uint32_t N;

	map<char, int> operations = { {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1} };

	cin >> x;
	cin >> N;

	string prefix, postfix;
	int prefix_decreaser = 0;
	int prev_oper = 0;
	bool first = true;

	for (auto i = 0; i < N; ++i) {
		prefix.append("(");
	}

	postfix.append(to_string(x));


	for (auto i = 0; i < N; ++i) {

		char oper;
		string val;

		cin >> oper >> val;

		if (operations[oper] > prev_oper && !first) {
			postfix.append(")");
		}
		else {
			++prefix_decreaser;
			first = false;
		}
		prev_oper = operations[oper];
		
		postfix.append(" ");
		postfix.append(string(1, oper));
		postfix.append(" ");
		postfix.append(val);
	}


	prefix.erase(prefix.begin() + N - prefix_decreaser, prefix.end());

	prefix.append(postfix);
	
	cout << prefix;

	return 0;
}