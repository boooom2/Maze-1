#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Maze.h"

/* Global Variables */
int i, j;
int maze[ROW][COL];

/* Print Maze */
void printMaze(int maze[][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/* Start Game
 * 1. Cur가 goal이라면 게임 종료, 아니라면 계속 진행
 * 2. Cur에서 오른쪽 아래로 이동하고 이전 위치를 stack에 넣는다.
 * 3. 이동할 수 없으면 아래로 이동하고 이전 위치를 stack에 넣는다.
 * 4. 이동할 수 없으면 오른쪽으로 이동하고 이전 위치를 stack에 넣는다.
 *		....(이 과정을 계속 반복)....
 * 8방향 모두 이동할 수 있는 곳이 없으면 현재 위치를 CHECK로 만들고 이전 위치를 pop
 */
void startGame (int maze[][COL]) {
	int r = 1, c = 1;	//start
	int cnt = 0;		//count
	bool goal = false;	//goal
	STACK *sRow = (STACK*)malloc(sizeof(STACK));
	STACK *sCol = (STACK*)malloc(sizeof(STACK));
	stackInit(sRow);
	stackInit(sCol);

	while (!goal) {	
		if (r == ROW - 2 && c == COL - 2) {
			goal = true;
			printf("=== The End ===\n");
			printf("COUNT : %d \n", cnt);
		}

		if (maze[r + 1][c + 1] == 1) {		// ↘
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r++; c++; cnt++;
		}
		else if (maze[r + 1][c] == 1) {	// ↓
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r++; cnt++;
		}
		else if (maze[r][c + 1] == 1) {	// →
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			c++; cnt++;
		}
		else if (maze[r + 1][c - 1] == 1) {	// ↙
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r++; c--; cnt++;
		}
		else if (maze[r - 1][c + 1] == 1) {	// ↗
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r--; c++; cnt++;
		}
		else if (maze[r][c - 1] == 1) {	// ←
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			c--; cnt++;
		}
		else if (maze[r - 1][c] == 1) {	// ↑
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r--; cnt++;
		}
		else if (maze[r - 1][c - 1] == 1) {	// ↖
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r--; c--; cnt++;
		}
		else {	// 움직일곳이 없을 때
			if (!empty(sRow)) { // 이전 위치로 돌아감 
				maze[r][c] = CHECK;
				r = pop(sRow);
				c = pop(sCol);
				cnt++;
			}
			else {
				printf("No route for Maze");
			}
		}
	}
}