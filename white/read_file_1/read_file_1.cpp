#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadFile(const string& file) {
	ifstream input(file);
	if (input) {
		string s;
		while (getline(input, s)) {
			cout << s << endl;
		}
	}
}

int main() {
	ReadFile("input.txt");
	return 0;
}