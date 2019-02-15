#include <map>;
#include <string>;
#include <exception>;
#include <iostream>;

using namespace std;


template <typename Tkey, typename Tval>
Tval& GetRefStrict(map<Tkey, Tval>& arg, const Tkey& key) {
	try {
		return arg.at(key);
	}
	catch (out_of_range) {
		throw runtime_error("error");
	}		
}


int main() {

	map<int, string> m = { {0, "value"} };
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl;
}