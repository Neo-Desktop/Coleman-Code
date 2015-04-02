/*****************************************************************************
 *  Program: Banking Application Midterm                                     *
 *   Author: Amrit Panesar                                                   *
 *     Date: 06/26/2013                                                      *
 *   Course: COM 203 - S. Ganore                                             *
 * Abstract: A bank account class with methods to deposit, withdraw,         *
 *           and check the balance of the account instance                   *
 *  Depends: Account.h, Standard C Library                                   *
 *     File: Account.h                                                       *
 * Descript: This file contains methods declared in Account.h. This file     *
 *           contains the source of the run function as well as the doMenu   *
 *           function. The account number and account balanced are randomized*
 *           in the constructor for the Account class.                       *
 *           For more information see Account.h and main.cpp                 *
 *****************************************************************************/

#include "Account.h"

/******************************************************************************
 * Function: Account::Account(string) - Constructor                           *
 * Abstract: The constructor initalizes the accountName with the parameter    *
 *           specified. The member variabled accountBalance and accountNum    *
 *           are assigned some random value using their respective set procs  *
 ******************************************************************************/
Account::Account(string namein)
{
	// The constructor initializes the accountName with the parameter specified
	// The member variables accountBalance and accountNum are assigned some random value
	setaccountName(namein);
	setaccountNumber(rand()%(unsigned int)pow(2,31));
	setaccountBalance(rand()%(unsigned int)pow(2,31));
}
/******************************************************************************
 * Function: Account::~Account() - Destructor                                 *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This destructor prints that it has been called as per the sample *
 *           output provided.                                                 *
 ******************************************************************************/
Account::~Account()
{
	// Write appropriate destructor, set, get and display functions
	cout << "Destructor Called" << endl;
}

/******************************************************************************
 * Function: Account::setaccountName(string) - Setter                         *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This sets the accountName member variable.                       *
 ******************************************************************************/
void Account::setaccountName(string namein)
{
	// Write appropriate destructor, set, get and display functions
	accountName = namein;
}
/******************************************************************************
 * Function: Account::getaccountName() - Getter                               *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This gets the accountName member variable.                       *
 ******************************************************************************/
string Account::getaccountName()
{
	// Write appropriate destructor, set, get and display functions
	return accountName;
}

/******************************************************************************
 * Function: Account::setaccountBalance(float) - Setter                      *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This sets the accountBalance member variable                     *
 ******************************************************************************/
void Account::setaccountBalance(float balancein)
{
	// Write appropriate destructor, set, get and display functions
	accountBalance = balancein;
}
/******************************************************************************
 * Function: Account::getaccountBalance() - Getter                            *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This gets the accountBalance member variable                     *
 ******************************************************************************/
float Account::getaccountBalance()
{
	// Write appropriate destructor, set, get and display functions
	return accountBalance;
}

/******************************************************************************
 * Function: Account::setaccountNumber(float) - Setter                       *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This sets the accountNumber member variable                      *
 ******************************************************************************/
void Account::setaccountNumber(unsigned int accnumbin)
{
	// Write appropriate destructor, set, get and display functions
	accountNumber = accnumbin;
}
/******************************************************************************
 * Function: Account::getaccountNumber(float) - Getter                       *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This gets the accountNumber member variable                      *
 ******************************************************************************/
unsigned int Account::getaccountNumber()
{
	// Write appropriate destructor, set, get and display functions
	return accountNumber;
}

/******************************************************************************
 * Function: Account::displayAccountInformation() - Display                   *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This function displays the account balance, number, and name     *
 ******************************************************************************/
void Account::displayAccountInformation()
{
	// Write appropriate destructor, set, get and display functions
	cout << "Here is the account Information:" << endl;
	cout << "Account for: " << getaccountName() << endl;
	cout << "Account #: " << getaccountNumber() << endl;
	cout << "Balance: $" << getaccountBalance() << endl;
}

/******************************************************************************
 * Function: Account::doExit() - Display                                      *
 * Abstract: Write the appropriate destructor, set and display functions.     *
 *           This function is called at exit and displays a goodbye message   *
 ******************************************************************************/
void Account::doExit()
{
	cout << "Thank you for using Banking program" << endl;
}

/******************************************************************************
 * Function: Account::withdraw() - Utility                                    *
 * Abstract: The class will also contain member functions named menu,         *
 *           withdraw, and deposit.                                           *
 *           The withdraw function checks to see if balance is sufficient for *
 *           withdrawal. If so, decrements balance by amount; if not, prints  *
 *           an appropriate message indicating insufficient funds and displays*
 *           the current balance.                                             *
 ******************************************************************************/
void Account::withdraw()
{
	// The class will also contain member functions named menu, withdraw, and deposit
	float withdraw;
	cout << "Enter the amount you want to withdraw" << endl << ":";
	cin >> withdraw;
	if (withdraw > getaccountBalance())
	{
		cout << "ERROR: Cannot withdraw amount due to Insufficient Funds !" << endl;
		cout << "Your balance remains at: $" << getaccountBalance() << endl;
	}
	else
	{
		setaccountBalance(getaccountBalance() - withdraw);
		cout << "Withdrawing $" << withdraw << " from account #" << getaccountNumber() << endl;;
		cout << "Your account balance is now: $" << getaccountBalance() << endl;
	}
}

/******************************************************************************
 * Function: Account::Deposit() - Utility                                     *
 * Abstract: The class will also contain member functions named menu,         *
 *           withdraw, and deposit.                                           *
 ******************************************************************************/
void Account::deposit()
{
	// The class will also contain member functions named menu, withdraw, and deposit
	float deposit;
	cout << "Enter the amount you want to deposit" << endl << ":";
	cin >> deposit;

	cout << "Depositing $" << deposit << " into account #" << getaccountNumber() << endl; 
	cout << "Your account balance is now: $" << getaccountBalance() << endl;
}

/******************************************************************************
 * Function: Account::Menu() - Utility                                        *
 * Abstract: The class will also contain member functions named menu,         *
 *           withdraw, and deposit.                                           *
 ******************************************************************************/
void Account::menu()
{
	// The class will also contain member functions named menu, withdraw, and deposit
	int choice;
	enum { ACC_BALANCE = 1, DEPOSIT, WITHDRAW, EXIT };
	while (true)
	{
		cout << "*******************************************************************************" << endl;
		cout << "|                                 Main Menu                                   |" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "|     1. Check account balance                                                |" << endl;
		cout << "|     2. Deposit amount                                                       |" << endl;
		cout << "|     3. Withdraw amount                                                      |" << endl;
		cout << "|     4. Exit                                                                 |" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "Please make a selection" << endl << ":";
		cin >> choice;

		switch (choice)
		{
		case ACC_BALANCE:
			system("cls");
			displayAccountInformation();
			break;
		case DEPOSIT:
			system("cls");
			displayAccountInformation();
			deposit();
			break;
		case WITHDRAW:
			system("cls");
			displayAccountInformation();
			withdraw();
			break;
		case EXIT:
			doExit();
			break;
		default:
			cout << "ERROR: You have made an invalid selection, please chose a different option." << endl;
		}
		if (choice == EXIT)
		{
			break;
		}
	}
}

/******************************************************************************
 * Function: Account::run() - Utility                                         *
 * Abstract: Initially calls a function to display the account information,   *
 *           then calls the menu function.                                    *
 ******************************************************************************/
void Account::run()
{
	system("cls");
	displayAccountInformation();
	menu();
}