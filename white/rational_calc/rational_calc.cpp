#include <iostream>
#include <sstream>
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
			throw invalid_argument("Invalid argument");
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

Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
};

Rational operator/(const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
};

ostream& operator<<(ostream& stream, const Rational& number) {
	stream << number.Numerator() << "/" << number.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& number) {
	int n = number.Numerator();
	int d = number.Denominator();
	stream >> n;
	stream.ignore(1);
	stream >> d;
	number = Rational(n, d);
	return stream;
}

int main() {
	//stringstream s;
	//s << "4/5 / 0/8";

	Rational a, b;
	string oper;

	try {
		cin >> a >> oper >> b;

		if (oper == "+") {
			cout << a + b;
		}
		else if (oper == "-") {
			cout << a - b;
		}
		else if (oper == "*") {
			cout << a * b;
		}
		else {
			cout << a / b;
		}
	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}