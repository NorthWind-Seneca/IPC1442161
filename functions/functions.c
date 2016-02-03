#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
* Retrieves an integer from the user, performing range validation.
*
* min		minimum bound of validation range.
* max		maximum bound of validation range.
* rangeType	type of validation to perform.
*			0=no validation, 1=min only, 2=max only, 3=min and max.
*
* Returns validated integer.
*/
int getInteger(int min, int max, int rangeType);

/**
* Retrieves a date from the user, returning the value as a compound integer
* where year is x10000, month is x100, day is x1.
*/
int getDate();

/**
* Given a compound date, prints in format YYYY-MM-DD
*/
void printDate(int cmpDate);

int main()
{
	int choice, date1 = 0, date2 = 0, temp;

	printf("Welcome to date comparison program.\n");

	do
	{
		printf("\nPlease enter choice:\n");
		printf("0: Quit\n");
		printf("1: Enter date 1\n");
		printf("2: Enter date 2\n");
		printf("3: Show both dates\n");
		printf("4: Compare dates\n");
		choice = getInteger(0, 5, 3);

		switch (choice)
		{
		case 1:
			printf("Please enter date 1:\n");
			date1 = getDate();
			printf("Entered ");
			printDate(date1);
			printf("\n");
			break;
		case 2:
			printf("Please enter date 2:\n");
			date2 = getDate();
			printf("Entered ");
			printDate(date2);
			printf("\n");
			break;
		case 3:
			printf("Date 1: ");
			printDate(date1);
			printf("\nDate 2: ");
			printDate(date2);
			printf("\n");
			break;
		case 4:
			if (date1 == date2)
				printf("Dates equivalent.\n");
			else if (date1 < date2)
				printf("Date 1 is earlier.\n");
			else
				printf("Date 2 is earlier.\n");
			break;
		}
	} while (choice != 0);

	printf("Goodbye.\n");

	return 0;
}

int getInteger(int min, int max, int rangeType)
{
	int result, goodResult;
	do
	{
		scanf("%d", &result);
		goodResult = 1;

		// Test min
		if (rangeType == 1 || rangeType == 3)
		{
			goodResult = goodResult && result >= min;
		}

		// Test max
		if (rangeType == 2 || rangeType == 3)
		{
			goodResult = goodResult && result <= max;
		}

		if (!goodResult)
		{
			printf("Invalid input. Try again.\n");
		}
	} while (!goodResult);
	return result;
}

/**
* Retrieves a date from the user, returning the value as a compound integer
* where year is x10000, month is x100, day is x1.
*/
int getDate()
{
	int year, month, day;
	printf("Enter year: ");
	year = getInteger(0, 0, 1);
	printf("Enter month: ");
	month = getInteger(1, 12, 3);
	printf("Enter day: ");
	day = getInteger(1, 31, 3);

	return year * 10000 + month * 100 + day;
}

/**
* Given a compound date, prints in format YYYY-MM-DD
*/
void printDate(int date)
{
	int year, month, day;

	// Mod by 100 to retrieve first two digits ie day
	day = date % 100;

	// divide by 100 to remove first two digits (eg 513 / 10 -> 51, 51 / 10 -> 5)
	date /= 100;

	month = date % 100;
	date /= 100;

	year = date;

	// Note: in this printf, %04d prints an integer while taking up
	// at least 4 spaces and padding empty spaces with 0.
	printf("%04d-%02d-%02d", year, month, day);
}
