#include<iostream>
#include<fstream>
using namespace std;


void endGame()
{
	cout << endl << endl;
	cout << "     Game Ended" << endl << endl << endl;

	exit(0);
}


char choiceSelection()
{

	char choice = 'a';

	while (choice != 'n' && choice != 'r' && choice != 'l' && choice != 'h' && choice != 'e')
	{

		cout << "Press n for new game" << endl;
		cout << "Press r for resume game" << endl;
		cout << "Press l for level selection" << endl;
		cout << "Press h for high score" << endl;
		cout << "Press e for exit" << endl;
		cout << endl;
		cout << "Press Key : ";
		cin >> choice;
		cout << endl;
		if (choice != 'n' && choice != 'r' && choice != 'l' && choice != 'h' && choice != 'e')
		{
			cout << "Wrong Input! Try Again." << endl << endl;
		}

	}
	return choice;
}

char levelSelection()
{
	cout << endl << endl;
	char level = '1';

	cout << "LEVEL SELECTION" << endl << endl;
	cout << " Press 1 for easy" << endl;
	cout << " Press 2 for medium" << endl;
	cout << "Enter your level : "; cin >> level;

	cout << endl << endl;

	return level;
}



void display(char arr[][8], int r, int c)
{
	cout << "                                              [ Search Words in a given Table  ]" << endl << endl << endl;

	for (int i = 0; i < r; i++)
	{
		cout << "                                                    ";
		for (int j = 0; j < c; j++)
		{
			cout << " ";
			cout << arr[i][j];
		}
		cout << endl;
	}

}

void i_display(char arr[][15], int r, int c)
{
	cout << "                                              [ Search Words in a given Table  ]" << endl << endl << endl;

	for (int i = 0; i < r; i++)
	{
		cout << "                                                    ";
		for (int j = 0; j < c; j++)
		{
			cout << " ";
			cout << arr[i][j];
		}
		cout << endl;
	}

}

void input_word(char word[])
{

	cout << endl;
	cout << "Enter a word to search :" << endl;
	cin >> word;

}

char pause(char arr[][8], char word[], char end) 
{

	if (word[0] == 'p' || word[0] == 'P')
	{
		ofstream fout("Pausedgame.txt");
		
		for (int i = 0; i < 8; i++)
		{

			for (int j = 0; j < 8; j++)
			{

				fout << arr[i][j];
			}
			fout << endl;
		}


		cout << endl;
		cout << "Press e for exit." << endl;
		cout << "Press r for resume." << endl;
		cout << "Enter Your Choice : ";
		cin >> end;

		if (end == 'e' || end == 'E')
		{
			endGame();
		}
	}
	return end;
}

char i_pause(char arr[][15], char word[], char end) 
{

	if (word[0] == 'p' || word[0] == 'P')
	{
		ofstream fout("Pausedgame.txt");
		
		for (int i = 0; i < 15; i++)
		{

			for (int j = 0; j < 15; j++)
			{

				fout << arr[i][j];
			}
			fout << endl;
		}


		cout << endl;
		cout << "Press e for exit." << endl;
		cout << "Press r for resume." << endl;
		cout << "Enter Your Choice : ";
		cin >> end;

		if (end == 'e' || end == 'E')
		{
			endGame();
		}
	}
	return end;
}



void resume(char arr[][8]) 
{

	ifstream finn;

	finn.open("Pausedgame.txt");
	while (!finn.eof())
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				finn >> arr[i][j];
			}
		}

	}
	finn.close();
}

void i_resume(char arr[][15]) 
{

	ifstream finn;

	finn.open("Pausedgame.txt");

	while (!finn.eof())
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				finn >> arr[i][j];
			}
		}

	}
	finn.close();
}

void verify(char word[], char& present, int& word_size)
{
	while (present == 'n')
	{
		present = 'n';
		word_size = 0;

		for (int i = 0; word[i] != 0; i++)
		{
			word_size++;
		}

		char com[10];
		int count = 0;
		ifstream fin1;
		fin1.open("dictionary.txt");
		while (!fin1.eof())
		{
			count = 0;

			fin1 >> com;
			for (int i = 0; i < word_size; i++)
			{
				if (word[i] == com[i])
				{
					count++;
					if (word_size == count)
					{
						present = 'y';
					}
				}

			}

		}
		if (present == 'n')
		{
			cout << "Not found in Dictionary." << endl;
			cout << "Enter word again : ";
			cin >> word;
		}

		fin1.close();

	}

}

void e_forwardRow(int& cfr, char arr[][8], char word[], int word_size, int& score, char& p)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cfr = 0;
			if (arr[i][j] == word[cfr])                 
			{
				for (int k = 0; k < word_size; k++)
				{
					if (arr[i][j + k] == word[k])
					{
						cfr++;

					}


				}
				if (word_size == cfr)
				{

					cout << "Start at (row " << i << " , col " << j << ")" << endl;
					cout << "End at (row " << i << " , col " << j + cfr - 1 << ")" << endl;

					score += 10;
					p = 'y';
				}
			}
		}
	}
}

void i_forwardRow(int& cfr, char arr[][15], char word[], int word_size, int& score, char& p)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cfr = 0;
			if (arr[i][j] == word[cfr])                  
			{
				for (int k = 0; k < word_size; k++)
				{
					if (arr[i][j + k] == word[k])
					{
						cfr++;

					}


				}
				if (word_size == cfr)
				{

					cout << "Start at (row " << i << " , col " << j << ")" << endl;
					cout << "End at (row " << i << " , col " << j + cfr - 1 << ")" << endl;

					score += 10;
					p = 'y';
				}
			}
		}
	}
}



void e_forwardcol(int& cfc, char arr[][8], char word[], int word_size, int& score, char& p)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			cfc = 0;
			if (arr[i][j] == word[cfc])                  
			{
				for (int k = 0; k < word_size; k++)
				{
					if (arr[i + k][j] == word[k])
					{
						cfc++;

					}


				}
				if (word_size == cfc)
				{

					cout << "Start at (row " << i << " , col " << j << ")" << endl;
					cout << "End at (row " << i + cfc - 1 << " , col " << j << ")" << endl;


					score += 10;
					p = 'y';
				}
			}
		}
	}



}

void i_forwardcol(int& cfc, char arr[][15], char word[], int word_size, int& score, char& p)
{
	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 15; i++)
		{
			cfc = 0;
			if (arr[i][j] == word[cfc])                  
			{
				for (int k = 0; k < word_size; k++)
				{
					if (arr[i + k][j] == word[k])
					{
						cfc++;

					}


				}
				if (word_size == cfc)
				{

					cout << "Start at (row " << i << " , col " << j << ")" << endl;
					cout << "End at (row " << i + cfc - 1 << " , col " << j << ")" << endl;


					score += 10;
					p = 'y';
				}
			}
		}
	}



}


void backwardrow(int& cbr, char arr[][15], char word[], int word_size, int& score, char& p)
{
	for (int i = 14; i > 0; i--)
	{
		for (int j = 14; j > 0; j--)
		{
			cbr = 0;
			if (arr[i][j] == word[cbr])                  
			{
				for (int k = 0; k < word_size; k++)
				{
					if (arr[i][j - k] == word[k])
					{
						cbr++;

					}


				}
				if (word_size == cbr)
				{

					cout << "Start at (row " << i << " , col " << j << ")" << endl;
					cout << "End at (row " << i << " , col " << j - cbr + 1 << ")" << endl;
					cout << endl;

					score += 10;
					p = 'y';
				}



			}

		}


	}
}

void backwardcol(int& cbc, char arr[][15], char word[], int word_size, int& score, char& p)
{
	for (int j = 14; j > 0; j--)
	{
		for (int i = 14; i > 0; i--)
		{
			cbc = 0;
			if (arr[i][j] == word[cbc])                  
			{
				for (int k = 0; k < word_size; k++)
				{
					if (arr[i - k][j] == word[k])
					{
						cbc++;

					}


				}
				if (word_size == cbc)
				{

					cout << "Start at (row " << i << " , col " << j << ")" << endl;
					cout << "End at (row " << i - cbc + 1 << " , col " << j << ")" << endl;

					score += 10;
					p = 'y';
				}



			}

		}


	}
}

void highScore()
{
	ifstream finn2("Highrecord.txt");
	if (!finn2)
	{
		cout << "No Record Yet." << endl;
	}
	else
	{
		char line[30];
		while (!finn2.eof())
		{
			finn2.getline(line, 30);
			cout << line << endl;
		}
	}
	finn2.close();
}

int main()
{
	char arr[8][8];
	char arr1[15][15];
	char again = 'y';
	char name[30];
	int score = 0, lives = 2;
	char choice = 'n';
	char level = '1';

	while (again == 'y' || again == 'Y')
	{

		again = 'y';
		score = 0;
		lives = 2;
		choice = 'n';
		level = '1';


		
		choice = 'n';
		level = '1';

		choice = choiceSelection();

		
		if (choice == 'l' || choice == 'L')
		{
			while (choice == 'l' || choice == 'L')
			{

				level = levelSelection();

				choice = choiceSelection();
			}
		}
		else 
		{
			level = '1';

		}


		if (choice == 'n')
		{

			cout << "Enter Player Name : ";
			cin >> name;
			cout << endl << endl;

		
			if (level == '1')
			{
				cout << endl;
				cout << "                                                  @ @ @ Easy Mode @ @ @ " << endl;
				cout << endl;
				cout << endl;

				cout << "                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                            Welcome to WORD SEARCH Game                  *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

				cout << endl;
				cout << endl;


				ifstream fin;
				fin.open("board.txt");
				while (!fin.eof())
				{
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							fin >> arr[i][j];
						}
					}

				}
				fin.close();

				display(arr, 8, 8);



				//lives
				lives = 2;
				while (lives > 0)
				{

					//word to search
					cout << endl;
					char word[10];
					int word_size = 0;
					input_word(word);

					//pause game
					char res = 'n';

					res = pause(arr, word, res);

					//resume
					if (res == 'r')
					{
						resume(arr);
					}
					else
					{
						ifstream finn;
						finn.open("board.txt");
						while (!finn.eof())
						{
							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 8; j++)
								{
									finn >> arr[i][j];
								}
							}

						}
						finn.close();
					}


					//verify word
					char present = 'n';
					word_size = 0;

					present = 'n';

					verify(word, present, word_size);


					//find word forward row wise
					char p = 'n';
					int cfr = 0;


					e_forwardRow(cfr, arr, word, word_size, score, p);
					int cfc = 0;
					e_forwardcol(cfc, arr, word, word_size, score, p);



					if (p == 'n')
					{
						lives--;
						if (lives == 1)
						{
							cout << "Word not Found in Board! You have One more lives" << endl << endl;
						}
						if (lives == 0)
						{
							cout << "Word not Found in Board! You have no more lives" << endl << endl;
						}
					}
				}


			}
			else if (level == '2')
			{
				cout << endl;
				cout << "                                                  @ @ @ Easy Mode @ @ @ " << endl;
				cout << endl;
				cout << endl;

				cout << "                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                            Welcome to WORD SEARCH Game                  *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           *                                                                         *" << endl;
				cout << "                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

				cout << endl;
				cout << endl;

				//read from board
				
				ifstream fin;
				fin.open("board.txt");
				while (!fin.eof())
				{
					for (int i = 0; i < 15; i++)
					{
						for (int j = 0; j < 15; j++)
						{
							fin >> arr1[i][j];
						}
					}

				}
				fin.close();


				i_display(arr1, 15, 15);



				//lives

				lives = 2;
				while (lives > 0)
				{

					//word to search
					cout << endl;
					char word[10];
					int word_size = 0;
					input_word(word);

					//pause game
					char res = 'n';

					res = i_pause(arr1, word, res);

					//resume
					if (res == 'r')
					{
						i_resume(arr1);
					}
					else
					{
						ifstream finn;
						finn.open("board.txt");
						while (!finn.eof())
						{
							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 8; j++)
								{
									finn >> arr1[i][j];
								}
							}

						}
						finn.close();
					}


					//verify word
					char present = 'n';
					word_size = 0;

					present = 'n';

					verify(word, present, word_size);



					char p = 'n';



					cout << endl;
					int cfr = 0;
					i_forwardRow(cfr, arr1, word, word_size, score, p);


					int cbr = 0;
					backwardrow(cfr, arr1, word, word_size, score, p);



					cout << endl;
					int cfc = 0;
					i_forwardcol(cfc, arr1, word, word_size, score, p);

					cout << endl;
					int cbc = 0;
					backwardcol(cbr, arr1, word, word_size, score, p);


					if (p == 'n')
					{
						lives--;
						if (lives == 1)
						{
							cout << "Word not Found in Board! You have One more lives" << endl << endl;
						}
						if (lives == 0)
						{
							cout << "Word not Found in Board! You have no more lives" << endl << endl;
						}
					}
				}

			}

			ofstream foutt;
			foutt.open("Highrecord.txt", ios::app);
			foutt << name << "\t\t" << score << endl;
			foutt.close();


		}
		else if (choice == 'r')
		{


			ifstream finP("Pausedgame.txt");
			if (!finP)
			{
				cout << "First Play Some Game." << endl;
			}
			else
			{
				resume(arr);
			}

			finP.close();
		}



		else if (choice == 'h')
		{

			highScore();
		}

		else if (choice == 'e')
		{
			endGame();
		}

		cout << endl << endl << "Do you want to play again? y/n : ";
		cin >> again;


	}

	return 0;
}
