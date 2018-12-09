#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name) {
		first_name_log[year] = first_name;
	}
	void ChangeLastName(int year, const std::string& last_name) {
		last_name_log[year] = last_name;
	}
	std::string GetFullName(int year) {
		std::string f_name = FindName(first_name_log, year);
		std::string l_name = FindName(last_name_log, year);

		return CombineNameSearchResult(f_name, l_name);
	}

	std::string GetFullNameWithHistory(int year) {
		std::string f_name = FindName(first_name_log, year);
		std::string l_name = FindName(last_name_log, year);

		std::string f_name_hist = FindNameHistory(first_name_log, year);
		std::string l_name_hist = FindNameHistory(last_name_log, year);
		
		f_name += f_name_hist;
		l_name += l_name_hist;		 

		return CombineNameSearchResult(f_name, l_name);
	}
private:
	map<int, std::string> first_name_log;
	map<int, std::string> last_name_log;
	typedef map<int, std::string>::iterator it_type;

	std::string FindName(map<int, std::string>& list, int year) {
		it_type iter = list.find(year);
		
		if (list.size() == 0) {
			return "";
		}
		else if (iter != end(list)) {
			return iter->second;
		}
		else {
			iter = list.lower_bound(year);
			if (iter != begin(list)) {
				--iter;
				return iter->second;
			}
			else {
				return "";
			}
		}
	}

	std::string FindNameHistory(map<int, std::string>& list, int year) {
		std::string result = "";
		vector<std::string> name_hist;
		
		it_type iter = list.find(year);

		if (list.size() <= 1) {
			return "";
		}
		else if (iter == end(list)) {
			iter = list.lower_bound(year);
			if (iter != begin(list)) {
				--iter;
			}
			else {
				return "";
			}
		}
		
		if (iter == begin(list)) {
			return "";
		}

		std::string previous = iter->second;
		do {
			--iter;
			if (previous != iter->second) {
				name_hist.push_back(iter->second);
				previous = iter->second;
			}
		} while (iter != begin(list));

		if (name_hist.size() > 0) {
			result = " (";
			result += name_hist[0];
			name_hist.erase(begin(name_hist));
			for (auto& n : name_hist) {
				result += ", " + n;
			}
			result += ")";
		}
			
		return result;

	}

	std::string CombineNameSearchResult(string & f_name, string & l_name) {
		string result = "";
		if (f_name == "" && l_name == "") {
			result = "Incognito";
		}
		else if (f_name != "" && l_name != "") {
			result += f_name + " " + l_name;
		}
		else if (l_name == "") {
			result += f_name + " with unknown last name";
		}
		else {
			result += l_name + " with unknown first name";
		}
		return result;
	}
	

};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
