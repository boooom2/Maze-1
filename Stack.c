#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/* Stack Functions */
void stackInit(STACK *s) {
	s->top = -1;
}
bool empty(STACK *s) {
	if (s->top == -1)
		return true;
	else
		return false;
}
void push(STACK *s, int num) {
	s->top += 1;
	s->arr[s->top] = num;
}
int pop(STACK *s) {
	int topIdx;
	if (empty(s)) {
		printf("No Data in Stack");
		exit(-1);
	}
	topIdx = s->top;
	s->top -= 1;
	return s->arr[topIdx];
}