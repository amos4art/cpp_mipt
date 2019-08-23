#include "date.h"
#include <iomanip>


Date::Date(int year, int month, int day) : Year(year), Month(month), Day(day) {
};

int Date::GetYear() const {
	return Year;
};

int Date::GetMonth() const {
	return Month;
};

int Date::GetDay() const {
	return Day;
};

/*
Date& Date::operator=(const Date& rhs) {

}
*/

Date ParseDate(istream& is) {
	int y = 0;
	int m = 0;
	int d = 0;

	string str;
	is >> str;

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

	return { y, m, d };
}


ostream& operator<<(ostream& out, const Date& date) {
	out << setfill('0');
	out << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
	return out;
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


bool operator<=(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() <= rhs.GetDay();
		}
		else {
			return lhs.GetMonth() < rhs.GetMonth();
		}
	}
	else {
		return lhs.GetYear() < rhs.GetYear();
	}
}


bool operator>(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() > rhs.GetDay();
		}
		else {
			return lhs.GetMonth() > rhs.GetMonth();
		}
	}
	else {
		return lhs.GetYear() > rhs.GetYear();
	}
}


bool operator>=(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() >= rhs.GetDay();
		}
		else {
			return lhs.GetMonth() > rhs.GetMonth();
		}
	}
	else {
		return lhs.GetYear() > rhs.GetYear();
	}
}


bool operator==(const Date& lhs, const Date& rhs) {
	return (lhs.GetYear() == rhs.GetYear()) & (lhs.GetMonth() == rhs.GetMonth()) & (lhs.GetDay() == rhs.GetDay());
}


bool operator!=(const Date& lhs, const Date& rhs) {
	return (lhs.GetYear() != rhs.GetYear()) | (lhs.GetMonth() != rhs.GetMonth()) | (lhs.GetDay() != rhs.GetDay());
}
