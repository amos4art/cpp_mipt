#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string word) {
	map<char, int> result;

	for (auto c : word) {
		++result[c];
	}

	return result;
}

int main() {
	int n;
	string first, second;

	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		string w1, w2;
		
		cin >> first;
		cin >> second;

		map<char, int> first_dict = BuildCharCounters(first);
		map<char, int> second_dict = BuildCharCounters(second);

		if (first_dict == second_dict) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}		
	}

	return 0;
}