#ifndef _GRADE
#define _GRADE
#include "Course.h"
#include "Student.h"
using namespace std;

class Grade{
	private:
		Student* student;
		Course* course;
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
		float getPoints();
		float getOutOf();
		float getValue();
		float getCoeff();
		//Mutator methods
		void setStudent(Student& student);
		void setCourse(Course& course);
		void setPoints(float newPoints);
		void setOutOf(float newOutOf);
		void setValue();
		void setCoeff(float newCoeff);
};

#endif