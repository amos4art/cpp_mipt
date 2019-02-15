#include <map>;
#include <vector>;
#include <iostream>;

using namespace std;

template <typename T> vector<T> operator* (const vector<T>& lhs, const vector<T>& rhs);
template <typename T1, typename T2> pair<T1, T2> operator* (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
template <typename T1, typename T2> map<T1, T2> operator* (const map<T1, T2>& lhs, const map<T1, T2>& rhs);
template <typename T> T Sqr(T& arg);

template <typename T>
vector<T> operator* (const vector<T>& lhs, const vector<T>& rhs) {
	vector<T> res;

	//assume that vectors has same size
	for (int i = 0; i < lhs.size(); ++i) {
		res.push_back(lhs[i] * rhs[i]);
	}
	return res;
}

template <typename T1, typename T2>
pair<T1, T2> operator* (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	pair<T1, T2> res;

	res = { lhs.first * rhs.first, lhs.second * rhs.second };
	
	return res;
}


template <typename T1, typename T2> 
map<T1, T2> operator* (const map<T1, T2>& lhs, const map<T1, T2>& rhs) {
	map<T1, T2> res;

	//assume that maps has same size
	for ( const auto& i : lhs ) {
		res[i.first] = i.second * rhs.at(i.first);
	}
	return res;
}


template <typename T> 
T Sqr(T& arg) {	
	return arg * arg;
}

int main() {
	vector<int> a = { 1, 2, 3 };

	vector<int> b = Sqr(a);

	//int a = 5;

	//int b = sqr(a);


	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}


	return 0;
}