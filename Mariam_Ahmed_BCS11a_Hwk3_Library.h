#ifndef Mariam_Ahmed_BCS11a_Hwk3_Library
#define Mariam_Ahmed_BCS11a_Hwk3_Library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Address{
    char street[20], city[20], country[20];
    int num;
}address;

typedef struct instructors{
    char title[20], first[10], last[10];
    int age;
    char gender;
    address *addressptr;
    struct instructors* next;
}instructors;

instructors* read(FILE* fptr, instructors* head);
instructors*  insert (instructors* head, instructors* newnode);
void print( instructors *head);
instructors* sort( instructors *head);


instructors* read(FILE* fptr, instructors* head) {
    while (1) {
    
        instructors* newnode = (instructors*)malloc(sizeof(instructors));
        newnode->addressptr = (address*)malloc(sizeof(address));

        if (fscanf(fptr, "%49[^,], %29[^,], %29[^,], %d, %c, %49[^,], %d, %29[^,], %29[^\n]",
                   newnode->title, newnode->first, newnode->last,
                   &newnode->age, &newnode->gender,
                   newnode->addressptr->street,
                   &newnode->addressptr->num,
                   newnode->addressptr->city,
                   newnode->addressptr->country) != 9) {
            free(newnode->addressptr);
            free(newnode);
            break;
        }
        newnode->next = NULL;
        head = insert(head, newnode);
    }
    return head;
}

instructors* insert(instructors* head, instructors* newnode) {
    if (head == NULL || strcmp(head->last, newnode->last) > 0) {
        newnode->next = head;
        head = newnode;
    } else {
        instructors* temp = head;
        while (temp->next != NULL && strcmp(temp->next->last, newnode->last) < 0) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

instructors* sort(instructors *head){
    if(head==NULL|| head->next== NULL){
        return head;
    }
    instructors* i,* j;
    for(i= head; i!=NULL; i= i->next){
        for(j= i->next;j!=NULL;j= j->next){
            if(strcmp(i->last, j->last)>0){
                instructors temp = *i;
                              strcpy(i->title, j->title);
                              strcpy(i->first, j->first);
                              strcpy(i->last, j->last);
                              i->age = j->age;
                              i->gender = j->gender;
                              strcpy(i->addressptr->street, j->addressptr->street);
                              i->addressptr->num = j->addressptr->num;
                              strcpy(i->addressptr->city, j->addressptr->city);
                              strcpy(i->addressptr->country, j->addressptr->country);

                              strcpy(j->title, temp.title);
                              strcpy(j->first, temp.first);
                              strcpy(j->last, temp.last);
                              j->age = temp.age;
                              j->gender = temp.gender;
                              strcpy(j->addressptr->street, temp.addressptr->street);
                              j->addressptr->num = temp.addressptr->num;
                              strcpy(j->addressptr->city, temp.addressptr->city);
                              strcpy(j->addressptr->country, temp.addressptr->country);
            }
            
        }
    }
    return head;
}

void print(instructors *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("%s %30s %-10s %-10s %-s %-s %-10s %-20s %-20s\n","Title:  ","First name: ", "Last name:", "Age:","Gender:  ", "Street name:", "Street Number: ","City: ", "Country:");

    for (instructors *temp = head; temp != NULL; temp = temp->next) {
        printf("%-30s %-10s %-10s %-5d %-5c %-20s %-10d %-30s %-20s\n",
               temp->title,
               temp->first,
               temp->last,
               temp->age,
               temp->gender,
               temp->addressptr->street,
               temp->addressptr->num,
               temp->addressptr->city,
               temp->addressptr->country);
    }
}

# endif
