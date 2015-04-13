#include "StudentInfo.h"

void StudentInfo::setGrade(float fGrade)
{
	grade = fGrade;
}
float StudentInfo::getGrade()
{
	return grade;
}

void StudentInfo::setName(std::string sName)
{
	name = sName;
}
string StudentInfo::getName()
{
	return name;
}

void StudentInfo::setStudID(int iId)
{
	studId = iId;
}
int StudentInfo::getStudID()
{
	return studId;
}