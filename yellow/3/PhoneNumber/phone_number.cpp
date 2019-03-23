#include <sstream>
#include <cassert>
#include "phone_number.h"


PhoneNumber::PhoneNumber(const std::string &international_number){
	std::stringstream buf(international_number);
	try {
		char delim;
		buf >> delim;
		if (delim != '+') {
			throw std::invalid_argument("invalid");
		}
		getline(buf, country_code_, '-');
		if (country_code_ == "") {
			throw std::invalid_argument("invalid");
		}
		getline(buf, city_code_, '-');
		if (city_code_ == "") {
			throw std::invalid_argument("invalid");
		}
		getline(buf, local_number_);
		if (local_number_ == "") {
			throw std::invalid_argument("invalid");
		}
	}
	catch (...) {
		throw std::invalid_argument("Invalid number");
	}

}

std::string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

std::string PhoneNumber::GetCityCode() const{
	return city_code_;
}

std::string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const {
	std::stringstream buf;
	buf << "+" << GetCountryCode() << "-" << GetCityCode() << "-" << GetLocalNumber();
	std::string res;
	buf >> res;
	return res;
}