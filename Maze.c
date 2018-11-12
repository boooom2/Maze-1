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
 * 1. Cur�� goal�̶�� ���� ����, �ƴ϶�� ��� ����
 * 2. Cur���� ������ �Ʒ��� �̵��ϰ� ���� ��ġ�� stack�� �ִ´�.
 * 3. �̵��� �� ������ �Ʒ��� �̵��ϰ� ���� ��ġ�� stack�� �ִ´�.
 * 4. �̵��� �� ������ ���������� �̵��ϰ� ���� ��ġ�� stack�� �ִ´�.
 *		....(�� ������ ��� �ݺ�)....
 * 8���� ��� �̵��� �� �ִ� ���� ������ ���� ��ġ�� CHECK�� ����� ���� ��ġ�� pop
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

		if (maze[r + 1][c + 1] == 1) {		// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r++; c++; cnt++;
		}
		else if (maze[r + 1][c] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r++; cnt++;
		}
		else if (maze[r][c + 1] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			c++; cnt++;
		}
		else if (maze[r + 1][c - 1] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r++; c--; cnt++;
		}
		else if (maze[r - 1][c + 1] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r--; c++; cnt++;
		}
		else if (maze[r][c - 1] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			c--; cnt++;
		}
		else if (maze[r - 1][c] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r--; cnt++;
		}
		else if (maze[r - 1][c - 1] == 1) {	// ��
			push(sRow, r); push(sCol, c);
			maze[r][c] = CHECK;
			r--; c--; cnt++;
		}
		else {	// �����ϰ��� ���� ��
			if (!empty(sRow)) { // ���� ��ġ�� ���ư� 
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