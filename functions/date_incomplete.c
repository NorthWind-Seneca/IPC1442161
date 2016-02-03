#include <stdio.h>

/**
* Retrieves an integer from console and validates it against min and max.
*
* min       minimum valid integer
* max       maximum valid integer
* use       whether to use min, max, both, or none, respectively 1, 2, 3, and 0
* returns a validated integer.
*/
int getInteger(int min, int max, int use)
{

}

/**
* Retrieves a date from the user, returning the value as a compound integer
* where year is x10000, month is x100, day is x1.
*/
int getDate()
{

}

/**
* Given a compound date, prints in format YYYY-MM-DD
*/
void printDate(int cmpDate)
{

}

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