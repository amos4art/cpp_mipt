#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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
int GDC(int a, int b) {
	int g = 1;

	if (a == 0) {
		cout << b;
		return 0;
	}

	if (b == 0) {
		cout << a;
		return 0;
	}

	while (a % 2 == 0 && b % 2 == 0) {
		a = double(a) / 2;
		b = double(b) / 2;
		g *= 2;
	}

	int u = a;
	int v = b;

	while (u != 0) {

		if (u % 2 == 0) {
			u = double(u) / 2;
		}

		if (v % 2 == 0) {
			v = double(v) / 2;
		}

		if (u >= v) {
			u -= v;
		}
		else {
			v -= u;
		}
	}

	return g * v;
}

class Rational {
public:
	Rational() {
		num = 0;
		denom = 1;
	}
	Rational(int numerator, int denominator) {
		if (numerator == 0) {
			num = 0;
			denom = 1;
		}
		else {
			int gdc = GDC(abs(numerator), abs(denominator));
			num = numerator / gdc;
			denom = denominator / gdc;

			if (denominator < 0) {
				num *= -1;
				denom *= -1;
			}
		}
	}

	int Numerator() const {
		return num;
	}
	int Denominator() const {
		return denom;
	}
private:
	int num, denom;
};
*/

void TestDefault() {
	Rational r;

	Assert(r.Numerator() == 0, "test default failed");
	Assert(r.Denominator() == 1, "test default failed");
}

void Test1() {
	Rational r(3, 10);

	Assert(r.Numerator() == 3, "test 1 failed");
	Assert(r.Denominator() == 10, "test 1 failed");
}

void Test2() {
	Rational r(8, 12);

	Assert(r.Numerator() == 2, "test 2 failed");
	Assert(r.Denominator() == 3, "test 2 failed");
}

void Test3() {
	Rational r(-4, 6);

	Assert(r.Numerator() == -2, "test 3 failed");
	Assert(r.Denominator() == 3, "test 3 failed");
}

void Test4() {
	Rational r(0, 15);

	Assert(r.Numerator() == 0, "test 4 failed");
	Assert(r.Denominator() == 1, "test 4 failed");
}

void Test5() {
	Rational r(-24, -64);

	Assert(r.Numerator() == 3, "test 5 failed");
	Assert(r.Denominator() == 8, "test 5 failed");
}


int main() {
  TestRunner runner;
  runner.RunTest(TestDefault, "TestDefault");
  runner.RunTest(Test1, "Test1");
  runner.RunTest(Test2, "Test2");
  runner.RunTest(Test3, "Test3");
  runner.RunTest(Test4, "Test4");
  runner.RunTest(Test5, "Test5");
  
  return 0;
}
