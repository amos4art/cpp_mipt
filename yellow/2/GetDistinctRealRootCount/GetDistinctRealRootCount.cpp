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
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
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

int GetDistinctRealRootCount(double a, double b, double c) {
	return 0;
}


void TestConst() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 0), 0, "const all zero");
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "const c = 1");
	AssertEqual(GetDistinctRealRootCount(0, 0, 99.9), 0, "const c = 99.9");
	AssertEqual(GetDistinctRealRootCount(0, 0, -0.001), 0, "const c = -0.001");
}


void TestLinear() {
	AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "linear 1 + 1");
	AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "linear 1 + 0");
}


void TestQuadratic() {
	AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "quadr 1 + 0 + 0");
	AssertEqual(GetDistinctRealRootCount(99, 0, 0), 1, "quadr 99 + 0 + 0");
	AssertEqual(GetDistinctRealRootCount(1, 0, -1), 2, "quadr 1 + 0 - 1");
	AssertEqual(GetDistinctRealRootCount(1, 0, -0.001), 2, "quadr 1 + 0 - 0.001");
	AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "quadr 1 + 0 + 1");
	AssertEqual(GetDistinctRealRootCount(1, 1, 10), 0, "quadr 1 + 1 + 10");
}


int main() {
	TestRunner runner;
	runner.RunTest(TestConst, "TestConst");
	runner.RunTest(TestLinear, "TestLinear");
	runner.RunTest(TestQuadratic, "TestQuadratic");
	return 0;
}