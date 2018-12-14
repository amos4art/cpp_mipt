#include <vector>
#include <algorithm>

#include <iostream>

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



struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

Function MakeWeightFunction(const Params& params,
	const Image& image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
	const Image& image,
	double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

int main() {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 52) << endl;
	return 0;
}
