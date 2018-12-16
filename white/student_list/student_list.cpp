#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
	string name;
	string lastname;
	int day;
	int month;
	int year;
};

void PrintName(const vector<Student>& List, int ind) {
	cout << List[ind].name << " " << List[ind].lastname << endl;
}

void PrintDate(const vector<Student>& List, int ind) {
	cout << List[ind].day << "." << List[ind].month << 
		"." << List[ind].year << endl;
}

int main() {
	vector<Student> StudentList;
	int n, m;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string name, lastname;
		int day, month, year;
				
		cin >> name >> lastname >> day >> month >> year;

		StudentList.push_back({ name, lastname, day, month, year });
	}

	cin >> m;

	string oper;
	int ind;

	for (int i = 0; i < m; ++i) {
		cin >> oper >> ind;
		--ind;

		if (ind < 0 || ind >= n) {
			cout << "bad request" << endl;
		}
		else {
			if (oper == "name") {
				PrintName(StudentList, ind);
			}
			else if (oper == "date") {
				PrintDate(StudentList, ind);
			}
			else {
				cout << "bad request" << endl;
			}
		}
	}
}
