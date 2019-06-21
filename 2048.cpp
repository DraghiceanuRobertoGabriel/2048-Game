//The link to play the original 2048 game
// https://play2048.co/

//2048
//Cpp

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int board[4][4];

int dirLine[]   = {1, 0, -1, 0};
int dirColumn[] = {0, 1, 0, -1};

pair<int, int> generateUnoccupiedPosition()
{

	int occupied;
	int line;
	int column;

	occupied = 1;

	while (occupied)
	{

		line = rand() % 4;
		column = rand() % 4;

		if (board[line][column] == 0)
		{

			occupied = 0;

		}

	}

	return make_pair (line, column);

}

void add2or4()
{

	int randnum;
	int DoiSau4;

	pair<int, int> pos;

	randnum = rand();

	if (randnum % 2 == 0)
	{

		DoiSau4 = 2;

	}

	else
	{

		DoiSau4 = 4;

	}

	pos = generateUnoccupiedPosition();

	board[pos.first][pos.second] = DoiSau4;

}

void NewGame()
{

	int i;
	int j;

	for (i = 0; i < 4; ++i)
	{

		for (j = 0; j < 4; ++j)
		{

			board[i][j] = 0;

		}

		add2or4();

	}

}

void MenuUI()
{
	cout << "2048";
	cout << endl;

	cout << endl;

	cout << "Menu:";
	cout << endl;

	cout << endl;

	cout << "N: NEW GAME";
	cout << endl;

	cout << "W: UP";
	cout << endl;

	cout << "A: LEFT";
	cout << endl;

	cout << "S: DOWN";
	cout << endl;

	cout << "D: RIGHT";
	cout << endl;

	cout << "Q: QUIT";
	cout << endl;

	cout << endl;
	cout << endl;

}

void PrintUI()
{

	system("cls");

	int i;
	int j;

	MenuUI();

	for (i = 0; i < 4; ++i)
	{

		for (j = 0; j < 4; ++j)
		{

			if (board[i][j] == 0)
			{

				cout << setw(4) << ".";

			}

			else
			{

				cout << setw(4) << board[i][j];

			}

		}

		cout << endl;

	}

	cout << endl;
	cout << endl;

	cout << "Please insert your comand:";

	cout << endl;
	cout << endl;

}

bool canDoMove(int line, int column, int nextLine, int nextCoulmn)
{

	if (nextLine < 0 || nextCoulmn < 0
		 || nextLine >= 4 || nextCoulmn >= 4
		  || board[line][column] != board[nextLine][nextCoulmn]
		   && board[nextLine][nextCoulmn] != 0)
	{

		return false;

	}

	else
	{

		return true;

	}

}

void applyMove(int direction)
{

	int i;
	int j;

	int startLine;
	int startColumn;

	int lineStep;
	int columnStep;

	int nextI;
	int nextJ;

	int movePossible;
	int canAddPiece;

	startLine = 0;
	startColumn = 0;
	lineStep = 1;
	columnStep = 1;

	if (direction == 0)
	{

		startLine = 3;
		lineStep = -1;

	}

	if (direction == 1)
	{

		startColumn = 3;
		columnStep = -1;

	}

	movePossible = 0;
	canAddPiece = 0;

	do {

		movePossible = 0;

		for (i = startLine; i >= 0 && i < 4; i += lineStep)
		{

			for (j = startColumn; j >= 0 && j < 4; j += columnStep)
			{

				nextI = i + dirLine[direction];
				nextJ = j + dirColumn[direction];

				if (board[i][j] && canDoMove(i, j, nextI, nextJ))
				{

					board[nextI][nextJ] += board[i][j];
					board[i][j] = 0;
					movePossible = 1;
					canAddPiece = 1;

				}

			}

		}

		PrintUI();

	} while (movePossible);

	if (canAddPiece)
	{

		add2or4();

	}

}

int main()
{

	srand(time(0));

	char command;
	char commandToDir[200];
	
	bool wrongCommand;

	int currentDirection;

	commandToDir['s'] = 0;
	commandToDir['d'] = 1;
	commandToDir['w'] = 2;
	commandToDir['a'] = 3;

	NewGame();

	while (true)
	{

		PrintUI();

		wrongCommand = true;

		while (wrongCommand == true)
		{

			cin >> command;

			if (command != 'n' && command != 'q' && command != 'w'
				 && command != 'a' && command != 's' && command != 'd')
			{

				PrintUI();

				cout << "Wrong Command!";
				cout << endl;
				cout << "Please insert a good one:";
				cout << endl;
				cout << endl;

			}

			else
			{

				wrongCommand = false;

			}

		}

		if (command == 'n')
		{

			NewGame();

		}

		else if (command == 'q')
		{

			break;

		}

		else
		{

			currentDirection = commandToDir[command];

			applyMove(currentDirection);

		}

	}

	return 0;
}
