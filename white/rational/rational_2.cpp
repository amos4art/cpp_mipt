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

bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator());
};

Rational operator-(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator());
};


int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
