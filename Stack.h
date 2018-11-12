#ifndef __STACK__H__
#define __STACK__H__

typedef enum { false, true } bool;

/* Stack for Backtracking */
typedef struct stack {
	int arr[10];
	int top;
}STACK;

/* Function Prototype */
void stackInit(STACK *s);
bool empty(STACK *s);
void push(STACK *s, int num);
int pop(STACK *s);

#endif