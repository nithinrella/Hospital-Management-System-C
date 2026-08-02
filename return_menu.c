#include "hospital.h"

void Return_menu()
{
    char ch;

    printf("\nDo you want to return to Main Menu? (Y/N) : ");
    scanf(" %c",&ch);

    if(ch=='Y' || ch=='y')
    {
        return;
    }

    printf("\nThank You...\n");
    exit(0);
}
