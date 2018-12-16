#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void ReadFile(const string& file) {
	ifstream input(file);

	string s;
	int n, m;

	getline(input, s, ' ');
	n = atoi(s.c_str());

	getline(input, s);
	m = atoi(s.c_str());
	
	for (int i = 0; i < n ; ++i) {
		int val;
		for (int i = 0; i < m - 1; ++i) {
			input >> val;
			input.ignore(1);
			cout << setw(10) << val << ' ';
		}
		input >> val;
		input.ignore(1);
		cout << setw(10) << val;
		cout << endl;
	}


}

int main() {
	ReadFile("input.txt");
	return 0;
}