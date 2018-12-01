#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int result = -2;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'f') {
			++result;
			if (result == 2) {
				result = i;
				break;
			}
		}
	}

	cout << result;

	return 0;
}