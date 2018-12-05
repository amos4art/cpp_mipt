#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
	int q;	
	map<set<string>, int> routes;

	cin >> q;

	for (int i = 0; i < q; ++i) {
		int stop_count;
		cin >> stop_count;
		set<string> stops;
		
		for (int i = 0; i < stop_count; ++i) {
			string stop;
			cin >> stop;
			stops.insert(stop);
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