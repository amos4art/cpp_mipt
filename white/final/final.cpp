#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <exception>
#include <iomanip>
/*
#include <regex>
*/

using namespace std;

class Date {
public:

	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
	
	Date() {
		year = 0;
		month = 0;
		day = 0;
	}

	Date(int y, int m, int d) {
		year = y;
		month = m;
		if (month < 1 || month > 12) {
			cout << "Month value is invalid: " << month << endl;
			throw invalid_argument("wrong format");
		}
		day = d;
		if (day < 1 || day > 31) {
			cout << "Day value is invalid: " << day << endl;
			throw invalid_argument("wrong format");
		}
	}


private:
	int year, month, day;
};

ostream& operator<<(ostream& out, const Date& date) {
	out << setfill('0');
	out << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
	return out;
}

istream& operator>>(istream& in, Date& date) {
	int y = date.GetYear();
	int m = date.GetMonth();
	int d = date.GetDay();
	
	string str;
	in >> str;
	
	/*too slow
	if (!regex_match(str, regex("\-?[0-9]+\-{1,2}[0-9]+\-{1,2}[0-9]+"))) {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}
	*/
	
	stringstream mystream(str);

	mystream >> y;
	if (mystream.fail()) {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}
	
	if (mystream.peek() != '-') {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}	
	mystream.ignore(1);
	
	mystream >> m;
	if (mystream.fail()) {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}
	
	if (mystream.peek() != '-') {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}	
	mystream.ignore(1);
	
	mystream >> d;
	if (mystream.fail()) {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}

	if (mystream.rdbuf()->in_avail() > 0) {
		cout << "Wrong date format: " << str << endl;
		throw invalid_argument("wrong format");
	}
	
	date = Date(y, m, d);

	return in;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		}
		else {
			return lhs.GetMonth() < rhs.GetMonth();
		}
	}
	else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

typedef set<string> EventList;
typedef map<Date, EventList> EventDict;

class Events {
public:
	void add(const Date& date, const string& event) {
		_events[date].insert(event);	
	}
	
	int del(const Date& date) {
		int n = 0;
		
		if (_events.count(date) > 0) {
			n = _events[date].size();
			_events.erase(date);
		}
		
		cout << "Deleted " << n << " events" << endl;
		return n;
	}

	bool del(const Date& date, const string& event) {
		bool result = false;

		if (_events.count(date) > 0) {
			if (_events[date].count(event) > 0) {
				_events[date].erase(event);
				result = true;
			}			
		}
		
		if (result) {
			cout << "Deleted successfully" << endl;
		}
		else {
			cout << "Event not found" << endl;
		}		
		return result;
	}

	void find(const Date& date) const {
		if (_events.count(date) > 0) {
			for (auto& e : _events.at(date)) {
				cout << e << endl;
			}
		}
	};
	
	void print() const {
		for (auto& d : _events) {
			for (auto& e : d.second) {
				cout << d.first << ' ' << e << endl;
			}				
		}
	};

private:
	EventDict _events;
};


int main() {
	
	string line, oper;

	Events events;

	while (getline(cin, line)) {
		if (line == "") {
			continue;
		}
		
		try {
			stringstream mystream(line);
			mystream >> oper;

			if (oper == "Add") {
				Date d;
				string e = "";
				mystream >> d >> e;
				events.add(d, e);
			}
			else if (oper == "Del") {
				Date d;
				mystream >> d;
				if (!mystream.eof()) {
					string e = "";
					mystream >> e;
					events.del(d, e);
				}
				else {
					events.del(d);
				}
			}
			else if (oper == "Find") {
				Date d;
				mystream >> d;
				events.find(d);
			}
			else if (oper == "Print") {
				events.print();
			}
			else {
				cout << "Unknown command: " << oper << endl;
			}
		}
		catch (invalid_argument& e) {
			break;
		}
		
	}
	
	return 0;
}