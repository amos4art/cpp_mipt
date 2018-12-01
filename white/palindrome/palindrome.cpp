#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrom(string s) {
	string s2 = s;
	reverse(s2.begin(), s2.end());
	
	if (s == s2) {
		return true;
	}
	else {
		return false;
	}
}
