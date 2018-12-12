#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
	Person(const std::string& first_name, const std::string& last_name, int year) {
		first_name_log[year] = first_name;
		last_name_log[year] = last_name;		
		person_birth = year;
	}
	
	void ChangeFirstName(int year, const std::string& first_name) {
		if (year >= person_birth) {
			first_name_log[year] = first_name;
		}
	}
	void ChangeLastName(int year, const std::string& last_name) {
		if (year >= person_birth) {
			last_name_log[year] = last_name;
		}
	}
	std::string GetFullName(int year) const {
		if (year < person_birth) {
			return "No person";
		}
		else {
			std::string f_name = FindName(first_name_log, year);
			std::string l_name = FindName(last_name_log, year);

			return CombineNameSearchResult(f_name, l_name);
		}
	}

	std::string GetFullNameWithHistory(int year) const {
		if (year < person_birth) {
			return "No person";
		}
		else {
			std::string f_name = FindName(first_name_log, year);
			std::string l_name = FindName(last_name_log, year);

			std::string f_name_hist = FindNameHistory(first_name_log, year);
			std::string l_name_hist = FindNameHistory(last_name_log, year);

			f_name += f_name_hist;
			l_name += l_name_hist;

			return CombineNameSearchResult(f_name, l_name);
		}		
	}
private:
	map<int, std::string> first_name_log;
	map<int, std::string> last_name_log;
	int person_birth;
	typedef map<int, std::string>::iterator it_type;

	std::string FindName(map<int, std::string> list, int year) const {
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

	std::string FindNameHistory(map<int, std::string> list, int year) const {
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

	std::string CombineNameSearchResult(const string & f_name, const string & l_name) const {
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

	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
