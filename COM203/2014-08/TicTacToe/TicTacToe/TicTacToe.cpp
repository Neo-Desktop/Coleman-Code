
#include "includes.h"

int TicTacToe::easyMoves[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

enum { NUL = 0, SOH, STX, ETX, EOT, ENQ, ACK, BEL, BS, HT,
	   LF, VT, FF, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, 
	   SYN, ETB, CAN, EM, SUB, ESC, FS, GS, RS, US, DEL = 127 };

TicTacToe::TicTacToe(string playername, char playerchar, char computerchar)
{
	setplayername(playername);
	sethuman(playerchar);
	setcomputer(computerchar);

	initboard();
	initwins();
	instructionsdisplayed = false;
}

void TicTacToe::initwins()
{
		wins = vector< vector<int> >(8, vector<int>(3));
		// diagonal
		wins[0][0] = 0;
		wins[0][1] = 4;
		wins[0][2] = 8;

		wins[1][0] = 2;
		wins[1][1] = 4;
		wins[1][2] = 6;

		// down
		wins[2][0] = 0;
		wins[2][1] = 3;
		wins[2][2] = 6;

		wins[3][0] = 1;
		wins[3][1] = 4;
		wins[3][2] = 7;

		wins[4][0] = 2;
		wins[4][1] = 5;
		wins[4][2] = 8;

		// across
		wins[5][0] = 0;
		wins[5][1] = 1;
		wins[5][2] = 2;

		wins[6][0] = 3;
		wins[6][1] = 4;
		wins[6][2] = 5;

		wins[7][0] = 6;
		wins[7][1] = 7;
		wins[7][2] = 8;
}

void TicTacToe::initboard()
{
	memset(board,' ',sizeof(char)*9);
}

void TicTacToe::displayInstructions()
{
	cout << "Instructions: Use your keyboard to type in coordinates to place a "
		 << endl << "token on the game board. " << endl << endl;
	cout << "You are "<< gethuman() << " - the protagonist in the story - you have been chosen by the high " << endl
		 << "council of Tic-Toe to defeat the evil lord " << getcomputer() << ", played by the computer. " << endl;
	cout << "Being the chosen one you are able to place your '" << gethuman() << "'" << endl
		 << "token first, in an any open space." << endl;
	cout << "The computer then places the " << getcomputer() << " token in a free space until " << endl
		 << "all spaces are filled" << endl;
	cout << "You and the computer continue to place tokens in free spaces until the game" << endl
		 << "board is filled " << endl;
	cout << "If all spaces are filled and no winner has been declared then a rematch is "
		 << endl << "called and the forces of good and evil spar once again." << endl << endl;
	system("pause");
	system("cls");
}

void TicTacToe::run()
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
		char input;
		input = _getch();
		cout << input << endl;
		if (toupper(input) == 'E' || input == LF)
		{
			iseasy = true;
			break;
		}
		else if (toupper(input) == 'H')
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
			setiswin(winner());
			if(getiswin())
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
			setiswin(winner());
			if(getiswin())
			{
				cout << "Congratulations! A Winner is You!" << endl;
				system("pause");
				break;
			}
			think(iseasy);
		}
	}
}

void TicTacToe::think(bool easy)
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
	else // hard think
	{
		bool movemade = false;
		if ( board[4] == ' ' ) // own this.
		{
			board[4] = getcomputer();
			movemade = true;
			return;
		}
		else
		{
			int count = 0;
			for (int i = 0; i < 9; i++)
			{
				if (board[i] == getcomputer())
					count++;
				//cout << count;
			}
			bool closerlook = false;
			// do we own the middle square?
			if ( board[4] == getcomputer() )
			{
				// we have more options
				closerlook = true;
			}
			else
			{
				// special case for:
				//   ____________
				//A | X |   |   |
				//	 ------------
				//B |   | O |   |
				//	 ------------
				//C |   |   | O |
				//	____________
				//    1   2   3

				if (board[4] == gethuman() && board[8] == gethuman() && board[6] == ' ')
				{
					board[6] = getcomputer();
					movemade = true;
				}
			}
			if (count >= 1 && !movemade)
			{
				for (int i = 0; i <= 7; i++) // win/block in one
				{
					//cout << "hard think pass: " << i << endl;
					// defensive think - block before win
					if (!movemade && board[wins[i][0]] == gethuman() && board[wins[i][1]] == gethuman() && board[wins[i][2]] == ' ')
					{
						board[wins[i][2]] = getcomputer();
						movemade = true;
						break;
					}
					if (!movemade && board[wins[i][1]] == gethuman() && board[wins[i][2]] == gethuman() && board[wins[i][0]] == ' ')
					{
						board[wins[i][0]] = getcomputer();
						movemade = true;
						break;
					}
					if (!movemade && board[wins[i][2]] == gethuman() && board[wins[i][0]] == gethuman() && board[wins[i][1]] == ' ')
					{
						board[wins[i][1]] = getcomputer();
						movemade = true;
						break;
					}
					//offensive think - seal the win if no blocks can be made?
					if (!movemade && board[wins[i][0]] == getcomputer() && board[wins[i][1]] == getcomputer() && board[wins[i][2]] == ' ')
					{
						board[wins[i][2]] = getcomputer();
						movemade = true;
						break;
					}
					if (!movemade && board[wins[i][1]] == getcomputer() && board[wins[i][2]] == getcomputer() && board[wins[i][0]] == ' ')
					{
						board[wins[i][0]] = getcomputer();
						movemade = true;
						break;
					}
					if (!movemade && board[wins[i][2]] == getcomputer() && board[wins[i][0]] == getcomputer() && board[wins[i][1]] == ' ')
					{
						board[wins[i][1]] = getcomputer();
						movemade = true;
						break;
					}
				}
			}
			if (!movemade) // we still haven't made a move!? win in two? what are we doing? find first open space
			{
				for (int i = 0; i < 9; i++)
				{
					if (board[i] == ' ' )
					{
						board [i] = getcomputer();
						movemade = true;
						break;
					}
				}
			}
		}
	}
}

bool TicTacToe::stalemate()
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

void TicTacToe::displayBoard()
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

void TicTacToe::getInput()
{
	while (true)
	{
		cout << "Coordinates" << endl << ">:";
		string input;
		cin >> input;
		bool isBad = false;
		if (isalpha(input[0]) && isdigit(input[1]))
		{
			if ( toupper(input[0]) > 'C' || toupper(input[0]) < 'A' || input[1]-'0' > 3 || input[1]-'0' < 1 )
			{
				isBad = true;
			}
			else
			{
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
				default:
					isBad = true;
				}
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

bool TicTacToe::winner()
{
	for (int i = 0; i < 2; i++)
	{
		char whatTest = gethuman();
		if (i == 1)
			whatTest = getcomputer();
		for (int j = 0; j < 8; j++) // 8 ways to win
		{
			int thiswin[3] = { wins[j][0], wins[j][1], wins[j][2] };
			// cout << board[thiswin[0]] << board[thiswin[1]] << board[thiswin[2]] << endl;
			if (board[thiswin[0]] == whatTest && board[thiswin[1]] == whatTest && board[thiswin[2]] == whatTest)
				return true;
		}
	}
	return false;
}

bool TicTacToe::isTie()
{
	for (int i = 0; i < boardsize; i++)
	{
		if (board[i] == ' ')
			return true;
	}
	return false;
}


void TicTacToe::setplayername(string playername)
{
	TicTacToe::playername = playername;
}

string TicTacToe::getplayername()
{
	return TicTacToe::playername;
}

void TicTacToe::setiswin(bool isWin)
{
	TicTacToe::isWin = isWin;
}
bool TicTacToe::getiswin()
{
	return TicTacToe::isWin;
}

void TicTacToe::sethuman(char human)
{
	TicTacToe::human = human;
}
char TicTacToe::gethuman()
{
	return TicTacToe::human;
}

void TicTacToe::setcomputer(char computer)
{
	TicTacToe::computer = computer;
}
char TicTacToe::getcomputer()
{
	return TicTacToe::computer;
}

void TicTacToe::setboard(char *board)
{
	*TicTacToe::board = *board;
}
char* TicTacToe::getboard()
{
	return board;
}

void TicTacToe::setposition(int position)
{
	TicTacToe::position = position;
}
int TicTacToe::getposition()
{
	return TicTacToe::position;
}

