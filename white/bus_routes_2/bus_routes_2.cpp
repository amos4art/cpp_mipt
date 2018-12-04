#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int q;
	map<vector<string>, int> routes;
	
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int stop_count;
		cin >> stop_count;
		vector<string> stops;
		stops.resize(stop_count);

		for (auto& stop : stops) {
			cin >> stop;
		}		

		if (routes.count(stops) == 0) {
			int s;
			s = routes.size() + 1;
			routes[stops] = s;
			cout << "New bus " << s << endl;
		}
		else {
			cout << "Already exists for " << routes[stops] << endl;
		}
	}
	return 0;
}