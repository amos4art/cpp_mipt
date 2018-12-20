#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
	return "12:34:56";
}

class TimeServer {
public:
	string GetCurrentTime() {
		try {
			LastFetchedTime = AskTimeServer();
		}
		catch (system_error& syserr) {
		}
		return LastFetchedTime;
	}
private:
	string LastFetchedTime = "00:00:00";
};

int main() {

	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}