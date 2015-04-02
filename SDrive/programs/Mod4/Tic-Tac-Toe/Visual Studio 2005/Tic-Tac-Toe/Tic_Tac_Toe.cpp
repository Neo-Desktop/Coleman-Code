#include "Tic_Tac_Toe.h"


Tic_Tac_Toe::Tic_Tac_Toe()
{
	initboard();
	sethuman('X');
	setcomputer('O');
	initeasymoves();
	instructionsdisplayed = false;
}

void Tic_Tac_Toe::initeasymoves()
{
	int easymoofs[] = { 4,0,2,6,8,1,3,5,7 };
	for (int i = 0; i < 9; i++)
	{
		easyMoves[i] = easymoofs[i];
	}
}

bool Tic_Tac_Toe::winner()
{
	for (int i = 0; i <= 2; i++)
	{
		char curCheck = gethuman();
		if (i == 1)
		{
			curCheck = getcomputer();
		}

		//vertical
		if ((board[0] == curCheck && board[3] == curCheck && board[6] == curCheck) ||
			(board[1] == curCheck && board[4] == curCheck && board[7] == curCheck) ||
			(board[2] == curCheck && board[5] == curCheck && board[8] == curCheck))
		{
			return true;
		}

		// horizontal
		if ((board[0] == curCheck && board[1] == curCheck && board[2] == curCheck) ||
			(board[6] == curCheck && board[7] == curCheck && board[8] == curCheck) ||
			(board[3] == curCheck && board[4] == curCheck && board[5] == curCheck))
		{
			return true;
		}

		// diagonal
		if ((board[4] == curCheck && board[0] == curCheck && board[8] == curCheck) ||
			 (board[4] == curCheck && board[2] == curCheck && board[6] == curCheck))
		{
			return true;
		}
	}
	return false;
}

void Tic_Tac_Toe::displayInstructions()
{
	cout << "Instructions: Use your keyboard to type in coordinates to place a "
		 << endl << "token on the game board. " << endl << endl;
	cout << "You are X - the protagonast in the story - you have been chrosen by the high " << endl
		 << "council of Tic-Toe to defeat the evil lord O, played by the computer. " << endl;
	cout << "Being the chosen one you are able to place your 'X'" << endl
		 << "token first, in an any open space." << endl;
	cout << "The computer then places the O token in a free space until " << endl
		 << "all spaces are filled" << endl;
	cout << "You and the computer continue to place tokens in free spaces until the game" << endl
		 << "board is filled " << endl;
	cout << "If all spaces are filled and no winner has been declared then a rematch is "
		 << endl << "called and the forces of good and evil spar once again." << endl;
	system("pause");
	system("cls");
}

void Tic_Tac_Toe::initboard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = ' ';
	}
}

void Tic_Tac_Toe::run()
{
	bool iseasy = true;
	if (!instructionsdisplayed)
	{
		displayInstructions();
		instructionsdisplayed = true;
	}
	initboard();
	while (true)
	{
		cout << "Would you like to play in Easy mode or Hard mode ?" << endl << "[E/h]:";
		string input;
		cin >> input;
		if (toupper(input[0]) == 'E')
		{
			iseasy = true;
			break;
		}
		else if (toupper(input[0]) == 'H')
		{
			iseasy = false;
			break;
		}
		else
		{
			cout << "Invalid selection, please try again." << endl;
		}
	}
	while (true)
	{
		displayBoard();
		if (stalemate())
		{
			cout << "Stale mate!" << endl;
			system("pause");
			break;
		}
		else
		{
			setisWin(winner());
			if(getisWin())
			{
				cout << "Sorry, the computer wins this round." << endl;
				system("pause");
				break;
			}
			getInput();
		}
		displayBoard();
		if (stalemate())
		{
			cout << "Stale mate!" << endl;
			system("pause");
			break;
		}
		else
		{
			setisWin(winner());
			if(getisWin())
			{
				cout << "Congradulations! A Winner is You!" << endl;
				system("pause");
				break;
			}
			think(iseasy);
		}
	}
}

bool Tic_Tac_Toe::stalemate()
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			return false;
		}
	}
	return true;
}

void Tic_Tac_Toe::think(bool easy)
{
	if (easy)
	{
		for (int i = 0; i <= 8; i++)
		{
			if (board[easyMoves[i]] == ' ')
			{
				board[easyMoves[i]] = getcomputer();
				break;
			}
		}
	}
	else 
	{
		// offencive think -- special cases || win in two
		if (board[0] == getcomputer() && board[2] == getcomputer() && board[1] == ' ' )
		{
			board[1] = getcomputer();
			return;
		} else if (board[3] == getcomputer() && board[5] == getcomputer() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		} else if (board[6] == getcomputer() && board[8] == getcomputer() && board[7] == ' ' )
		{
			board[7] = getcomputer();
			return;
		} else if (board[0] == getcomputer() && board[6] == getcomputer() && board[3] == ' ' )
		{
			board[3] = getcomputer();
			return;
		} else if (board[1] == getcomputer() && board[7] == getcomputer() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		} else if (board[2] == getcomputer() && board[8] == getcomputer() && board[5] == ' ' )
		{
			board[5] = getcomputer();
			return;
		} else if (board[0] == getcomputer() && board[8] == getcomputer() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		} else if (board[2] == getcomputer() && board[6] == getcomputer() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		}
		// offencive think -- main think || win in one
		for (int i = 0; i <= 8; i++)
		{
			switch(i)
			{
			case 0:
				if (board[0] == getcomputer() && board[1] == getcomputer() && board[2] == ' ') //across
				{
					board[2] = getcomputer();
					return;
				}
				else if (board[0] == getcomputer() && board[4] == getcomputer() && board[8] == ' ') //diag
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[0] == getcomputer() && board[3] == getcomputer() && board[6] == ' ') //down
				{
					board[6] = getcomputer();
					return;
				}
				break;
			case 1:
				if (board[1] == getcomputer() && board[4] == getcomputer() && board[7] == ' ') //down
				{
					board[7] = getcomputer();
					return;
				}
				break;
			case 2:
				if (board[2] == getcomputer() && board[4] == getcomputer() && board[6] == ' ') //diag
				{
					board[6] = getcomputer();
					return;
				}
				else if (board[2] == getcomputer() && board[5] == getcomputer() && board[8] == ' ') // down
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[2] == getcomputer() && board[1] == getcomputer() && board[0] == ' ') //across
				{
					board[0] = getcomputer();
					return;
				}
				break;
			case 3:
				if (board[3] == getcomputer() && board[4] == getcomputer() && board[5] == ' ') // across
				{
					board[5] = getcomputer();
					return;
				}
				break;
			case 4:
					// this is the middle square. doesn't really matter.
					// case is checked virtually everywhere else
				break;
			case 5:
				if (board[5] == getcomputer() && board[4] == getcomputer() && board[3] == ' ')
				{
					board[3] = getcomputer();
					return;
				}
				break;
			case 6:
				if (board[6] == getcomputer() && board[7] == getcomputer() && board[8] == ' ') //across
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[6] == getcomputer() && board[4] == getcomputer() && board[2] == ' ') //diag
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[6] == getcomputer() && board[3] == getcomputer() && board[0] == ' ') //down
				{
					board[0] = getcomputer();
					return;
				}
				break;
			case 7:
				if (board[7] == getcomputer() && board[4] == getcomputer() && board[1] == ' ') //down
				{
					board[1] = getcomputer();
					return;
				}
				break;
			case 8:
				if (board[8] == getcomputer() && board[4] == getcomputer() && board[0] == ' ') //diag
				{
					board[0] = getcomputer();
					return;
				}
				else if (board[8] == getcomputer() && board[5] == getcomputer() && board[2] == ' ') // down
				{
					board[2] = getcomputer();
					return;
				}
				else if (board[8] == getcomputer() && board[7] == getcomputer() && board[6] == ' ') //across
				{
					board[6] = getcomputer();
					return;
				}
				break;
			}
		}


		// defencive think -- special cases || block in one
		if (board[0] == gethuman() && board[2] == gethuman() && board[1] == ' ' )
		{
			board[1] = getcomputer();
			return;
		} else if (board[3] == gethuman() && board[5] == gethuman() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		} else if (board[6] == gethuman() && board[8] == gethuman() && board[7] == ' ' )
		{
			board[7] = getcomputer();
			return;
		} else if (board[0] == gethuman() && board[6] == gethuman() && board[3] == ' ' )
		{
			board[3] = getcomputer();
			return;
		} else if (board[1] == gethuman() && board[7] == gethuman() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		} else if (board[2] == gethuman() && board[8] == gethuman() && board[5] == ' ' )
		{
			board[5] = getcomputer();
			return;
		} else if (board[0] == gethuman() && board[8] == gethuman() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		} else if (board[2] == gethuman() && board[6] == gethuman() && board[4] == ' ' )
		{
			board[4] = getcomputer();
			return;
		}
		//main defencive think || blocks
		for (int i = 0; i <= 8; i++)
		{
			switch(i)
			{
			case 0:
				if (board[0] == gethuman() && board[1] == gethuman() && board[2] == ' ') //across
				{
					board[2] = getcomputer();
					return;
				}
				else if (board[0] == gethuman() && board[4] == gethuman() && board[8] == ' ') //diag
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[0] == gethuman() && board[3] == gethuman() && board[6] == ' ') //down
				{
					board[6] = getcomputer();
					return;
				}
				break;
			case 1:
				if (board[1] == gethuman() && board[4] == gethuman() && board[7] == ' ') //down
				{
					board[7] = getcomputer();
					return;
				}
				break;
			case 2:
				if (board[2] == gethuman() && board[4] == gethuman() && board[6] == ' ') //diag
				{
					board[6] = getcomputer();
					return;
				}
				else if (board[2] == gethuman() && board[5] == gethuman() && board[8] == ' ') // down
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[2] == gethuman() && board[1] == gethuman() && board[0] == ' ') //across
				{
					board[0] = getcomputer();
					return;
				}
				break;
			case 3:
				if (board[3] == gethuman() && board[4] == gethuman() && board[5] == ' ') // across
				{
					board[5] = getcomputer();
					return;
				}
				break;
			case 4:
					// this is the middle square. doesn't really matter.
					// case is checked virtually everywhere else
				break;
			case 5:
				if (board[5] == gethuman() && board[4] == gethuman() && board[3] == ' ')
				{
					board[3] = getcomputer();
					return;
				}
				break;
			case 6:
				if (board[6] == gethuman() && board[7] == gethuman() && board[8] == ' ') //across
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[6] == gethuman() && board[4] == gethuman() && board[2] == ' ') //diag
				{
					board[8] = getcomputer();
					return;
				}
				else if (board[6] == gethuman() && board[3] == gethuman() && board[0] == ' ') //down
				{
					board[0] = getcomputer();
					return;
				}
				break;
			case 7:
				if (board[7] == gethuman() && board[4] == gethuman() && board[1] == ' ') //down
				{
					board[1] = getcomputer();
					return;
				}
				break;
			case 8:
				if (board[8] == gethuman() && board[4] == gethuman() && board[0] == ' ') //diag
				{
					board[0] = getcomputer();
					return;
				}
				else if (board[8] == gethuman() && board[5] == gethuman() && board[2] == ' ') // down
				{
					board[2] = getcomputer();
					return;
				}
				else if (board[8] == gethuman() && board[7] == gethuman() && board[6] == ' ') //across
				{
					board[6] = getcomputer();
					return;
				}
				break;
			}
		}
		for (int i = 0; i <= 8; i++)
		{
			if (board[easyMoves[i]] == ' ')
			{
				board[easyMoves[i]] = getcomputer();
				break;
			}
		}
	}
}

void Tic_Tac_Toe::getInput()
{
	while (true)
	{
		cout << "Coordinates" << endl << ">:";
		string input;
		cin >> input;
		bool isBad = false;
		if (isalpha(input[0]) && isdigit(input[1]))
		{
			if ((toupper(input[0]) != 'A' && toupper(input[0]) != 'B' && toupper(input[0]) != 'C') ||
				(input[1] != '1' && input[1] != '2' && input[1] != '3'))
			{
				cout << "Error: Bad coordinates" << endl;
			}
			switch (toupper(input[0]))
			{
			case 'A':
				switch (input[1])
				{
				case '1':
					if (board[0] == ' ')
					{
						board[0] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				case '2':
					if (board[1] == ' ')
					{
						board[1] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				case '3':
					if (board[2] == ' ')
					{
						board[2] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				}
				break;
			case 'B':
				switch (input[1])
				{
				case '1':
					if (board[3] == ' ')
					{
						board[3] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				case '2':
					if (board[4] == ' ')
					{
						board[4] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				case '3':
					if (board[5] == ' ')
					{
						board[5] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				}
				break;
			case 'C':
				switch (input[1])
				{
				case '1':
					if (board[6] == ' ')
					{
						board[6] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				case '2':
					if (board[7] == ' ')
					{
						board[7] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				case '3':
					if (board[8] == ' ')
					{
						board[8] = gethuman();
					}
					else
					{
						isBad = true;
					}
					break;
				}
				break;
			}
			if (isBad)
			{
				cout << "Error: bad coordinates" << endl;
			}
			else
			{
				cout << "Input accepted!" << endl;
				break;
			}
		}
		else
		{
			cout << "Error: bad coordinates" << endl;
		}
	}
}

void Tic_Tac_Toe::displayBoard()
{
	cout << "   ____________" << endl;
	cout << "A | " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
	cout << "   ------------" <<  endl;
	cout << "B | " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
	cout << "   ------------" <<  endl;
	cout << "C | " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
	cout << "   ____________" << endl;
	cout << "    1   2   3 " << endl << endl;
}

void Tic_Tac_Toe::isTie()
{
}


void Tic_Tac_Toe::setisWin(bool isWin)
{
	this->isWin = isWin;
}
bool Tic_Tac_Toe::getisWin()
{
	return isWin;
}

void Tic_Tac_Toe::sethuman(char human)
{
	this->human = human;
}
char Tic_Tac_Toe::gethuman()
{
	return human;
}

void Tic_Tac_Toe::setcomputer(char computer)
{
	this->computer = computer;
}
char Tic_Tac_Toe::getcomputer()
{
	return computer;
}

//void Tic_Tac_Toe::setboard(char* board)
//{
//	this->board = *board;
//}
//char* Tic_Tac_Toe::getboard()
//{
//	return board;
//}

void Tic_Tac_Toe::setposition(int position)
{
	this->position = position;
}
int Tic_Tac_Toe::getposition()
{
	return position;
}

//void Tic_Tac_Toe::seteasyMoves(char* moves)
//{
//	this->easyMoves = *moves;
//}
//char* Tic_Tac_Toe::geteasyMoves()
//{
//	return easyMoves;
//}

