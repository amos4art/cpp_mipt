#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

class Matrix {
public:
	Matrix(){}

	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(int num_rows, int num_cols) {
		if (num_rows < 0 || num_cols < 0) {
			throw out_of_range("rows and columns cannot be negative");
		}
		
		_num_rows = num_rows;
		_num_columns = num_cols;
		_data.assign(num_rows, vector<int>(num_cols));
	}

	int At(int row, int col) const {
		return _data.at(row).at(col);
	}

	int& At(int row, int col) {
		return _data.at(row).at(col);
	}

	int GetNumRows() const {
		return _num_rows;
	}

	int GetNumColumns() const {
		return _num_columns;
	}

private:
	int _num_rows;
	int _num_columns;
	vector<vector<int>> _data;
};

istream& operator>>(istream& in, Matrix& matrix) {
	int rows;
	int cols;

	in >> rows >> cols;

	matrix.Reset(rows, cols);

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			in >> matrix.At(r, c);
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
	int rows = matrix.GetNumRows();
	int cols = matrix.GetNumColumns();
	
	out << rows << " " << cols << endl;

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			out << matrix.At(r, c) << " ";
		}
		out << endl;
	}
	return out;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	int rows = lhs.GetNumRows();
	int cols = lhs.GetNumColumns();

if (rows != rhs.GetNumRows() || cols != rhs.GetNumColumns()) {
		return false;		
	}
	else {
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				if (lhs.At(r, c) != rhs.At(r, c)) {
					return false;
				}
			}			
		}
	}
	return true;	
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}
	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}
	
	int rows = lhs.GetNumRows();
	int cols = lhs.GetNumColumns();

	Matrix new_matr(rows, cols);

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			new_matr.At(r, c) = lhs.At(r, c) + rhs.At(r, c);
		}
	}
	
	return new_matr;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	
	return 0;

}
