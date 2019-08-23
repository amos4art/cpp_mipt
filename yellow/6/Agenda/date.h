#pragma once

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Date {
public:
	Date(int year, int month, int day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	//Date& operator=(const Date& rhs);

private:
	int Year;
	int Month;
	int Day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& out, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
