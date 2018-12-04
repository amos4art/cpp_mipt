#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int q;
	string operand;
	map<string, vector<string>> buses;
	map<string, vector<string>> stops;

	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operand;
		if (operand == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus;
			cin >> stop_count;
			buses[bus].resize(stop_count);
			for (auto& stop : buses[bus]) {
				cin >> stop;
				stops[stop].push_back(bus);
			}
		}
		else if (operand == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			if (stops.count(stop) == 0) {
				cout << "No stop";
			}
			else {
				for (auto bus : stops[stop]) {
					cout << bus << " ";
				}
			}
			cout << endl;
		}
		else if (operand == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if (buses.count(bus) == 0) {
				cout << "No bus" << endl;
			}
			else {
				for (auto stop : buses[bus]) {
					cout << "Stop " << stop << ": ";
					if (stops[stop].size() == 1) {
						cout << "no interchange";
					}
					else {						
						for (auto b : stops[stop]) {
							if (b != bus) {
								cout << b << " ";
							}							
						}
					}
					cout << endl;
				}
			}
		}
		else if (operand == "ALL_BUSES") {
			if (buses.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (auto bus : buses) {
					cout << "Bus " << bus.first << ": ";
					for (auto stop : bus.second) {
						cout << stop << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}