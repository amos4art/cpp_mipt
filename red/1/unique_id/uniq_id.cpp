#include <string>
#include <vector>
using namespace std;

#define PREPARE_ID(x) uniq ## x
#define PREPARE_ID2(x) PREPARE_ID(x)
#define UNIQ_ID PREPARE_ID2(__LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}