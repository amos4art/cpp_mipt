#include <string>

using namespace std;

struct Specialization {
	string val;
	explicit Specialization(const string& x) {
		val = x;
	}
};

struct Course {
	string val;
	explicit Course(const string& x) {
		val = x;
	}
};

struct Week {
	string val;
	explicit Week(const string& x) {
		val = x;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(const Specialization& s, const Course& c, const Week& w) {
		specialization = s.val;
		course = c.val;
		week = w.val;
	}
};
