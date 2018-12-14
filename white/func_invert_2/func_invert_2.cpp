#include <vector>
#include <algorithm>

using namespace std;

class FuncPart {
public:
	FuncPart(char operand, double value) {
		oper = operand;
		val = value;
	}
	double Apply(double value) const {
		if (oper == '-') {
			return value - val;
		}
		else if (oper == '+') {
			return value + val;
		}
		else if (oper == '*') {
			return value * val;
		}
		else if (oper == '/') {
			return value / val;
		}
	}
	void Invert() {
		if (oper == '-') {
			oper = '+';
		}
		else if (oper == '+') {
			oper = '-';
		}
		else if (oper == '*') {
			oper = '/';
		}
		else if (oper == '/') {
			oper = '*';
		}
	}
private:
	char oper;
	double val;
};


class Function {
public:
	void AddPart(char operand, double value) {
		body.push_back(FuncPart(operand, value));
	}
	double Apply(double value) const {
		for (const auto& part : body) {
			value = part.Apply(value);
		}
		return value;
	}
	void Invert() {
		reverse(begin(body), end(body));
		for (auto& part : body) {
			part.Invert();
		}
	}
private:
	vector<FuncPart> body;
};
