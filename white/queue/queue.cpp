#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int q, n;
	string operand;
	vector<int> queue;
	vector<bool> worry;

	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operand;
		if (operand == "WORRY") {
			cin >> n;
			worry[n] = true;
		}
		else if (operand == "QUIET") {
			cin >> n;
			worry[n] = false;
		}
		else if (operand == "COME") {
			cin >> n;
			queue.resize(queue.size() + n);
			worry.resize(worry.size() + n);
			//worry.assign(worry.size() - 1, false, n);
		}
		else if (operand == "WORRY_COUNT") {
			cout << count(begin(worry), end(worry), true) << endl;
		}

	}
	
	return 0;
}




