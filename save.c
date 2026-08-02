#include "hospital.h"

void Save_data()
{
    FILE *fp;
    PATIENT *temp;

    if(head == NULL)
    {
        printf("\nNo Patient Records Found\n");
        return;
    }

    fp = fopen("patients.txt","w");

    if(fp == NULL)
    {
        printf("\nUnable to Open File\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp,"%d %s %d %s %s %s %s %s %d %d %s %s\n",
                temp->account_no,
                temp->name,
                temp->age,
                temp->gender,
                temp->contact,
                temp->place,
                temp->doctor,
                temp->disease,
                temp->room_no,
                temp->admitted,
                temp->join_date,
                temp->discharge_date);

        temp = temp->next;
    }

    fclose(fp);

    printf("\nData Saved Successfully\n");
}
