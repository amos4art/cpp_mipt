#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, c, first;
	cin >> a >> b >> c;

	if (a == 0 && b != 0)
		cout << -c / b;
	else {
		double right_part = (b*b) / (4 * a*a) - c / a;
		if (right_part >= 0) {
			double right_sqrt = sqrt(right_part);
			first = right_sqrt - b / (2 * a);
			double second = -right_sqrt - b / (2 * a);
			if (first != second)
				cout << first << " " << second;
			else 
				cout << first;
		}
	}
	
	return 0;
}