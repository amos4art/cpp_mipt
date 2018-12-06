#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void Print(const vector<string>& arr) {
	for (const auto& i : arr) {
		cout << i << " ";
	}
}

int main() {
	int n;
	vector<string> myarray;

	cin >> n;
	myarray.resize(n);

	for (auto& i : myarray) {
		cin >> i;
	}

	sort(begin(myarray), end(myarray), [](string x, string y) { 
		string x_low = x;
		string y_low = y;
		int i = 0;		
		char c;
		while (x_low[i])
		{
			c = x_low[i];
			x_low[i] = tolower(c);
			i++;
		}
		i = 0;
		while (y_low[i])
		{
			c = y_low[i];
			y_low[i] = tolower(c);
			i++;
		}
		
		return x_low <= y_low; });
	
	Print(myarray);

	return 0;
}