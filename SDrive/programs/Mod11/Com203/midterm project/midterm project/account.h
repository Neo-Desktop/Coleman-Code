/***************************************************************
 * Project: COM 203 Midterm
 *  Author: Amrit Panesar
 *    Date: 09/04/2014
 **************************************************************/


/*****************************************************************
Account Class (A bank account class with methods to deposit, withdraw, and check the balance.) (5 points)
1. Class contains 3 private data members called accountBalance, accountName and accountNum.
	Choose appropriate data types for these variables

2. Write an overloaded constructor that takes one parameter of the type string.
	The constructor initializes the accountName with the parameter specified.
	The member variables accountBalance and accountNum are assigned some random value (No need to use rand function).

3. Write appropriate destructor, set, get and display functions.

4. The class will also contain member functions named menu, withdraw, and deposit
	The withdraw function checks to see if balance is sufficient for withdrawal.
	If so, decrements balance by amount; if not, prints an appropriate message indicating insufficient funds and displays the current balance.
	The deposit function adds deposit amount to balance and displays new balance
	The menu function will contain the following menu options: 1. Check Balance, 2. Deposit Amount, 3. Withdraw Amount, 4. Exit.
	Use appropriate messages for each option selected and then call the correct function to perform the task.
*****************************************************************/

#pragma once

#include "includes.h"

class account
{
private:
	int accountNum;
	string accountName;
	float accountBalance;

	void setaccountNum(int input);
	int getaccountNum();
	string getPaddedAccountNum();

	void setaccountName(string input);
	string getaccountName();

	void setaccountBalance(float input);
	float getaccountBalance();

	void doAccountBalance();
	void doDeposit();
	void doWithdraw();
	void balanceform();

public:
	account(string name);
	~account();

	void menu();
};