#include <vector>

using namespace std;

class Incognizable {
public:
	Incognizable() {
	}

	Incognizable(int number) {
	}

	Incognizable(int number1, int number2) {
	}
};


int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}