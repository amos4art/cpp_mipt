#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
ADD i s
Добавить дело с названием s в день i.

NEXT
Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий, добавленные дни изначально не будут содержать дел. Если же в новом месяце меньше дней, дела со всех удаляемых дней необходимо будет переместить на последний день нового месяца.

Обратите внимание, что количество команд этого типа может превышать 11.

DUMP i
Вывести все дела в день i.

Изначально текущим месяцем считается январь. Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.*/

int main() {
	int q, d;
	string operand, task;
	vector<int> days_in_monthes = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	vector<vector<string>> tasks(31);
	int curren_month = 0;
	
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> operand;
		if (operand == "ADD") {
			cin >> d;
			cin >> task;
			tasks[d].push_back(task);
		}
		else if (operand == "NEXT") {
			++curren_month;
			if (curren_month == days_in_monthes.size()) {
				curren_month = 1;
			}
			vector<vector<string>> new_tasks(days_in_monthes[curren_month]);


			v1.insert(end(v1), begin(v2), end(v2));


			tasks = new_tasks;
			
		}
		else if (operand == "DUMP") {
			cin >> d;
			for (auto t : tasks[d]) {
				cout << t << endl;
			}
		}
	}

	return 0;
}