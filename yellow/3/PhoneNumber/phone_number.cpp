#include <sstream>
#include <cassert>
#include "phone_number.h"


PhoneNumber::PhoneNumber(const string &international_number){
	stringstream buf(international_number);
	try {
		char delim;
		buf >> delim;
		if (delim != '+') {
			throw invalid_argument("invalid");
		}
		getline(buf, country_code_, '-');
		if (country_code_ == "") {
			throw invalid_argument("invalid");
		}
		getline(buf, city_code_, '-');
		if (city_code_ == "") {
			throw invalid_argument("invalid");
		}
		getline(buf, local_number_);
		if (local_number_ == "") {
			throw invalid_argument("invalid");
		}
	}
	catch (...) {
		throw invalid_argument("Invalid number");
	}

}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const{
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	stringstream buf;
	buf << "+" << GetCountryCode() << "-" << GetCityCode() << "-" << GetLocalNumber();
	string res;
	buf >> res;
	return res;
}