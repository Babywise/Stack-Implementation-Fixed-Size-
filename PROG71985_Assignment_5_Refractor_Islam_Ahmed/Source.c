/* Written By:
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 *
 *    Date Started:		2020/11/18
 *    Date Completed:	2020/11/22
 *	  Refractor Date Started:		2020/12/18
 *    Refractor Date Completed:		2020/12/22
 *
 *	  Program Description:
 *
 *			This program uses a linked list to emulate a stack the same way a program made in assembly
 *          would. The program takes userinput and allocates the exact amount of memory needed for the
 *          inputted string and then adds them to the linked list (stack) one by one. For this representation
 *			position 1 in the linked list is the top of the stack, so when a character is added, the previous
 *			chracater is pushed down to the "next" item of the list and the current character is then place in
 *			position 1 (or top of the list).
 *			After all characters are added, the program pushs (prints) the top character in the list (stack) and
 *			then removes (pops) it from the list. This results in the inputted string to be outputted in reverse
 *			order.
 * 
 *	  Refractor Description:
 * 
 *			Same as previous description, however this iteration uses an array instead of a linked list
 *
 *    Revision History:
 *
 *			2020/11/18 - Created Program
 *					   - Added input.c/.h and added function to dynamically recieve user input
 *					   - Added Character.c/.h and functions to provide a structure for each character
 *					   - Added Word.c/.h to provide a structure containing a list for each character in Character.c/.h
 *					   - Started Stack implentation using linked links, Created StackADT and StackNode .c/.h
 *          2020/11/19 - Added basic functions to create nodes in StackNode.c
 *					   - Added functions to StackADT.c to add (push) nodes/characters to the linked list
 *					   - Added functions to Character.c and Word.c in order to get character data from structures
 *							without introducing direct access
 *			2020/11/20 - Added functions to StackADT.c and Word.c to remove (pop) nodes/characters from the linked list
 *			2020/11/21 - Fixed add(push) functions in StackADT to move the head correctly (keeping head at the top instead of bottom)
 *			2020/11/22 - Finished commenting
 * 
 *	   Refractory History:
 * 
 *			2020/12/05 - Created source.c using example from project refractor description
 *					   - Created struct for stack with a head and array
 *					   - Created functions create, push, pop and dispose
 *					   - Tested and fixed mishaps with pop
 *					   - finishing commenting
 *
 */
#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	Stack stack = createStack();

	//uncomment these if you would like to keep menu the same as given example
	//Warning, scanf will return an error if buffer is overflown, use scanf_s if 
	//you would like to avoid this issue

	//char inputBuffer[MAX_INPUT] = { 0 };
	printf("Please Enter a Word: ");
	//scanf("%[^\n]", &inputBuffer);

	//comment this out if you will use scanf
	//function return = userInput dynamically, must free after use
	char* inputBuffer = getUserInput();


	//push letters 1 by one onto the stack moving head each time
	int i = 0;
	while (inputBuffer[i] != '\0') {
		push(&stack, inputBuffer[i++]);
	}

	printf("\n");
	
	//pop letters off one by one starting from the last push character (head of stack)
	char ch;
	while (ch = pop(&stack)) {
		printf("%c", ch);
	}

	printf("\n");

	//free array in the stack
	disposeStack(&stack);
	//free dynamic userinput
	free(inputBuffer);

	return 0;

}