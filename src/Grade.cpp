#include "Grade.h"

Grade::Grade(){}

Grade::~Grade(){}

Student* Grade::getStudent() {return student;}

Course* Grade::getCourse() {return course;}

float Grade::getPoints() {return points;}

float Grade::getOutOf() {return outOf;}

float Grade::getValue() {return value;}

float Grade::getCoeff() {return coeff;}

void Grade::setStudent(Student& newStudent) {student = &newStudent;}

void Grade::setCourse(Course& newCourse) {course = &newCourse;}

void Grade::setPoints(float newPoints) {points = newPoints;}

void Grade::setOutOf(float newOutOf) {outOf = newOutOf;}

void Grade::setValue() {value = points/outOf;}

void Grade::setCoeff(float newCoeff) {coeff = newCoeff;}
