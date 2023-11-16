#include "Grade.h"

Grade::Grade(){}

Grade::Grade(Student& student, Course& course, const string& identifier,
	const float& points, const float& outOf, const float& value,
	const float& coeff)
	: student(&student), course(&course), identifier(identifier), points(points),
	outOf(outOf), value(value), coeff(coeff) {}

Grade::~Grade(){}

Student* Grade::getStudent() const {return student;}

Course* Grade::getCourse() const {return course;}

float Grade::getPoints() const {return points;}

float Grade::getOutOf() const {return outOf;}

float Grade::getValue() const {return value;}

float Grade::getCoeff() const {return coeff;}

void Grade::setStudent(Student& newStudent) {student = &newStudent;}

void Grade::setCourse(Course& newCourse) {course = &newCourse;}

void Grade::setIdentifier(const string& newIdentifier) {identifier = newIdentifier;};

void Grade::setPoints(const float& newPoints) {
	points = newPoints;
	this->setValue();
}

void Grade::setOutOf(const float& newOutOf) {
	outOf = newOutOf;
	this->setValue();
}

void Grade::setValue() {value = points/outOf;}

void Grade::setCoeff(const float& newCoeff) {coeff = newCoeff;}
