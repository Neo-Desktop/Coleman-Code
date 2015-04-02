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

#include "includes.h"
#include "account.h"
#include "main.h"

account::account(string input) // constructor
{
	setaccountName(input); // use the setter to set the input
	//use rand function
	setaccountBalance(10000 + rand () % 90000); // use a random total for the account balance
	setaccountNum(1000000 + rand () % 9000000); // use a random number for the account number
}

account::~account()
{
	cout << "destructor called" << endl;
	//delete &accountNum;
	//delete &accountName;
	//delete &accountBalance;
}

void account::setaccountNum(int input) // setter
{
	accountNum = input;
}
int account::getaccountNum() // getter
{
	return accountNum;
}
string account::getPaddedAccountNum()  //utility function
{
	//use the space pad function defined in global scope
	//to return a nicely formatted account number
	return spacePad(getaccountNum());
}

void account::setaccountName(string input) // setter
{
	accountName = input;
}
string account::getaccountName() // getter
{
	return accountName;
}

void account::setaccountBalance(float input) // setter
{
	accountBalance = input;
}
float account::getaccountBalance() // getter
{
	return accountBalance;
}

void account::menu() // utility function
{
	// main function that gets called after object initialization
	// loop does not end until option 4 is entered.
	bool cont = true;
	while (cont)
	{
		cls();
		cout << "Welcome, " << getaccountName() << ". Account Number: " << getaccountNum() << ". Balance: $" << getaccountBalance() << endl << endl;
		cout << string(80,'*');
		cout << "|                                 Main Menu                                    |";
		cout << string(80,'*');
		cout << "|     1. Check account balance                                                 |";
		cout << "|     2. Deposit amount                                                        |";
		cout << "|     3. Withdraw amount                                                       |";
		cout << "|     4. Exit                                                                  |";
		cout << string(80,'*');
		cout << "Please make a selection" << endl << ":";
		char input = 0;
		while (input == 0)
		{
			input = _getch();
			cout << input;
			switch (input)
			{
			case '1':
				doAccountBalance();
				break;
			case '2':
				doDeposit();
				break;
			case '3':
				doWithdraw();
				break;
			case '4':
				cont = false;
				break;
			default:
				input = 0;
			}
		}
	}
}

void account:: balanceform() // utility function
{
	// nicely formats account number and current balance
	// is called by all menu options, except quit
	cout << endl << endl << endl << endl;
	cout << string(8,' ') << "+-----------------------------------------+" << endl;
	cout << string(8,' ') << "|    Account: " << getPaddedAccountNum() << "                     |" << endl;
	cout << string(8,' ') << "|    Current balance: $" << spacePad(getaccountBalance(), 10) << "         |" << endl;
	cout << string(8,' ') << "+-----------------------------------------+" << endl;
	cout << endl << endl << endl << endl << endl;
}
void account::doAccountBalance() // utility function, menu option 1
{
	// simply displays the account number and balance using balanceform()
	cls();
	cout << "Welcome, " << getaccountName() << ". Account Number: " << getaccountNum() << ". Balance: $" << getaccountBalance() << endl << endl;
	cout << "Viewing: Account balance" << endl;
	balanceform();
	pause();
}
void account::doWithdraw() // utility function, menu option 2
{
	// perform a withdrawal
	cls();
	cout << "Welcome, " << getaccountName() << ". Account Number: " << getaccountNum() << ". Balance: $" << getaccountBalance() << endl << endl;
	cout << "Withdrawal slip" << endl;
	balanceform();
	bool valid = false;
	char perform = 0;
	while (!valid)
	{
		// ask the user how much they wish to withdraw
		cout << "How much would you like to withdraw today?" << endl << ":$";
		float input;
		cin >> input;
		if (input > getaccountBalance()) // check condition, do we have enough money to make the withdrawal?
		{
			// not enough
			cout << "$" << input << " is more than you have in your account.";
			cout << "Please enter a different amount." << endl << endl;
		}
		else
		{
			// good amount
			cout << "About to withdraw $" << input << " from account number: " << getaccountNum() << endl;
			cout << "Continue? [y/N]" << endl << ":";
			while (perform == 0)
			{
				perform = _getch();
				cout << perform;
				switch(toupper(perform))
				{
				case 'Y':
				case 'N':
				case CR:
				case ESC:
					valid = true;
					break;
				default:
					perform = 0;
					break;
				}
			}

			cout << endl << endl;
			if (toupper(perform) == 'Y')
			{
				// make it so
				float balance = getaccountBalance();
				balance -= input;
				setaccountBalance(balance);
				cout << "Withdrew $" << input << " from account number: " << getaccountNum() << endl;
				cout << "New balance: $" << getaccountBalance() << endl << endl;
			}
			else
			{
				cout << "Aborted." << endl;
			}
		}
	}
	cout << endl << endl;
	pause();
}
void account::doDeposit() // utility function, menu option 3
{
	cls();
	cout << "Welcome, " << getaccountName() << ". Account Number: " << getaccountNum() << ". Balance: $" << getaccountBalance() << endl << endl;
	cout << "Deposit slip" << endl;
	balanceform();
	bool valid = false;
	char perform = 0;
	while (!valid)
	{
		// ask the user how much they wish to deposit
		cout << "How much would you like to deposit today?" << endl << ":$";
		float input;
		cin >> input;
		cout << "About to deposit $" << input << " into account number: " << getaccountNum() << endl;
		cout << "Continue? [y/N]" << endl << ":";
		while (perform == 0)
		{
			perform = _getch();
			cout << perform << endl;
			switch(toupper(perform))
			{
			case 'Y':
			case 'N':
			case CR:
			case ESC:
				valid = true;
				break;
			default:
				perform = 0;
				break;
			}
		}

		cout << endl << endl;
		if (toupper(perform) == 'Y')
		{
			// make it so
			float balance = getaccountBalance();
			balance += input;
			setaccountBalance(balance);
			cout << "Deposited $" << input << " into account number: " << getaccountNum() << endl;
			cout << "New balance: $" << getaccountBalance() << endl << endl;
		}
		else
		{
			cout << "Aborted." << endl;
		}

	}
	pause();
}


// hope you've enjoyed the show!