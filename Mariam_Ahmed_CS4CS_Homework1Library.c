#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include "Mariam_Ahmed_CS4CS_Homework1Library.h"


int main(void){
    char choice;
    do{
        show();
        puts("Enter your choice number: ");
        scanf(" %c", &choice);
        
        switch (choice){
            case '1':
                readline();
                break;
            case '2':
                countdigits();
                break;
            case '3':
                sum();
                break;
            case '4':
                countalpha();
                break;
            case '5':
                 mostrepeatedchar();
                break;
            case '6':
                mostrepeatednum();
                break;
            case '7':
               countalphanumeric();
                break;
            case 'q': case 'Q':
                break;
        }
    }while(choice!='q'&& choice!='Q');
    
    puts("program is terminated...\n\n");
    
    return 0;
}
