#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
	Person(const string& name, const string& prof) : Name(name), Proffession(prof) {
	}
	
	virtual void Walk(const string& destination) {
		cout << Proffession << ": " << Name << " walks to: " << destination << endl;
	}

	const string Name;
	const string Proffession;
};


class Student : public Person {
public:
	
	Student(const string& name, const string& favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {
	}

	void Learn() {
		cout << Proffession << ": " << Name << " learns" << endl;
	}

	void Walk(const string& destination) override {
		Person::Walk(destination);
		SingSong();
	}

	void SingSong() {
		cout << Proffession << ": " << Name << " sings a song: " << FavouriteSong << endl;
	}

	const string FavouriteSong;
};


class Teacher : public Person {
public:

	Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject(subject) {
	}

	void Teach() {
		cout << Proffession << ": " << Name << " teaches: " << Subject << endl;
	}

	const string Subject;
};


class Policeman : public Person {
public:
	
	Policeman(const string& name) : Person(name, "Policeman") {
	}

	void Check(const Person& p) {
		cout << "Policeman: " << Name << " checks " << p.Proffession << ". " << 
			p.Proffession << "'s name is: " << p.Name << endl;
	}	
};


void VisitPlaces(Person& per, vector<string> places) {
	for (auto p : places) {
		per.Walk(p);
	}
}


int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
