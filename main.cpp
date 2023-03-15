#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <dos.h>
using namespace std;

char grid[32][32], x[10][10], o[10][10], * p[10][10];

void drawGrid();
//int whosTurn(int a);

int main() {
	int i, j, square, posrow = 0, poscol = 0, mode, xro;
	const int SIZE = 10;
	bool gameRunning = false;


	// DRAWING AN X
	for (j = 0; j < SIZE; j++) {
		for (i = 0; i < SIZE; i++) {
			if (j == i || i == (SIZE - 1) - j) {
				x[j][i] = '*';
			}
			else {
				x[i][j] = ' ';
			}
		}
	}
	//DRAWING AN 0
	for (j = 0; j < 10; j++) {
		for (i = 0; i < 10; i++) {
			if ((j == 0) || (i == 9) || (j == 9) || (i == 0) || (j == i)) {
				o[j][i] = '*';
			}
			else {
				o[j][i] = ' ';
			}
		}
	}



	//DRAWING GRID
	for (int j = 0; j < 32; j++) {
		for (int i = 0; i < 32; i++) {
			if ((i == 10) || (i == 21)) {
				grid[i][j] = '|';
			}
			else {
				grid[i][j] = ' ';
			}if ((j == 10) || (j == 21)) {
				grid[i][j] = '-';
			}

		}
	}
	//WELCOME SCREEN
	printf("		W E L C O M E		T O		T I C T A C T O E	\n\n\n");
	Sleep(1500);
	printf("The aim of the game is to get either 3 X's or 3 O's in a line, horizontaly, vertically or diagonally!\n\n");
	Sleep(1500);
	printf("You can choose to play against AI or select 2player mode with a friend!\n\n");
	Sleep(3000);
	printf("Please Enter '1' to play against AI.\n\n");
	printf("Or Enter '2' to play with a friend :)\n\n");
	scanf_s("%i", &mode);

	if (mode == 1) {
		gameRunning = true;
		system("cls");
		printf("You have selected to play against AI.\n\n");
		Sleep(1500);
		printf("Please Press '1' to play as X's or '2' to play as O's.\n");
		scanf_s("%i", &xro);
		Sleep(2000);
		system("cls");
	}

	drawGrid();
	while (gameRunning == true) {
		printf("Please select a square(1-9): \n");
		scanf_s("%i", &square);
		switch (square) {
		case 1:
			posrow = 0;
			poscol = 0;
			break;
		case 2:
			posrow = 11;
			poscol = 0;
			break;
		case 3:
			posrow = 22;
			poscol = 0;
			break;
		case 4:
			posrow = 0;
			poscol = 11;
			break;
		case 5:
			posrow = 11;
			poscol = 11;
			break;
		case 6:
			posrow = 22;
			poscol = 11;
			break;
		case 7:
			posrow = 0;
			poscol = 22;
			break;
		case 8:
			posrow = 11;
			poscol = 22;
			break;
		case 9:
			posrow = 22;
			poscol = 22;
			break;
		default:
			printf("Wrong Entry!");
			Sleep(1000);
			break;
		}

		for (j = 0; j < 10; j++) {
			for (i = 0; i < 10; i++) {
				if (xro == 1) {
					grid[posrow + j][poscol + i] = x[i][j];
				}
				else if (xro == 2) {
					grid[posrow + j][poscol + i] = o[i][j];
				}
			}
		}
	
		
		system("cls");
		drawGrid();
		
	}
	return 0;

}

void drawGrid() {
	for (int j = 0; j < 32; j++) {
		for (int i = 0; i < 32; i++) {
			printf("%c", grid[i][j]);
			if (i == 31) {
				printf("\n");
			}
		}
	}
}

/*int whosTurn(int a) {
	for (int i = 0; i < 10; i++) {
		if(i%2==0){
			a = 1;
			return a;
		}
	}
}
*/



