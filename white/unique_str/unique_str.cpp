#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int q;
	set<string> str;

	cin >> q;

	for (int i = 0; i < q; ++i) {
		string s;
		cin >> s;		
		str.insert(s);
	}
	cout << str.size();

	return 0;

}