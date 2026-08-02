#include "hospital.h"

void Modify_patient()
{
    PATIENT *temp;
    int account;

    if(head == NULL)
    {
        printf("\nNo Patient Records Found\n");
        return;
    }

    printf("\n----------- MODIFY PATIENT -----------\n");

    printf("Enter Account Number : ");
    scanf("%d",&account);

    temp = head;

    while(temp != NULL)
    {
        if(temp->account_no == account)
        {
            printf("\nPatient Found\n");

            printf("\nEnter New Name : ");
            scanf("%s",temp->name);

            printf("Enter Age : ");
            scanf("%d",&temp->age);

            printf("Enter Gender : ");
            scanf("%s",temp->gender);

            printf("Enter Contact Number : ");
            scanf("%s",temp->contact);

            printf("Enter Place : ");
            scanf("%s",temp->place);

            printf("Enter Doctor Name : ");
            scanf("%s",temp->doctor);

            printf("Enter Disease : ");
            scanf("%s",temp->disease);

            printf("Enter Room Number : ");
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

            printf("\nPatient Details Updated Successfully\n");

Save_data();

Return_menu();

return;
        }

        temp = temp->next;
    }

    printf("\nPatient Not Found\n");
    Save_data();
    Return_menu();
}
