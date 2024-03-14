#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void printInterface(char *i, int gCount);

bool inArray(int *pairs, int i, int num)
{

	for (int j = 0; j < i; j++)
	{
		if (pairs[j] == num)
			return true;
	}

	return false;
}
int main()
{
	srand(time(0));							 // CARD DECLARATION
	int pairs[8] = {1, 2, 3, 4, 5, 6, 7, 8}; // 0-3; 4-7

	int choice1, choice12, choice2, choice22, guesses = 0;
	char yesNo = 'G';

	pairs[0] = rand() % 8;
	printf("%i: %i\n", 0, pairs[0]);
	for (int i = 1; i < 8;)
	{
		int num = rand() % 8;
		if (!inArray(pairs, i, num))
		{
			pairs[i] = num;
			i++;
		}
	}
	char guess[8];
	char numbers[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	char numbersOrg[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	char symbol[4] = {'%', '@', '$', '^'};
	for (int i = 0; i < 4; i++)
	{ // Declare symbols to cards
		guess[pairs[i]] = symbol[i];
		guess[pairs[4 + i]] = symbol[i];
	}
	system("mode 23, 20"); // INTERFACE
	do
	{
		printInterface(numbers, guesses);
		printf("   Choose first card:\n"); // FIRST CHOICE
		printf("           ");
		scanf("%i", &choice1);
		choice12 = choice1 - 1;
		if (choice1 < 1 || choice1 > 8)
		{ // FIRST INVALID CHOICE CHECK
			printf("    Invalid choice");
			Sleep(1000);
			system("cls");
		}
		else if (numbers[choice12] != numbersOrg[choice12])
		{
			printf("    Invalid choice");
			Sleep(1000);
			system("cls");
		}
		else
		{
			numbers[choice12] = guess[choice12];
			system("cls");
			printInterface(numbers, guesses);
			printf("  Choose second card:\n"); // SECOND CHOICE
			printf("           ");
			scanf("%i", &choice2);
			choice22 = choice2 - 1;
			if (choice2 < 1 || choice2 > 8)
			{ // SECOND INVALID CHOICE CHECK
				printf("    Invalid choice");
				Sleep(1000);
				system("cls");
				numbers[choice12] = numbersOrg[choice12];
			}
			else if(choice2 == choice1)
			{
				printf("    Invalid choice");
				guesses++;
				Sleep(1000);
				system("cls");
				numbers[choice12] = numbersOrg[choice12];
			}
			else if (numbers[choice22] != numbersOrg[choice22])
			{
				printf("    Invalid choice");
				Sleep(1000);
				system("cls");
				numbers[choice12] = numbersOrg[choice12];
			}
			else
			{
				numbers[choice22] = guess[choice22];
				system("cls");
				printInterface(numbers, guesses);
				if (guess[choice12] == guess[choice22])
				{
					printf("      Guessed it!\n");
					guesses++; // RIGHT OR WRONG CHECK
				}
				else
				{
					printf("         Wrong!\n");
					guesses++;
					numbers[choice12] = numbersOrg[choice12];
					numbers[choice22] = numbersOrg[choice22];
				}
				printf("     Press Enter...");
				getchar();
				getchar();
				system("cls");
			}
		}
		// CHECK IF FINSIHED
		if (numbers[0] != numbersOrg[0] && numbers[1] != numbersOrg[1] && numbers[2] != numbersOrg[2] && numbers[3] != numbersOrg[3] && numbers[4] != numbersOrg[4] && numbers[5] != numbersOrg[5] && numbers[6] != numbersOrg[6] && numbers[7] != numbersOrg[7])
		{
			printf("         PEXESO\n");
			printf("=======================\n\n\n\n\n\n");
			printf("        Victory!\n");
			printf("   Number of guesses:\n");
			printf("           %i\n\n", guesses);
			printf("   Enter to continue\n");
			getchar();
			getchar();
			system("cls");
			do
			{
				printf("         PEXESO\n");
				printf("=======================\n\n\n\n\n\n");
				printf("       Again?(Y/N)");
				yesNo = getchar();
				system("cls");
				if (yesNo == 'Y' || yesNo == 'y')
				{
					printf("         PEXESO\n");
					printf("=======================\n\n\n\n\n\n");
					printf("     Restarting...");
					Sleep(1500);
					system("cls");
					main();
				}
				if (yesNo == 'N' || yesNo == 'n')
				{
					printf("         PEXESO\n");
					printf("=======================\n\n\n\n\n\n");
					goto out;
				}
			} while (yesNo != 'Y' || yesNo != 'y' || yesNo != 'N' || yesNo != 'n');
		}
	} while (true);
out:
	printf("        Closing...");
	Sleep(1500);
	/**/
}

void printInterface(char *i, int gCount)
{
	printf("         PEXESO      %.2i\n", gCount);
	printf("=======================\n\n");
	printf(" ***   ***   ***   ***\n");
	printf(" *%c*   *%c*   *%c*   *%c*\n", i[0], i[1], i[2], i[3]);
	printf(" ***   ***   ***   ***\n\n");

	printf(" ***   ***   ***   ***\n");
	printf(" *%c*   *%c*   *%c*   *%c*\n", i[4], i[5], i[6], i[7]);
	printf(" ***   ***   ***   ***\n");
}
