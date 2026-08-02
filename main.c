#include "hospital.h"

PATIENT *head = NULL;

int main()
{
    char choice;

    Load_data();

    while(1)
    {
        printf("\n------------HOSPITAL MANAGEMENT SYSTEM-------------\n");
       

        printf("\nA/a : Create Account\n");
        printf("B/b : Book Appointment\n");
        printf("P/p : Print Details\n");
        printf("F/f : Find Patient\n");
        printf("M/m : Modify Patient\n");
        printf("X/x : Delete Patient\n");
        printf("Q/q : Quit\n");

        printf("\nEnter Choice : ");
        scanf(" %c",&choice);

        switch(choice)
        {
            case 'A':
            case 'a':
                Create_account();
                break;

            case 'B':
            case 'b':
                Book_appointment();
                break;

            case 'P':
            case 'p':
                Print_all_patients();
                break;

            case 'F':
            case 'f':
                Search_patient();
                break;

            case 'M':
            case 'm':
                Modify_patient();
                break;

            case 'X':
            case 'x':
                Delete_patient();
                break;
		

            case 'Q':
            case 'q':
                printf("\nThank You...\n");
                return 0;

            default:
                printf("\nInvalid Choice\n");
        }
    }
}
