#include "hospital.h"

void Create_account()
{
    PATIENT *newnode, *temp;
    char ch;

    newnode = (PATIENT *)malloc(sizeof(PATIENT));

    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    printf("\n----------- CREATE ACCOUNT -----------\n");

    printf("Enter Account Number : ");
    scanf("%d",&newnode->account_no);

    /* Duplicate Account Check */
    temp = head;

    while(temp != NULL)
    {
        if(temp->account_no == newnode->account_no)
        {
            printf("\nThis Account Number Already Exists.\n");

            printf("\nDo you want to book an appointment? (Y/N) : ");
            scanf(" %c",&ch);

            free(newnode);

            if(ch=='Y' || ch=='y')
            {
                Book_appointment();
                return;
            }

            printf("\nDo you want to create another account? (Y/N) : ");
            scanf(" %c",&ch);

            if(ch=='Y' || ch=='y')
            {
                Create_account();
                return;
            }

            Return_menu();
            return;
        }

        temp = temp->next;
    }

    printf("Enter Name : ");
    scanf("%s",newnode->name);

    printf("Enter Age : ");
    scanf("%d",&newnode->age);

    printf("Enter Gender : ");
    scanf("%s",newnode->gender);

    printf("Enter Contact Number : ");
    scanf("%s",newnode->contact);

    printf("Enter Place : ");
    scanf("%s",newnode->place);

    strcpy(newnode->doctor,"-");
    strcpy(newnode->disease,"-");

    newnode->room_no = 0;
    newnode->admitted = 0;

    strcpy(newnode->join_date,"-");
    strcpy(newnode->discharge_date,"-");

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    Save_data();

    printf("\nAccount Created Successfully.\n");

    printf("\nDo you want to book an appointment? (Y/N) : ");
    scanf(" %c",&ch);

    if(ch=='Y' || ch=='y')
    {
        Book_appointment();
        return;
    }

    Return_menu();
}
