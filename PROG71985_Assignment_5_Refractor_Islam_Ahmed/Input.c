/* Written By:
 *    Name:		Islam Ahmed
 *    Email:	Iahmed9886@conestogac.on.ca
 *    Course:	PROG71985 - Fall2020
 * 
 * Function Description:
 * 
 *		- Dynamically get user input 
 *		- function adapted from previous assignment submissions
 * 
 */
#include "Input.h"
#include <stdlib.h>
#include <string.h>

char* getUserInput() {

	int maxCount = sizeof(char);
	char* seatSelection = (char*)malloc(sizeof(char));
	memset(seatSelection, NULL, sizeof(char));

	if (seatSelection == NULL) {

		printf("Memory could not be allocated");
		exit(EXIT_FAILURE);

	} else {

		char ch = NULL;
		int i = 0;

		//Accept input until user hits enter
		while ((ch = getchar()) != '\n' && ch != NULL) {

			seatSelection[i] = ch;
			i++;

			//if i reaches maxCount reaches size of char, realloc + 1 char until entire word/sentence is "gotten" from getchar 
			if (i == maxCount) {

				maxCount++;
				seatSelection = (char*)realloc(seatSelection, maxCount * sizeof(char));

				if (seatSelection == NULL) {

					printf("Memory could not be re-allocated");
					exit(EXIT_FAILURE);

				}
			}
		}

		//replaces last char '\n' with NULL
		seatSelection[i] = NULL;

	}

	return seatSelection;

}
