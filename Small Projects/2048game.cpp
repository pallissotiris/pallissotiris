#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*
This is my version of the popular game 2048, played in the command line.
The game is played with the WASD keys.
*/

bool won = false;

//The array that holds all the tiles' values
int a[16];

//Function that generates a "2"tile in the top-left corner of the board. 
//It should generate a "2" or "4" tile in a random unoccupied tile. 
void generate() {
	a[0] = 2;
}

//Function to chech if a tile is out of space to move
bool oos(int a, int b) {
	if (b == 1) {
		if (a == 3 || a == 7 || a == 11 || a == 15) return true;
		return false;
	}
	else if (b == -1) {
		if (a == 0 || a == 4 || a == 8 || a == 12) return true;
		return false;
	}
	else if (b == 4) {
		if (a == 12 || a == 13 || a == 14 || a == 15) return true;
		return false;
	}
	else {
		if (a == 0 || a == 1 || a == 2 || a == 3) return true;
		return false;
	}
}

//Function that moves all tiles that can move based on the direction given
void move(int loc, int x, int direc) {
	int pars = direc;
	while (a[loc + pars] == 0 && !oos(loc + pars, direc)) pars += direc ;
	if (a[loc + pars] == 0) swap(a[loc], a[loc + pars]);
	else if (a[loc + pars] == x) {
		a[loc + pars] *= 2;
		a[loc] = 0;
		if (x == 1024) won = true;
	}
	else {
		a[loc] = 0;
		a[loc + pars - direc] = x;
	}
}

//Function that prints the game board
void show(){
	cout <<  "---------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int j = 0; j < 4; j++) {
			cout << setw(4) << a[(i * 4) + j] << " | ";
		}
		cout << endl << "---------------------------" << endl;
	}
}

//Funtion that handles the gameplay. I
void play() {
	bool won = false;
	int dir, pos;
	char arrow;
	for (int i = 0; i < 16; i++) a[i] = 0;
	generate();
	show();
	while (!won) {
		cin >> arrow;
		if (arrow == w )dir = -4;
		else if (arrow == s)dir = 4;
		else if (arrow == a) dir = -1;
		else if(arrow == d) dir = 1;
		if(dir == 1){
			for (int i = 2; i > -1; i--) {
				for (int j = 0; j < 4; j++) {
					pos = i + (j * 4);
					move(pos, a[pos], dir);
				}
			}
			generate();
			show();
		}
		else if(dir == -1){
			for (int i = 1; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					pos = i + (j * 4);
					move(pos, a[pos], dir);
				}
			}
			generate();
			show();
		}
		else if (dir == 4){
			for (int i = 2; i > -1; i--) {
				for (int j = 0; j < 4; j++) {
					pos = (i * 4) + j;
					move(pos, a[pos], dir);
				}
			}
			generate();
			show();
		}
		else if(dir==-4){
			for (int i = 1; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					pos = (i * 4) + j;
					move(pos, a[pos], dir);
				}
			}
			generate();
			show();
		}
	}
	//You get here only after you've won
	cout << "You won!";
}

int main()
{
	play();
}

