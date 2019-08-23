#include "database.h"


void Database::Add(const Date& date, const string& event) {
	events[date].insert(event);
};

void Database::Print(ostream& out) const {
	for (auto& d : events) {
		for (auto& e : d.second) {
			out << d.first << ' ' << e << endl;
		}
	}
};


