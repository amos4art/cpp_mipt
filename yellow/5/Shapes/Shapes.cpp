#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;


class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;	
};


class Rect : public Figure {
public:
	Rect(int width, int height) : _w(width), _h(height) {
	}
		
	string Name() const override {
		return "RECT";
	}

	double Perimeter() const override {
		return _w * 2 + _h * 2;
	}

	double Area() const override {
		return _w * _h;
	}

private:
	int _w;
	int _h;
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c) : _a(a), _b(b), _c(c) {
	}

	string Name() const override {
		return "TRIANGLE";
	}

	double Perimeter() const override {
		return _a + _b + _c;
	}

	double Area() const override {
		double p = Perimeter() / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	int _a;
	int _b;
	int _c;
};


class Circle : public Figure {
public:
	Circle(int radius) : _r(radius) {
	}

	string Name() const override {
		return "CIRCLE";
	}

	double Perimeter() const override {
		return 2 * 3.14 * _r;
	}

	double Area() const override {
		return 3.14 * _r * _r;
	}

private:
	int _r;
};


shared_ptr<Figure> CreateFigure(istringstream& is) {
	string fig;
	is >> fig;
	
	if (fig == "RECT") {
		int w, h;
		is >> w >> h;
		return make_shared<Rect>(w, h);
	}
	else if (fig == "TRIANGLE") {
		int a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	}
	else if (fig == "CIRCLE") {
		int r;
		is >> r;
		return make_shared<Circle>(r);
	}
}


int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
