/* Written By:
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 *
 * Function Description:
 *
 *		- functions to create a stack using malloc and
 *		- push a letter onto the stack and
 *		- pop a letter onto the stack and return the poped character
 *		- free the array in the stack so there are no memory leaks
 * 
 */
#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack createStack() {

	Stack stack;
	stack.head = -1;
	stack.stackArray = (char*)malloc(sizeof(char) * MAX_INPUT);
	memset(stack.stackArray, 0, sizeof(stack.stackArray));
	return stack;

}

void push(Stack* stack, char inputBuffer) {

	if (stack->head < MAX_INPUT - 1) {
		if (stack->head < 0) {
			stack->head = 0;
		} else {
			stack->head++;
		}

		stack->stackArray[stack->head] = inputBuffer;

	} else {
		printf("Stack size is too small, stack was overflown\n"
			"Please increase the stack size!\n");
		exit(EXIT_FAILURE);
	}

}

char pop(Stack* stack) {

	if (stack->head >= 0) {
		char headChar = stack->stackArray[stack->head];
		stack->stackArray[stack->head] = NULL;
		stack->head--;
		return headChar;
	}
	return NULL;
}

void disposeStack(Stack* stack) {

	free(stack->stackArray);

}
