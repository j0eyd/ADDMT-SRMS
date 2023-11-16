#ifndef _GRADE
#define _GRADE
#include "Course.h"
#include "Student.h"
using namespace std;

class Grade{
	private:
		Student* student;
		Course* course;
		string identifier;
		float points;
		float outOf;
		float value;
		float coeff;
	public:
		//Creator, Destructor methods
		Grade();
		~Grade();
		//Accessor methods
		Student* getStudent();
		Course* getCourse();
		string getIdentifier();
		float getPoints();
		float getOutOf();
		float getValue();
		float getCoeff();
		//Mutator methods
		void setStudent(Student& student);
		void setCourse(const Course& course);
		void setIdentifier(const string& newIdentifier);
		void setPoints(const float& newPoints);
		void setOutOf(const float& newOutOf);
		void setValue(const float& newValue);
		void setCoeff(const float& newCoeff);
};

#endif