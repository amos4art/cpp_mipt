#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
static int pow10(int n)
{
	static int p10[10] = {
		1, 10, 100, 1000, 10000,
		100000, 1000000, 10000000, 100000000, 1000000000
	};

	return p10[n];
}

void Reverse(vector<int>& v) {
	for (int i = 0; i < v.size() / 2; ++i) {
		int tmp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = tmp;
	}
}
*/

int main() {
	int n, avg;
	int summ = 0;
	int high = 0;
	string n_str, s;
	vector<int> high_vector;

	/*
	getline(cin, n_str);
	n = atoi(n_str.c_str());
	*/

	cin >> n;

	vector<int> temp(n);

	for (int& t : temp) {
		cin >> t;
		summ += t;
	}

	/*
	getline(cin, s);
	   
	for (auto& t : temp) {
		int i = s.size() - 1;
		int degree = 0;
		char v;
		do {
			v = s[i];
			if (v != ' ') {
				t += atoi(&v) * pow10(degree);
				++degree;
			}
			s.erase(i);
			--i;
		} while (v != ' ' && i >= 0);
		summ += t;
	}

	Reverse(temp);
	*/

	avg = summ / n;


	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i] > avg) {
			++high;
			high_vector.push_back(i);
		}
	}
	
	cout << high << endl;

	for (auto& h : high_vector) {
		cout << h << " ";
	}

	return 0;
}