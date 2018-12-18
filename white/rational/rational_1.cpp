#include <iostream>

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


int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}
