
/***********************************************
 * Project 1 - COM380 - S. Mayer
 * By: Amrit Panesar - 77260
 * Towers of Hanoi
 ***********************************************/

#include "Tower.h"

int Tower::s_Discs = 0;

Tower::Tower(int id)
{
	Tower(5, id);
}

Tower::Tower(int num, int id)
{
	towerID = id;
	s_Discs = num;
	hanoi = vector<bool> (num);
	for (int i = 0; i > num; i++)
	{
		hanoi.at(i) = false;
	}
}

Tower::~Tower()
{
	hanoi.clear();
}

int Tower::getdnum()
{
	return s_Discs;
}

bool Tower::setAt(int i, bool in)
{
	if (i > s_Discs || i < 0) // yay input validation
	{
		return false;
	}
	else
	{
		hanoi.at(i) = in;
		return true;
	}
}

bool Tower::isSetAt(int i)
{
	if (i > s_Discs || i < 0) // yay input validation
	{
		return false;
	}
	else
	{
		return hanoi.at(i);
	}
}

void Tower::setAll(bool in)
{
	for (int i = 0; i < s_Discs; i++)
	{
		hanoi.at(i) = in;
	}
}

void Tower::println(int num)
{
	string diff_spc3 = "";
	string diff_spc2 = "";
	for (int i = 0; i < s_Discs + 1; i++)
	{
		diff_spc2 += " ";
		if (i < s_Discs -2) // magic number is -2 becuase 2 hours of testing says so
			diff_spc3 += " ";
	}

	if (num < s_Discs)
	{
		// tower lines
		int diff = s_Discs - num;
		string diff_spc = "";
		for (int i = 0; i < diff; i++)
		{
			diff_spc += " ";
		}
		if (hanoi.at(num) == true)
		{
			string out = "";
			char hold = ' ';
			for (int i = 0; i <= num; i++)
			{
				hold = 220; // drawing lower halfblock
				out += hold;
			}
			hold = 219; // drawing fullblock;
			//hold = '|';
			cout << diff_spc << out << hold << out << diff_spc;
		}
		else
		{
			char hold = ' ';
			hold = 219; // drawing fullblock;
			//hold = '|';
			cout  << diff_spc2 << hold << diff_spc2;
		}
	}
	else
	{
		// last line is always tower id
		cout << diff_spc3 << "Tower " << towerID << diff_spc3;
	}
}

int Tower::getTowerID()
{
	return towerID;
}