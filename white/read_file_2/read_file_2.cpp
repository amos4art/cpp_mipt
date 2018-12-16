#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadFile(const string& file, const string& out_file) {
	ifstream input(file);
	ofstream output(out_file);
	if (input) {
		string s;
		while (getline(input, s)) {
			output << s << endl;
		}
	}
}

int main() {
	ReadFile("input.txt", "output.txt");
	return 0;
}