#include "phone_number.h"
#include "..\\..\\test_runner.h"

void TruePositive1() {
	PhoneNumber p("+XXX-YYY-ZZZZZZ");
	string country = p.GetCountryCode();
	AssertEqual(country, "XXX", "bad country code");
	string city = p.GetCityCode();
	AssertEqual(city, "YYY", "bad city code");
	string phone = p.GetLocalNumber();
	AssertEqual(phone, "ZZZZZZ", "bad phone");
}

void TruePositive2() {
	PhoneNumber p("+7-495-111-22-33");
	string country = p.GetCountryCode();
	AssertEqual(country, "7", "bad country code");
	string city = p.GetCityCode();
	AssertEqual(city, "495", "bad city code");
	string phone = p.GetLocalNumber();
	AssertEqual(phone, "111-22-33", "bad phone");
}

void TruePositive3() {
	PhoneNumber p("+7-495-1112233");
	string country = p.GetCountryCode();
	AssertEqual(country, "7", "bad country code");
	string city = p.GetCityCode();
	AssertEqual(city, "495", "bad city code");
	string phone = p.GetLocalNumber();
	AssertEqual(phone, "1112233", "bad phone");
}

void TruePositive4() {
	PhoneNumber p("+323-22-460002");
	string country = p.GetCountryCode();
	AssertEqual(country, "323", "bad country code");
	string city = p.GetCityCode();
	AssertEqual(city, "22", "bad city code");
	string phone = p.GetLocalNumber();
	AssertEqual(phone, "460002", "bad phone");
}

void TruePositive5() {
	PhoneNumber p("+1-2-coursera-cpp");
	string country = p.GetCountryCode();
	AssertEqual(country, "1", "bad country code");
	string city = p.GetCityCode();
	AssertEqual(city, "2", "bad city code");
	string phone = p.GetLocalNumber();
	AssertEqual(phone, "coursera-cpp", "bad phone");
}

void TrueNegative6() {
	try {
		PhoneNumber p("1-2-333");
		throw exception("fail");
	}
	catch (invalid_argument& e) {	
	}
	catch (...) {
		throw exception("fail");
	}
}

void TrueNegative7() {
	try {
		PhoneNumber p("+7-1233");
		throw exception("fail");
	}
	catch (invalid_argument& e) {
	}
	catch (...) {
		throw exception("fail");
	}
}

int main() {	TestRunner tr;
	tr.RunTest(TruePositive1, "TruePositive1");
	tr.RunTest(TruePositive2, "TruePositive2");
	tr.RunTest(TruePositive3, "TruePositive3");
	tr.RunTest(TruePositive4, "TruePositive4");
	tr.RunTest(TruePositive5, "TruePositive5");

	tr.RunTest(TrueNegative6, "TrueNegative6");
	tr.RunTest(TrueNegative7, "TrueNegative7");

	return 0;
}