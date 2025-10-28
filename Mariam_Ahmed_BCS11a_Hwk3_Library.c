# include "Mariam_Ahmed_BCS11a_Hwk3_Library.h"

int main(void){
    FILE *fptr;
    instructors *head=NULL;
    if((fptr=fopen("/Users/marriamhatem/Desktop/Mariam_Ahmed_BCS11a_Hwk3/Mariam_Ahmed_BCS11a_Hwk3/BCS11a_Hwk3_Instructors.txt","r")) == NULL){
        puts("File failed to open...");
        return 1;
    }
    else
        puts("File successfully opened...\n");
    head= read (fptr, head);
    fclose(fptr);
    head= sort(head);
    print(head);
  
    instructors* temp;
    while(head!=NULL){
        temp= head;
        head= head->next;
        free(temp->addressptr);
        free(temp);
    }
    return 0;
}



