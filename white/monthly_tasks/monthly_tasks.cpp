#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> DAYS_IN_MONTHES = 
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MONTH_COUNT = DAYS_IN_MONTHES.size();

int main() {
	int q, d;
	string operand, task;
	
	vector<vector<string>> tasks(31);
	int curren_month = 0;
	
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operand;
		if (operand == "ADD") {
			cin >> d;
			cin >> task;
			tasks[d - 1].push_back(task);
		}
		else if (operand == "NEXT") {
			curren_month = (curren_month + 1) % MONTH_COUNT;

			vector<vector<string>> new_tasks(tasks);

			new_tasks.resize(DAYS_IN_MONTHES[curren_month]);

			if (new_tasks.size() < tasks.size()) {
				for (int k = new_tasks.size(); k < tasks.size(); ++k) {
					new_tasks[new_tasks.size() - 1].insert(end(new_tasks[new_tasks.size() - 1]), begin(tasks[k]), end(tasks[k]));
				}
			}	
			
			tasks = new_tasks;			
		}
		else if (operand == "DUMP") {
			cin >> d;
			cout << tasks[d - 1].size() << " ";
			for (auto t : tasks[d - 1]) {
				cout << t << " ";
			}
			cout << endl;
		}
	}

	return 0;
}