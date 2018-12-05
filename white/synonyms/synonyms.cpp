#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	int q;
	string operand;
	map<string, set<string>> syn_dict;

	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operand;
		if (operand == "ADD") {
			string word1, word2;
			cin >> word1;
			cin >> word2;
			syn_dict[word1].insert(word2);
			syn_dict[word2].insert(word1);
		}
		else if (operand == "COUNT") {
			string word;
			cin >> word;
			cout << syn_dict[word].size() << endl;
		}
		else if (operand == "CHECK") {
			string word1, word2;
			cin >> word1;
			cin >> word2;
			if (syn_dict[word1].count(word2) > 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}