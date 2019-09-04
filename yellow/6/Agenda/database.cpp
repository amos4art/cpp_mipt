#include "database.h"


void Database::Add(const Date& date, const string& event) {
	EventDict::iterator it = events.find(date);
	if ( it == events.end() || events[date].first.find(event) == events[date].first.end()) {
		events[date].first.insert(event);
		events[date].second.push_back(event);
	}	
};

void Database::Print(ostream& out) const {
	for (auto& d : events) {
		for (auto& e : d.second.second) {
			out << d.first << ' ' << e << endl;
		}
	}
};

pair<Date, string> Database::Last(const Date& date) const {
	if (events.size() == 0 || (*events.cbegin()).first > date) {
		throw invalid_argument("Invalid date");
	}

	EventDict::const_iterator it_date = events.find(date);
	if (it_date != events.cend()) {
		pair<Date, string> Last = { (*it_date).first, (*it_date).second.second.back() };
		return Last;
	}
	else {
		it_date = events.lower_bound(date);
		it_date--;
		pair<Date, string> Last = { (*it_date).first, (*it_date).second.second.back() };
		return Last;
	}	
}


ostream& operator<<(ostream& out, const pair<Date, string>& event_item) {
	out << event_item.first << ' ' << event_item.second;
	return out;
}
