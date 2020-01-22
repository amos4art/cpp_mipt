#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y)		\
do {								\
	out << (x) << endl << (y) << endl;				\
} while (0)

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
	
	output.str("");
	output.clear();
	
	if (false)
		PRINT_VALUES(output, 5, "red belt");
	else
		PRINT_VALUES(output, 2, "white belt");
	ASSERT_EQUAL(output.str(), "2\nwhite belt\n");

	output.str("");
	output.clear();

	PRINT_VALUES(output, 2*4, 5+9);
	ASSERT_EQUAL(output.str(), "8\n14\n");


  }, "PRINT_VALUES usage example");
}
