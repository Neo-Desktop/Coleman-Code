
#ifndef _tower_h
#define _tower_h

	#include <string>
	#include <iostream>
	#include <vector>
	#include <algorithm>

	using namespace std;

	class Tower
	{
	public:
		Tower(int);
		Tower(int, int);
		~Tower();

		bool isSetAt(int i);
		bool setAt(int i, bool in);

		int getdnum();
		int getTowerID();

		void println(int num);
		void setAll(bool in = true);

		//friend ostream& operator<<(ostream& os, const Tower& tower);

	private:
		int towerID;
		static int s_Discs;
		vector<bool> hanoi;
	};

#endif