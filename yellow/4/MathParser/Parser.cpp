#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	int x;
	string y;
	uint32_t N;

	cin >> x;
	cin >> N;

	string res;
	
	for (auto i = 0; i < N; ++i) {
		res.append("(");
	}
		
	res.append(to_string(x));

	for (auto i = 0; i < N; ++i) {
		res.append(")");

		string oper, val;

		cin >> oper >> val;

		res.append(" ");
		res.append(oper);
		res.append(" ");
		res.append(val);
	}

	cout << res;

	return 0;
}
