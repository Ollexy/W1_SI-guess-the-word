#include <stdio.h>
#include <conio.h>
#include <string.h>

void wordleMenu();
void checkLettersPossition(char codeWord[], char codeWordCheck[]);


int main()
{
	wordleMenu();

	int characterPosition = 0, lenght, attempts = 1, lifes = 7, length2;					
	char choice, codeWord[8], codeWordCheck[8], ch;

	choice = _getch();

	if (choice == '1')
	{
		system("cls");
		printf("Please enter code-word(max 7 letters): ");

		while (1)		
		{
			ch = _getch();
			if (ch == 13)
			{
				break;			//when user press "enter"
			}
			else if (ch == 8)
			{
				characterPosition--;
				codeWord[characterPosition] = '\0';			//when user press "backspace" its going back by 1 array
				printf("\b \b");
			}
			else if (ch == 32 || ch == 9)
			{
				continue;			//when user press space or tab ignore it
			}
			else
			{
				if (characterPosition < 7)
				{
					codeWord[characterPosition] = ch;
					characterPosition++;
					printf("*");
				}
				else
				{
					printf("Your input exceeds maximum code-word lenght.\n");
					break;
				}
			}
		}
		codeWord[characterPosition] = '\0';
		printf("\n");
		if (strlen(codeWord) == 0)
		{
			printf("No word entered");
		}
		else
		{
			lenght = strlen(codeWord);
			printf("Code-word lenght: %d\n\n", lenght);
		}
		while (lifes > 0)
		{
			printf("Try to guess: ");
			scanf_s("%s", codeWordCheck, 8);						
			if (strcmp(codeWord, codeWordCheck) == 0)
			{
				
				printf("GAME OVER. YOU WIN. You win in %d attempts\n", attempts);
				return 0;
			}
			else
			{
				//checkLettersPossition(codeWord, codeWordCheck);
				lifes--;
				printf("Wrong. %d lifes left\n", lifes);
			}
		}
		printf("GAME OVER. YOU LOSE");
	}
	return 0;
}
void wordleMenu()
{

	printf("  ------------------- \n");
	printf("|                     |\n");
	printf("| (1) Start the game  |\n");
	printf("|                     |\n");
	printf(" ---------------------\n\n");
}

void checkLettersPossition(char codeWord[], char codeWordCheck[]) {
	char emptyWord[8], goodLetters[8], badLetters[8];
	for (int i = 0; i < strlen(codeWord); i++) {
		int isFind = 0;
		if (codeWordCheck[i] == codeWord[i]) {
			emptyWord[i] = codeWordCheck[i];
			if (strchr(goodLetters, codeWordCheck[i]) != NULL) {
				for (int j = 0; j < strlen(codeWord); j++) {
					if (goodLetters[j] == codeWordCheck[i])
						goodLetters[j] = ' ';
				}
			}
			isFind = 1;
		}
		for (int j = 0; j < strlen(codeWord); j++)
			if ((codeWordCheck[i] == codeWord[j]) && (i != j) && (strchr(badLetters, codeWordCheck[i]) == NULL)) {
				//strncat_s(goodLetters, &codeWordCheck[i], 1);
				isFind = 1;
			}

		if ((isFind == 0) && (strchr(badLetters, codeWordCheck[i]) == NULL)) {
			//strncat_s(badLetters, &codeWordCheck[i], 1);
		}
			
	}
}
