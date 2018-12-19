#include <string>
#include <exception>
#include <sstream>
#include <iostream>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		stringstream s;
		s << left << " != " << right;
		throw runtime_error(s.str());
	}
}


int main() {
	try {
		EnsureEqual("C++ White", "C++ White");
		EnsureEqual("C++ White", "C++ Yellow");
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
	return 0;
}