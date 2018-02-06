#include <iostream>
#include <conio.h>//gia to input() functions for getting a character from a console window 
#include <windows.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x , y,fruitx , fruity , score;
enum eDrirection { STOP=0 , LEFT , RIGHT , UP , DOWN};
eDrirection dir;
void setup()
{
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
}
void draw()
{
	system("cls");
	for (int i = 0;i < width + 2;i++)cout << "#";
	cout << endl;
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruity && j == fruitx)
				cout << "F";
			else 
				cout << " ";
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0;i < width + 2;i++)cout << "#";
	cout << endl;

		}
	


void input()
{
	if (_kbhit())//returns positive number if a character on the keyboard is pressed if nothing is pressed it returns 0
	{
		//_getch-->returns the ascii value of the character that was pressed
		//CONTROLS:
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir=RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}


void logic()
{
	
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	
}


int main()
{	
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
		//Sleep(50);
		if (dir == LEFT || dir == RIGHT)
		{
			Sleep(15);
		}

		Sleep(50);

		if (dir == UP || dir == DOWN)
		{
			Sleep(60);
		}
	}
	return 0;
}