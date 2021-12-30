#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

// Variables ,Constants
bool game_end=0;
const int xmax=35,ymax=20;
int headx=xmax/2,heady=ymax/2;
char dir;
int fruitx=rand()%xmax;
int fruity=rand()%ymax;
int score=0;

// Main Game

void game_control(){
	if(headx==fruitx && heady == fruity){
		fruitx = rand()%(xmax-1) + 1;
		fruity = rand()%(ymax-1) + 1;
		score= score+5;
	}
	if(headx==xmax || heady==ymax || headx == 1 || heady == 1){
		game_end = 1;
	}
	
} 

void input(){
	if (_kbhit()){
		switch (getch()){
			case ('i'):
				if (dir != 'd'){
				dir = 'u' ;}
				break;
			case ('j'):
				if (dir != 'r'){
				dir = 'l';}
				break;
			case ('k'):
				if (dir != 'u'){
				dir = 'd';}
				break;
			case ('l'):
				if (dir != 'l'){
				dir = 'r';}
		}
	}
}

void direction(){
	switch (dir){
		case ('u'):
			heady--;
			break;
		case ('l'):
			headx--;
			break;
		case ('r'):
			headx++;
			break;
		case ('d'):
			heady++;
			break;
	}
}

void drawing(){
	system("CLS");
	for (int y = 1 ; y<=ymax ; y++){
		if (y==1 || y==ymax){
			for(int x = 1 ; x<=xmax ; x++){
				if(x==1 || x==xmax){
					cout << "|";
				}
				else{
					cout << "_";
				}
			}
		}else{
			for(int x = 1 ; x<=xmax ; x++){
				if(x==1 || x==xmax){
					cout << "|";
				}
				else if(x==headx && y ==heady){
					cout << "X";
				}
				else if(x==fruitx && y ==fruity){
					cout << "0";
				}
				else{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	cout << "Score : " << score;
}


int main(){
	srand(time(NULL));
	while (!game_end){
		drawing();
		if(_kbhit()){
			input();}
		direction();
		game_control();
	}
	
	getch();
	
	return 0;
}
