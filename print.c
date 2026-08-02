#include "hospital.h"

void Print_specific_patient();
void Print_doctor_patients();
void Print_disease_patients();

void Print_all_patients()
{
    PATIENT *temp;
    int choice;

    printf("\n----------- PRINT MENU -----------\n");
    printf("1. Print All Patients\n");
    printf("2. Print Specific Patient\n");
    printf("3. Print Doctor Patients\n");
    printf("4. Print Disease Patients\n");

    printf("\nEnter Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:

            if(head == NULL)
            {
                printf("\nNo Patient Records Found\n");
                Return_menu();
                return;
            }

            temp = head;

            while(temp != NULL)
            {
                printf("\n---------------------------------\n");

                printf("Account Number : %d\n",temp->account_no);
                printf("Name           : %s\n",temp->name);
                printf("Age            : %d\n",temp->age);
                printf("Gender         : %s\n",temp->gender);
                printf("Contact        : %s\n",temp->contact);
                printf("Place          : %s\n",temp->place);
                printf("Doctor         : %s\n",temp->doctor);
                printf("Disease        : %s\n",temp->disease);
                printf("Room Number    : %d\n",temp->room_no);
                printf("Admitted       : %d\n",temp->admitted);
                printf("Join Date      : %s\n",temp->join_date);
                printf("Discharge Date : %s\n",temp->discharge_date);

                temp = temp->next;
            }

            break;

        case 2:

            Print_specific_patient();
            break;

        case 3:

            Print_doctor_patients();
            break;

        case 4:

            Print_disease_patients();
            break;

        default:

            printf("\nInvalid Choice\n");
    }

    Return_menu();
}

/* Print Specific Patient */

void Print_specific_patient()
{
    PATIENT *temp;
    int account;

    printf("\nEnter Account Number : ");
    scanf("%d",&account);

    temp = head;

    while(temp != NULL)
    {
        if(temp->account_no == account)
        {
            printf("\n---------------------------------\n");

            printf("Account Number : %d\n",temp->account_no);
            printf("Name           : %s\n",temp->name);
            printf("Age            : %d\n",temp->age);
            printf("Gender         : %s\n",temp->gender);
            printf("Contact        : %s\n",temp->contact);
            printf("Place          : %s\n",temp->place);
            printf("Doctor         : %s\n",temp->doctor);
            printf("Disease        : %s\n",temp->disease);
            printf("Room Number    : %d\n",temp->room_no);
            printf("Admitted       : %d\n",temp->admitted);
            printf("Join Date      : %s\n",temp->join_date);
            printf("Discharge Date : %s\n",temp->discharge_date);

            printf("---------------------------------\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nPatient Not Found\n");
}

/* Print Doctor Patients */

void Print_doctor_patients()
{
    PATIENT *temp;
    char doctor[30];
    int found = 0;

    printf("\nEnter Doctor Name : ");
    scanf("%s",doctor);

    temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->doctor,doctor)==0)
        {
            printf("---------------------------------\n");
            printf("Account Number : %d\n",temp->account_no);
            printf("Name           : %s\n",temp->name);
            printf("Disease        : %s\n",temp->disease);
            printf("---------------------------------\n");

            found = 1;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nNo Patients Found\n");
    }
}

/* Print Disease Patients */

void Print_disease_patients()
{
    PATIENT *temp;
    char disease[30];
    int found = 0;

    printf("\nEnter Disease : ");
    scanf("%s",disease);

    temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->disease,disease)==0)
        {
            printf("---------------------------------\n");
            printf("Account Number : %d\n",temp->account_no);
            printf("Name           : %s\n",temp->name);
            printf("Doctor         : %s\n",temp->doctor);
            printf("---------------------------------\n");

            found = 1;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nNo Patients Found\n");
    }
}
