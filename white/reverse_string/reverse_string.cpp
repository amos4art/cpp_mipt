#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
	
public:
	ReversibleString() {
		_string = "";
	}
	
	ReversibleString(const string& s) {
		_string = s;
	}

	void Reverse() {
		reverse(_string.begin(), _string.end());
	}

	string ToString() const {
		string s;
		s = _string;
		return s;
	}
	
private:
	string _string;
};
