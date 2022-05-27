#include <stdio.h>
#include <conio.h>
#include <string.h>

void wordleMenu();

int main()
{
	wordleMenu();

	int characterPosition = 0, lenght, result, attempts = 0, lifes = 7;					// w result zapisac czy porownanie stringow da 0
	char choice, codeWord[8], codeWordCheck[8], ch;

	choice = _getch();
	
	if (choice == '1')
	{
		system("cls");
		printf("Please enter code-word(max 7 letters): ");

		while (1)		//infinity loop
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
				if(characterPosition < 7)
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
		//while (lifes > 0)
		//{
			//printf("Try to guess: ");
			//scanf_s("");						//tu trzeba porownac string, ale jeszcze nie wiem jak
			//if ()
			//{
				//attempts++;
				//printf("GAME OVER. YOU WIN. You win in %d attempts", attempts);
			//}
			//else()
			//{
				//lifes--;
				//printf("Wrong. %d lifes left", lifes);
			//}
		//}
		//if (lifes == 0)
			//printf("GAME OVER. YOU LOSE");
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
