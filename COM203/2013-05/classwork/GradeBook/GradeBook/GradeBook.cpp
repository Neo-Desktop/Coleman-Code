#include "GradeBook.h"

void GradeBook::setcourseName(string cName)
{
	courseName = cName;
}

string GradeBook::getcourseName()
{
	return courseName;
}

void GradeBook::displayMessage()
{
	cout << "Hello! Welcome to " << GradeBook::getcourseName() << endl;
}