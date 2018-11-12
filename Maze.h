#ifndef __MAZE__H__
#define __MAZE__H__

#define ROW 6
#define COL 8
#define SUB 48	//ASCII 1 -> integer 1
#define CHECK 9	//방문을 했는지 CHECK

/* Function Prototype */
void printMaze(int maze[][COL], int row, int col);
void startGame(int maze[][COL]);

#endif