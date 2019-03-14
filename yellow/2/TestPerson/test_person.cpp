#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/*
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  first_name_log[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  last_name_log[year] = last_name;
  }
  string GetFullName(int year) {
	  string result = "";

	  string f_name = FindName(first_name_log, year);
	  string l_name = FindName(last_name_log, year);

	  if (f_name == "" && l_name == "") {
		  result = "Incognito";
	  }
	  else if (f_name != "" && l_name != "") {
		  result += f_name + " " + l_name;
	  }
	  else if (l_name == "") {
		  result += f_name + " with unknown last name";
	  }
	  else {
		  result += l_name + " with unknown first name";
	  }
	  return result;
  }
private:
	map<int, string> first_name_log;
	map<int, string> last_name_log;

	string FindName(map<int, string>& list, int year) {

		map<int, string>::iterator iter = list.find(year);

		if (list.size() == 0) {
			return "";
		}
		else if (iter != end(list)) {
			return iter->second;
		}
		else {
			iter = list.lower_bound(year);
			if (iter != begin(list)) {
				--iter;
				return iter->second;
			}
			else {
				return "";
			}
		}
	}
};
*/

void TestEmpty() {
	Person p;

	Assert(p.GetFullName(1900) == "Incognito", "Empty person test failure");
	Assert(p.GetFullName(0) == "Incognito", "Empty person test failure");
	Assert(p.GetFullName(1) == "Incognito", "Empty person test failure");
	Assert(p.GetFullName(999) == "Incognito", "Empty person test failure");
	Assert(p.GetFullName(numeric_limits<int>::min()) == "Incognito", "Empty person test failure");
	Assert(p.GetFullName(numeric_limits<int>::max()) == "Incognito", "Empty person test failure");

}


void TestChangeFirstName() {
	Person p;
	
	p.ChangeFirstName(2000, "Sergey");
	Assert(p.GetFullName(2000) == "Sergey with unknown last name", "Change First Name test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change First Name test failure");
	Assert(p.GetFullName(2001) == "Sergey with unknown last name", "Change First Name test failure");

	p.ChangeFirstName(2000, "Vlad");
	Assert(p.GetFullName(2000) == "Vlad with unknown last name", "Change First Name test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change First Name test failure");
	Assert(p.GetFullName(2001) == "Vlad with unknown last name", "Change First Name test failure");

	p.ChangeFirstName(2001, "Sergey");
	Assert(p.GetFullName(2000) == "Vlad with unknown last name", "Change First Name test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change First Name test failure");
	Assert(p.GetFullName(2001) == "Sergey with unknown last name", "Change First Name test failure");

	p.ChangeFirstName(2002, "Misha");
	Assert(p.GetFullName(2030) == "Misha with unknown last name", "Change First Name test failure");
}


void TestChangeLastName() {
	Person p;

	p.ChangeLastName(2000, "Sergey");
	Assert(p.GetFullName(2000) == "Sergey with unknown first name", "Change Last Name test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change First Name test failure");
	Assert(p.GetFullName(2001) == "Sergey with unknown first name", "Change Last Name test failure");

	p.ChangeLastName(2000, "Vlad");
	Assert(p.GetFullName(2000) == "Vlad with unknown first name", "Change Last Name test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change First Name test failure");
	Assert(p.GetFullName(2001) == "Vlad with unknown first name", "Change Last Name test failure");

	p.ChangeLastName(2001, "Sergey");
	Assert(p.GetFullName(2000) == "Vlad with unknown first name", "Change Last Name test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change First Name test failure");
	Assert(p.GetFullName(2001) == "Sergey with unknown first name", "Change Last Name test failure");

	p.ChangeLastName(2002, "Misha");
	Assert(p.GetFullName(2030) == "Misha with unknown first name", "Change Last Name test failure");
}


void TestChangeBothNames() {
	Person p;

	p.ChangeFirstName(2000, "Sergey");
	p.ChangeLastName(2002, "Shpak");

	Assert(p.GetFullName(2000) == "Sergey with unknown last name", "Change Names test failure");
	Assert(p.GetFullName(1999) == "Incognito", "Change Names test failure");
	Assert(p.GetFullName(2003) == "Sergey Shpak", "Change Names test failure");

	p.ChangeLastName(2000, "Pukov");
	Assert(p.GetFullName(2000) == "Sergey Pukov", "Change Names test failure");
	Assert(p.GetFullName(2006) == "Sergey Shpak", "Change Names test failure");


	p.ChangeLastName(1989, "Sraka");
	Assert(p.GetFullName(1988) == "Incognito", "Change Names test failure");
	Assert(p.GetFullName(1999) == "Sraka with unknown first name", "Change Names test failure");

	p.ChangeFirstName(1980, "Misha");
	Assert(p.GetFullName(1989) == "Misha Sraka", "Change Names test failure");

}


int main() {
  TestRunner runner;
  
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestChangeFirstName, "TestChangeFirstName");
  runner.RunTest(TestChangeLastName, "TestChangeLastName");
  runner.RunTest(TestChangeBothNames, "TestChangeBothNames");


  return 0;
}
