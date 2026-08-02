#ifndef HOSPITAL_H
#define HOSPITAL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patient
{
    int account_no;

    char name[30];
    int age;
    char gender[10];
    char contact[15];
    char place[30];

    char doctor[30];
    char disease[30];

    int room_no;
    int admitted;

    char join_date[15];
    char discharge_date[15];

    struct patient *next;

}PATIENT;


/* Global Head Pointer */

extern PATIENT *head;


/* Function Prototypes */

void Create_account();
void Book_appointment();

void Print_all_patients();
void Print_specific_patient();
void Print_doctor_patients();
void Print_disease_patients();

void Search_patient();

void Modify_patient();

void Delete_patient();

void Save_data();

void Load_data();

void Return_menu();

#endif
