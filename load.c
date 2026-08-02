#include "hospital.h"

void Load_data()
{
    FILE *fp;

    PATIENT *newnode, *temp;

    fp = fopen("patients.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Saved Data Found\n");
        return;
    }

    /* Clear old linked list */

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    while(1)
    {
        newnode = (PATIENT *)malloc(sizeof(PATIENT));

        if(newnode == NULL)
        {
            printf("Memory Allocation Failed\n");
            fclose(fp);
            return;
        }

        if(fscanf(fp,"%d %s %d %s %s %s %s %s %d %d %s %s",
                  &newnode->account_no,
                  newnode->name,
                  &newnode->age,
                  newnode->gender,
                  newnode->contact,
                  newnode->place,
                  newnode->doctor,
                  newnode->disease,
                  &newnode->room_no,
                  &newnode->admitted,
                  newnode->join_date,
                  newnode->discharge_date) != 12)
        {
            free(newnode);
            break;
        }

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
    }

    fclose(fp);
}
