#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int q;
	string operand;
	map<string, string> capitals;

	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operand;
		if (operand == "CHANGE_CAPITAL") {
			string country, new_cap;
			cin >> country;
			cin >> new_cap;			
			if (capitals.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << new_cap << endl;
			}
			else if (capitals[country] == new_cap) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
			else {
				cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_cap << endl;
			}
			capitals[country] = new_cap;
		}
		else if (operand == "RENAME") {
			string old_country, new_country;
			cin >> old_country;
			cin >> new_country;
			
			if (old_country == new_country || capitals.count(old_country) == 0 || capitals.count(new_country) > 0) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << old_country << " with capital " << capitals[old_country] << " has been renamed to " << new_country << endl;
				capitals[new_country] = capitals[old_country];
				capitals.erase(old_country);
			}			
		}
		else if (operand == "ABOUT") {
			string country;
			cin >> country;

			if (capitals.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital " << capitals[country] << endl;
			}
		}
		else if (operand == "DUMP") {
			if (capitals.size() == 0) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (auto c : capitals) {
					cout << c.first << "/" << c.second << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
