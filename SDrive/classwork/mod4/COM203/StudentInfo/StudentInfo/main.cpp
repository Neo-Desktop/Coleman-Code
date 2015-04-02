#include "StudentInfo.h"

int main()
{
	StudentInfo info;
	info.setStudID(77260);
	info.setGrade(90);
	info.setName("Amrit");

	cout << "ID: " << info.getStudID() << ", " << info.getName() << " has a score of: " << info.getGrade() << endl;
	cin.get();
}