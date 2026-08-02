#include "hospital.h"

void Book_appointment()
{
    PATIENT *temp;
    int account;
    char ch;

START:

    /* If no patients exist */
    if(head == NULL)
    {
        printf("\nNo Patient Records Found.\n");

        printf("\nDo you want to create a new account? (Y/N) : ");
        scanf(" %c",&ch);

        if(ch=='Y' || ch=='y')
        {
            Create_account();
            return;
        }
        else
        {
            Return_menu();
            return;
        }
    }

    printf("\n----------- BOOK APPOINTMENT -----------\n");

    printf("Enter Account Number : ");
    scanf("%d",&account);

    temp = head;

    /* Search Patient */
    while(temp != NULL)
    {
        if(temp->account_no == account)
        {
            printf("\nPatient Found\n");

            printf("Doctor Name : ");
            scanf("%s",temp->doctor);

            printf("Disease : ");
            scanf("%s",temp->disease);

            printf("Room Number : ");
            scanf("%d",&temp->room_no);

            printf("Admitted (1=YES 0=NO) : ");
            scanf("%d",&temp->admitted);

            if(temp->admitted == 1)
            {
                printf("Joining Date : ");
                scanf("%s",temp->join_date);

                printf("Discharge Date : ");
                scanf("%s",temp->discharge_date);
            }
            else
            {
                strcpy(temp->join_date,"-");
                strcpy(temp->discharge_date,"-");
            }

            printf("\nAppointment Booked Successfully\n");

            Save_data();

            Return_menu();

            return;
        }

        temp = temp->next;
    }

    /* Patient not found */
    printf("\nPatient Not Registered.\n");

    printf("\nDo you want to register this patient? (Y/N) : ");
    scanf(" %c",&ch);

    if(ch=='Y' || ch=='y')
    {
        Create_account();
        return;
    }
    else
    {
        printf("\nThank You...\n");

        Return_menu();
        return;
    }
}
