#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadFile(const string& file) {
	ifstream input(file);
	
	double num;

	cout << fixed << setprecision(3);

	while (input >> num) {
		cout << num << endl;
	}

}

int main() {
	ReadFile("input.txt");
	return 0;
}