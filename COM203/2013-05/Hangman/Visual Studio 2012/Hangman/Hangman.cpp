#include "stdhangman.h"

Hangman::Hangman()
{
	attempts   = 0;
	wordLength = 0;
	secretWord = "";
	wordList = vector<hangword>();
	adminList = vector<string>();
	//readdmins();
	readFromFile();
	blankguesses();
	doseed();
}

void Hangman::blankguesses()
{
	attempts = 0;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (unsigned int i = 0; i < alpha.length(); i++)
	{
		alphabet[i] = alpha[i];
	}
}

void Hangman::displayMenu()
{
	while (true)
	{
		cls();
		fflush(stdout);
		centerline("Main Menu",1);
		centerline("==========================",2);
		centerline("1. Game Administration",3);
		centerline("2. Begin a game",4);
		centerline("3. Exit",5);
		centerline("==========================",6);
		cursorpos(1,7);
		cout << "Please make a selection" << endl << ":";
		string input;
		cin >> input;
		switch (input[0])
		{
		case '1':
			while(doadmin());
			break;
		case '2':
			while(playGame());
			break;
		case '3':
			break;
		default:
			writeline("Please make a valid selection [1-3]");
			writeline(2);
		}
		if ( input[0] == '3' )
		{
			break;
		}
	}
}

bool Hangman::playGame()
{
	chooseword();
	blankguesses();
	while (attempts <= 6)
	{
		while(!handleinput());
		if (revealedword == secretWord)
		{
			break;
		}
	}
	cls();
	if (attempts >= 6)
	{
		centerline("Hangman - Loss", 1);
		centerline(secretWord, 4);
		centerline("Sorry! You loose this round", 8);
	}
	else
	{
		centerline("Hangman - Winner", 1);
		centerline(secretWord, 4);
		centerline("Congratulations! You guessed correctly",8);
	}
	writeline(2);

	string input;
	while (true)
	{
		cout << "Play again?" << endl << "[Y/n]";
		cin >> input;
		if (toupper(input[0]) == 'Y')
		{
			return true;
		}
		else if (toupper(input[0]) == 'N')
		{
			return false;
		}
		else
		{
			cout << "Please enter either Yes or No" << endl;
		}
	}
	return true;
}

bool Hangman::notguessed(char inguess)
{
	for (int j = 0; j < 26; j++)
	{
		if (alphabet[j] == inguess)
		{
			alphabet[j] = ' ';
			return true;
		}
	}
	return false;
}

bool Hangman::doadmin()
{
	cls();
	centerline("Hangman - Administration",1);
	centerline("Hangman Administrator Login",4);
	cursorpos(1,10);
	cout << "Please enter your password" << endl << ":";
	return false;
}

bool Hangman::isinword(char inguess)
{
	string secret = getSecretWord(); 
	for (unsigned int i = 0; i < secret.length(); i++)
	{		
		if (secret[i] == toupper(inguess))
		{
			return true;
		}
	}
	return false;
}

void Hangman::drawletters()
{
	for (int i = 0; i < 26; i++)
	{
		if (i == 0)
		{
			cursorpos (4,6);
		}
		if (i == 8)
		{
			cursorpos (4,8);
		}
		if (i == 16)
		{
			cursorpos (4,10);
		}
		if ( i == 24 )
		{
			cursorpos(4, 12);
		}
		cout << alphabet[i] << "   ";
	}
	cursorpos(4, 18);
	cout << revealedword;
}

bool Hangman::handleinput()
{
	cls(); // clear screen
	drawseperator(); // do the separator thing
	centerline("Hangman",1); // screen title
	drawhangman();
	drawletters();
	fflush(stdout);
	cursorpos(0, 20);
	writeline("Please enter a letter");
	cout << ":";
	string input;
	cin >> input;
	char guess = input[0];
	guess = toupper(guess);
	if (isalpha(guess) && notguessed(guess))
	{
		if (isinword(guess))
		{
			revealchar(guess);
		}
		else
		{
			attempts++;
		}
		return true;
	}
	else
	{
		cout << guess << " is an invalid input, please try again";
		pause();
		return false;
	}
}

void Hangman::revealchar(char input)
{
	string secret = getSecretWord();
	for (unsigned int i = 0; i < secret.length(); i++)
	{
		if (secret[i] == input)
		{
			revealedword[i] = secret[i];
		}
	}
}

void Hangman::readFromFile()
{
/*
	hangword holdword;
	ifstream hangmanfile ("wordlist.bin", ios::in|ios::binary|ios::ate);
	if (hangmanfile.is_open())
	{
		while(!hangmanfile.eof())
		{
			holdword.Read(hangmanfile);
			wordList.push_back(holdword);
		}
	}
	else
	{
		cout << "Unable to open wordlist.bin for reading. Trying to create it.." << endl;
*/
		initFile();
//	}
}

void Hangman::initFile()
{
	hangword holdword;
	ifstream hangwordtxt ("hangmanwordlist.txt", ios::in);
	int id = 1;
	if (hangwordtxt.is_open())
	{
		while (!hangwordtxt.eof())
		{
			string word = "";
			getline(hangwordtxt,word);
			for (unsigned int j = 0; j < word.length(); j++)
			{
				word[j] = toupper(word[j]);
			}
			holdword.setword(word);
			holdword.setid(id);
			wordList.push_back(holdword);
			id++;
		}
	}
	else
	{
		cout << "Error unable to open hangmanwordlist.txt for reading" << endl;
		pause();
	}
	hangwordtxt.close();
	if (wordList.size() != 0)
	{
		ofstream hangmanbin ("wordlist.bin", ios::out|ios::binary|ios::app);
		if (hangmanbin.is_open())
		{
			for (unsigned int i = 0; i < wordList.size(); i++)
			{
				wordList[i].Write(hangmanbin);
			}
		}
		else
		{
			cout << "Error unable to open wordlist.bin for writing" << endl;
			pause();
		}
	}
	else
	{
		cout << "No words in the wordlist. Not creating file." << endl;
		pause();
	}
}

void Hangman::chooseword()
{
	if (wordList.size() == 0)
	{
		hangword hang;
		hang.setid(0);
		hang.setword("TEST");
		wordList.push_back(hang);
	}
	int wordindex = rand()%wordList.size();
	setSecretWord(wordList[wordindex].getword());
	string rev = string(getSecretWord().length(),'_');
	revealedword = rev;
}

void Hangman::drawhangman()
{
	cursorpos(55, 10);
	switch (attempts)
	{
	case 0:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"          |" << endl;
		cursorpos(55, 13);
		cout <<"          |" << endl;
		cursorpos(55, 14);
		cout <<"          |" << endl;
		cursorpos(55, 15);
		cout <<"          |" << endl;
		break;
	case 1:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"          |" << endl;
		cursorpos(55, 14);
		cout <<"          |" << endl;
		cursorpos(55, 15);
		cout <<"          |" << endl;
		break;
	case 2:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"      |   |" << endl;
		cursorpos(55, 14);
		cout <<"          |" << endl;
		cursorpos(55, 15);
		cout <<"          |" << endl;
		break;
	case 3:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"     /|   |" << endl;
		cursorpos(55, 14);
		cout <<"          |" << endl;
		cursorpos(55, 15);
		cout <<"          |" << endl;
		break;
	case 4:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"     /|\\  |" << endl;
		cursorpos(55, 14);
		cout <<"          |" << endl;
		cursorpos(55, 15);
		cout <<"          |" << endl;
		break;
	case 5:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"     /|\\  |" << endl;
		cursorpos(55, 14);
		cout <<"      |   |" << endl;
		cursorpos(55, 15);
		cout <<"          |" << endl;
		break;
	case 6:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"     /|\\  |" << endl;
		cursorpos(55, 14);
		cout <<"      |   |" << endl;
		cursorpos(55, 15);
		cout <<"     /    |" << endl;
		break;
	case 7:
		cout <<"       ___ " << endl;
		cursorpos(55, 11);
		cout <<"      |   |" << endl;
		cursorpos(55, 12);
		cout <<"      @   |" << endl;
		cursorpos(55, 13);
		cout <<"     /|\\  |" << endl;
		cursorpos(55, 14);
		cout <<"      |   |" << endl;
		cursorpos(55, 15);
		cout <<"     / \\  |" << endl;
		break;
	}
		cursorpos(55, 16);
		cout <<"  ________|________" << endl;
		cursorpos(55, 17);
		cout <<" /        |       /|" << endl;
		cursorpos(55, 18);
		cout <<"/________________/ /" << endl;
		cursorpos(55, 19);
		cout <<"|________________|/" << endl;
}

void Hangman::setSecretWord(string word)
{
	secretWord = word;
}
string Hangman::getSecretWord()
{
	return secretWord;
}

void Hangman::setWordLength(int length)
{
	wordLength = length;
}
int Hangman::getWordLength()
{
	return wordLength;
}

/***********************************
       ___
      |   |
      @   |
     /|\  |
      |   |
     / \  |
  ________|________
 /        |       /|
/________________/ /
|________________|/

************************************/