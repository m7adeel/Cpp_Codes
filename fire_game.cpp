#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int x_max = 50, y_max = 30;
char dir;
bool bullet = 0;
int bulletx = 0,bullety =0;
char dir_bul;
bool enemy =1;
int enemyx,enemyy;

void fire();

class player
{
	public:
		string name;
		string direction;
		int score = 0;
		int x = x_max/2 , y = y_max/2;
		
		void movement(char dir)
		{
			switch(dir)
			{
				case 'i':
					y--;
					direction = "up";
					break;
				
				case 'k':
					y++;
					direction = "down";
					break;
					
				case 'j':
					x--;
					direction = "left";
					break;
					
				case 'l':
					x++;
					direction = "right";
					break;
			}
		}
		
};

// Declaring a player in the game
	player p1;
//end of declaration

inline void draw()
{
	system("CLS");
	for (int y = 1 ; y < y_max ; y++)
	{
		for(int x = 1 ; x < x_max ; x++)
		{
			if(y == 1 || y == y_max -1)
			{
				cout << "0";
			}
			else
			{
				if(x == 1 || x == x_max - 1)
				{
					cout << "0";
				}
				else if(x == p1.x && y == p1.y)
				{
					cout << "0";
				}
				else if(x == p1.x && y == (p1.y+1))
				{
					cout << "0";
				}
				else if(x == (p1.x-1) && y == (p1.y+1))
				{
					cout << "0";
				}
				else if(x == (p1.x+1) && y == (p1.y+1))
				{
					cout << "0";
				}
				else if(x == bulletx && y == bullety  && bullet == 1)
				{
					cout << "|";
				}
				else if(x == enemyx && y == enemyy && enemy == 1)
				{
					cout << "E";
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	cout << p1.name << "'s Score : " << p1.score;
}

inline void bul_mov()
{
	if(bulletx == enemyx && bullety == enemyy && enemy == 1)
	{
		bullet = 0;
		enemyx = rand() % (x_max-4) + 3;
		enemyy = rand() & (y_max-10) + 2;
		p1.score += 5;
	}
	else if(dir_bul == 'u')
	{
		bullety--;
	}
	if(bulletx == 0 || bullety == 0)
	{
		bullet = 0;
	}
}

int main()
{
	srand(time(0));
	enemyx = rand() % (x_max-4) + 3;
	enemyy = rand() % (y_max-10) + 2;
	
	cout << "\n\n\t\tEnter Player 1 Name : ";
	cin >> p1.name;
	
	while(1)
	{
		draw();
		dir = getch();
		p1.movement(dir);
		if(dir == 'a')
		{
			fire();
			while(bullet)
			{
				draw();
				bul_mov();
			}
		}
	}
	
	return 0;
}

inline void fire()
{
	bullet = 1;
	bulletx = p1.x;
	bullety =(p1.y-1);
	dir_bul = 'u';
}
