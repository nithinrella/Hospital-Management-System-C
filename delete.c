#include "hospital.h"

void Delete_patient()
{
    PATIENT *temp, *prev;
    int account;

    if(head == NULL)
    {
        printf("\nNo Patient Records Found\n");
        Return_menu();
        return;
    }

    printf("\n----------- DELETE PATIENT -----------\n");

    printf("Enter Account Number : ");
    scanf("%d",&account);

    temp = head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->account_no == account)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nPatient Deleted Successfully\n");

            Save_data();

            Return_menu();

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nPatient Not Found\n");

    Return_menu();
}
