#include <iostream>
#include <exception>

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
		if (denominator == 0) {
			throw invalid_argument("Denominator cannot be zero");
		}
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


Rational operator/(const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("Denominator cannot be zero");
	}
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
};


int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}