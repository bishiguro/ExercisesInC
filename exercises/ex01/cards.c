/* 
Card Counting Program, derived from HeadFirstC 
Bonnie Ishiguro
*/

#include <stdio.h>
#include <stdlib.h>

/* Prompts the user for a card name and puts the reply in the given buffer.

	card_name: buffer where the input is stored
*/
void card_input(char card_name[])
{
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}

/* Updates the card count depending on the value of the current card.
       
	val: the value of the current card
	count: the current card count
*/
void card_count(int val, int *count)
{
	if ((val > 2) && (val < 7)) {
		*count = *count + 1;
	} else if (val == 10) {
		*count = *count - 1;
	}
	printf("Current count: %i\n", *count);
}

/* Assigns a value to the current card. 
	
	card_name: the card name buffer
*/

int card_value(char card_name[]) 
{
	int val = 0;
	switch(card_name[0]) {
	case 'K':
	case 'Q':
	case 'J':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	case 'X':
		val = 0;
		break;
	default:
		val = atoi(card_name);
		if ((val < 1) || (val > 10)) {
			puts("I don't understand that value!");		
			val = -1;
			break;
		}
	}
	return val;
}

int main() 
{
	char card_name[3];
	int count = 0;
	do {
		card_input(card_name);
		
		int val = card_value(card_name);
		if (val == -1)
			continue;

		card_count(val, &count);

	} while (card_name[0] != 'X');	
	return 0;	
}