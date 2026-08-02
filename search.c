#include "hospital.h"

void Search_patient()
{
    PATIENT *temp;
    int account;

    if(head == NULL)
    {
        printf("\nNo Patient Records Found\n");

        Return_menu();
        return;
    }

    printf("\n----------- SEARCH PATIENT -----------\n");

    printf("Enter Account Number : ");
    scanf("%d",&account);

    temp = head;

    while(temp != NULL)
    {
        if(temp->account_no == account)
        {
            printf("\n-----------Patient Found------------\n");

   

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

            Return_menu();
            return;
        }

        temp = temp->next;
    }

    printf("\nPatient Not Found\n");

    Return_menu();
}
