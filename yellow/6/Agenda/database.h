#pragma once

#include <string>
#include <vector>
#include <set>
#include <map>
#include "date.h"

using namespace std;


typedef set<string> EventSet;
typedef vector<string> EventVector;
typedef pair<set<string>, vector<string>> EventList;
typedef map<Date, EventList> EventDict;

class Database {
public:
	Database() {};

	void Add(const Date& date, const string& event);

	void Print(ostream& out) const;

	pair<Date, string> Last(const Date& date) const;

	template <class P>
	int RemoveIf(P predicate) {
		int n = 0;

		EventDict::iterator it_date = events.begin();
		while (it_date != events.end()) {
			EventVector::iterator it_event = (*it_date).second.second.begin();
			while (it_event != (*it_date).second.second.end()) {
				if (predicate((*it_date).first, *it_event)) {
					(*it_date).second.first.erase(*it_event);
					it_event = (*it_date).second.second.erase(it_event);					
					n++;
				}
				else {
					it_event++;
				}				
			}
			
			if ((*it_date).second.second.size() == 0) {
				it_date = events.erase(it_date);
			}
			else {
				it_date++;
			}			
		}		

		return n;
	};

	template <class P>
	vector<pair<Date, string>> FindIf(P predicate) const {
		vector<pair<Date, string>> found;

		EventDict::const_iterator it_date = events.cbegin();
		while (it_date != events.cend()) {
			EventVector::const_iterator it_event = (*it_date).second.second.cbegin();
			while (it_event != (*it_date).second.second.cend()) {
				if (predicate((*it_date).first, *it_event)) {
					found.push_back({ (*it_date).first, *it_event });
				}
				it_event++;
			}
			it_date++;
		}

		return found;
	};

private:
	EventDict events;
};

ostream& operator<<(ostream& out, const pair<Date, string>& event_item);