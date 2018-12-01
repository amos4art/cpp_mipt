#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	vector<double> res;
	double a, b, c;
	cin >> a >> b >> c;

	if (a == 0) {
		res.push_back(-c / b);
	}
	else {
		double right_part = (b*b) / (4 * a*a) - c / a;
		if (right_part >= 0) {
			double right_sqrt = sqrt(right_part);
			res.push_back(right_sqrt - b / (2 * a));
			double second = -right_sqrt - b / (2 * a);
			if (second != res[0]) {
				res.push_back(second);
			}
		}
	}
	
	for (double x : res) {
		cout << x;
	}

	return 0;
}