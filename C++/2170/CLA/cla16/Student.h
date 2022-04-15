#ifndef student_h
#define student_h

#include <string>
using namespace std;

class Student
{
	private:
		string name;
		int id;
		double *scores;
		int numScores = 3;
	public:
		Student(); // default constructor
		Student(string name, int id); // constructor with parameters
		Student(const Student &obj); // copy constructor
		~Student(); // destructor;
		void displayInfo();
		void setStudent(string name, int id);
		void createScoresArray();
};

#endif
