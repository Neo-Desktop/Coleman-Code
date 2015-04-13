#pragma once

#include "stdhangman.h"

class hangword
{
private:
	int id;
	string word;
public:
	void setid(int in);
	int getid();

	void setword(string in);
	string getword();

	void Read(ifstream& file);
	void Write(ofstream& file);

	void writeword(ofstream& file,const string& str);
	string readword(ifstream& file);

	void writeid(ofstream& file, int& num);
	int readid(ifstream& file);
};
