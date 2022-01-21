/* Written By:
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 *
 * Function Description:
 *
 *		- struct for the stack that includes an array of letters and head variable to indicate the head position 
 * 
 */
#pragma once
#define MAX_INPUT 50

typedef struct stack {

	int head;
	char* stackArray;

}Stack;

Stack createStack();
void push(Stack*, char);
char pop(Stack*);
void disposeStack(Stack*);