/*****************************************************************************
 *  Program: Banking Application Midterm                                     *
 *   Author: Amrit Panesar                                                   *
 *     Date: 06/26/2013                                                      *
 *   Course: COM 203 - S. Ganore                                             *
 * Abstract: A bank account class with methods to deposit, withdraw,         *
 *           and check the balance of the account instance                   *
 *  Depends: Account.h, Standard C Library                                   *
 *     File: Account.h                                                       *
 * Descript: This file contains the function prototypes and declarations     *
 *           of data members in use with the banking application midterm.    *
 *           Setters and getters for each member variable are provided as    *
 *           public members. The constructor for the accont class requires   *
 *           a string for the account name.                                  *
 *           For more information see Account.cpp and main.cpp               *
 *****************************************************************************/

#include <string>
#include <iostream>
#include <ctime>
#include <cmath>
#include <Windows.h>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
	// Class contains 3 private data members called accountBalance, accountName and accountNum.
	// Choose appropriate data types for these variables
	float accountBalance;
	string accountName;
	unsigned int accountNumber;

public:
	// Write an overloaded constructorthat takes one parameter of the type string.
	Account(string name);
	// Write appropriate destructor, set, get and display functions
	~Account();

	//Write appropriate destructor, set, get and display functions
	float getaccountBalance();
	void setaccountBalance(float balance);

	string getaccountName();
	void setaccountName(string name);

	unsigned int getaccountNumber();
	void setaccountNumber(unsigned int acccountNumber);

	void displayAccountInformation();

	// The class will also contain member functions named menu, withdraw, and deposit
	void menu();
	void withdraw();
	void deposit();

	void doExit();
	void run();
};

#endif
