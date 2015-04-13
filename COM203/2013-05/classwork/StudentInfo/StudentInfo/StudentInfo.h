#include <iostream>
#include <string>

using namespace std;

class StudentInfo
{
	string name;
	int studId;
	float grade;

public:
	void setName(string sName);
	string getName();

	void setStudID(int iId);
	int getStudID();

	void setGrade(float fGrade);
	float getGrade();
};