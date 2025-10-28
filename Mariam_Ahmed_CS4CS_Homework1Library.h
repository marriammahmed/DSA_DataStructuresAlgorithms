#ifndef Mariam_Ahmed_CS4CS_Homework1Library//.h
#define Mariam_Ahmed_CS4CS_Homework1Library//.h



char input[84];
void readline(void);
void readline(void){
    puts("enter a max of 84 characters: ");
    scanf(" %83[^\n]", input);
    puts("Your line has been read and saved...\n");

}

int countdigits(void);
int countdigits(void){
    readline();
    int num = 0;
       for (int i = 0; i < strlen(input); i++) {
           if (isdigit(input[i])) num++;
       }
    printf("The number of digits is: %d\n", num);
    return num;
    
}

int sum(void);
int sum(void){
    readline();
    int sum=0;
    for(int i=0; i<strlen(input); i++){
        if (isdigit(input[i]))
         sum+= input[i]-'0';
    }
    printf("The sum is: %d\n", sum);

    return sum;
}



int countalpha(void);
int countalpha(void){
    readline();
    int num= sizeof(input);
    int count=0;
    for(int i=0; i<num;i++){
        if(isalpha(input[i]))
            count++;
    }
    printf("Number of alpha characters: %d\n", count);
    return count;
}


char mostrepeatedchar(void);
char mostrepeatedchar(void){
    readline();
    int letters[26]={0};
    int max=0;
    char most='\0';
    for(int i=0;i<strlen(input);i++)
    {   char c= tolower(input[i]);
        if(isalpha(c)){
            letters[c-'a']++;
            if(letters[c-'a']> max){
                max = letters[c - 'a'];
                most= c;
            }
        }}
    printf("Most frequent character: %c\n", most);
    return most;
}



int mostrepeatednum(void);
int mostrepeatednum(void){
    readline();
    int nums[10]={0};
    int most=0;
    int max=0;
    for(int i=0;i<strlen(input);i++)
    {
        if(isdigit(input[i])){
            int digit=input[i]-'0';
            nums[digit]++;
            if(nums[digit]> max){
                max= nums[digit];
                most= digit;}
        }}
    printf("Most frequent digit: %d\n", most);
    return most;
}

int countalphanumeric(void);
int countalphanumeric(void){
    readline();
    int count=0;
    for(int i=0; i<strlen(input); i++){
        if(isalnum(input[i]))
        count++;
    }
    printf("Number of alphanumeric characters: %d\n", count);
    return count;
    
}


void show(void);
void show(void){
    printf("Menu\n1. Read a line (up to 84 characters long)\n2. Count number of the digits in the sentence\n3. Find the sum of digits in the sentence\n4. Count the number of alpha characters (a-z, A-Z) in the sentence\n5. Find the alpha character that is repeated the most\n6. Find the digit (0-9) that is repeated the most\n7. Count the number of alpha-numeric characters (a-z, A-Z, 0-9) in the sentence\n8. Terminate the program (use Q or q to exit)\n\n");
}



#endif
