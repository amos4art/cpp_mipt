#pragma once

#include <string>
#include <vector>
#include <set>
#include <map>
#include "date.h"

using namespace std;


typedef set<string> EventList;
typedef map<Date, EventList> EventDict;

class Database {
public:
	Database() {};

	void Add(const Date& date, const string& event);

	void Print(ostream& out) const;

	template <class P>
	int RemoveIf(P predicate) {
		return 0;
		/*
		int n = 0;

		if (_events.count(date) > 0) {
			n = _events[date].size();
			_events.erase(date);
		}

		cout << "Deleted " << n << " events" << endl;
		return n;
		*/

	};

	template <class P>
	vector<string> FindIf(P predicate) {
		return { "1", "2", "3" };
		/*
		if (_events.count(date) > 0) {
			for (auto& e : _events.at(date)) {
				cout << e << endl;
			}
		}
		*/
	};

	string Last(const Date& date) {
		return "last";
	};

private:
	EventDict events;
};