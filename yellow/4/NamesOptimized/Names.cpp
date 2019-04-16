# include <map>
# include <string>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_name_log[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_name_log[year] = last_name;
	}
	string GetFullName(int year) {
		string result = "";

		string f_name = FindName(first_name_log, year);
		string l_name = FindName(last_name_log, year);

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
private:
	map<int, string> first_name_log;
	map<int, string> last_name_log;

	string FindName(map<int, string>& list, int year) {

		map<int, string>::iterator iter = list.find(year);

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
};

int main() {
	return 0;
}
