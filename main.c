/* Data Structure Homework
 * Maze Program
 * ID : 2013104184
 * Name : Woo sangmin */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Maze.h"

/* Global Variables */
int i, j;
int maze[ROW][COL];
//bool check[ROW][COL];

int main() {
	char readLine[10];

	/* Maze Initialize */
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			maze[i][j] = 0;
		}
	}

	FILE *fp = fopen("maze.txt", "r");
	i = 1;
	while (!feof(fp)) {
		int k = 0;
		fscanf(fp, "%s", readLine);
		for (j = 1; j < COL - 1; j++) {
			maze[i][j] = (int)(readLine[k]) - SUB;
			k++;
		}
		i++;
	}

	printMaze(maze, ROW, COL);
	startGame(maze);
	printMaze(maze, ROW, COL);
	return 0;
}