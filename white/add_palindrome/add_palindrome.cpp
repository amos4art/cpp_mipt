#include <string>
#include <vector>

using namespace std;

bool IsPalindrome(string s) {
	bool result = true;
	int len = s.size();
	for (int i = 0; i < len/2; ++i) {
		if (s[i] != s[len - 1 - i]) {
			result = false;
			break;
		}
	}
	
	return result;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string>	result;

	for (auto w : words) {
		if (w.size() >= minLength) {
			if (IsPalindrome(w)) {
				result.push_back(w);
			}
		}		
	}

	return result;
}
