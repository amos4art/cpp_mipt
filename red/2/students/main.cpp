#include "student.h"
#include "test_runner.h"
#include <algorithm>

using namespace std;

#ifdef TEST_BUILD
#include <chrono>
using namespace std::chrono;

class LogDuration {
public:
	LogDuration() : start(steady_clock::now()) {
	}
	~LogDuration() {
		auto finish = steady_clock::now();
		auto dur = finish - start;
		cerr << duration_cast<milliseconds>(dur).count() << "ms" << endl;
	}
private:
	steady_clock::time_point start;
};
#endif


//Оптимизируйте эту функцию
bool Compare(const Student& first, const Student& second) {
  return first.Less(second);
}

void TestComparison() {
#ifdef TEST_BUILD
	LogDuration log;
#endif
	
	Student newbie {
    "Ivan", "Ivanov", {
      {"c++", 1.0},
      {"algorithms", 3.0}
    },
    2.0
  };

  Student cpp_expert {
    "Petr", "Petrov", {
      {"c++", 9.5},
      {"algorithms", 6.0}
    },
    7.75
  };

  Student guru {
    "Sidor", "Sidorov", {
      {"c++", 10.0},
      {"algorithms", 10.0}
    },
    10.0
  };

  Assert(Compare(guru, newbie), "test1");
  Assert(Compare(guru, cpp_expert), "test2");
  Assert(!Compare(newbie, cpp_expert), "test3");
}

void TestSorting() {
#ifdef TEST_BUILD
	LogDuration log;
#endif
	vector<Student> students {
    {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
    {"Semen", "Semenov", {{"maths", 4.}}, 4.},
    {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
    {"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
	{"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
	{"Semen", "Semenov", {{"maths", 4.}}, 4.},
	{"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
	{"Petr", "Petrov", {{"maths", 3.}}, 3.},
    {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
  };
  sort(students.begin(), students.end(), Compare);
  Assert(is_sorted(students.begin(), students.end(),
    [](Student first, Student second) {
      return first.Less(second);
    }), "test sorting"
  );
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestComparison);
  RUN_TEST(tr, TestSorting);
  return 0;
}