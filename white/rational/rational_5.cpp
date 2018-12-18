#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int GDC(int a, int b) {
	int g = 1;

	if (a == 0) {
		cout << b;
		return 0;
	}

	if (b == 0) {
		cout << a;
		return 0;
	}

	while (a % 2 == 0 && b % 2 == 0) {
		a = double(a) / 2;
		b = double(b) / 2;
		g *= 2;
	}

	int u = a;
	int v = b;

	while (u != 0) {

		if (u % 2 == 0) {
			u = double(u) / 2;
		}

		if (v % 2 == 0) {
			v = double(v) / 2;
		}

		if (u >= v) {
			u -= v;
		}
		else {
			v -= u;
		}
	}

	return g * v;
}

class Rational {
public:
	Rational() {
		num = 0;
		denom = 1;
	}
	Rational(int numerator, int denominator) {
		if (numerator == 0) {
			num = 0;
			denom = 1;
		}
		else {
			int gdc = GDC(abs(numerator), abs(denominator));
			num = numerator / gdc;
			denom = denominator / gdc;

			if (denominator < 0) {
				num *= -1;
				denom *= -1;
			}
		}
	}

	int Numerator() const {
		return num;
	}
	int Denominator() const {
		return denom;
	}
private:
	int num, denom;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
};

Rational operator-(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator());
};

bool operator<(const Rational& lhs, const Rational& rhs) {
	Rational diff = lhs - rhs;
	if (diff.Numerator() < 0) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
