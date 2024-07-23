#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    //char * gets(char * s);
    char str[50];
    char upp, rev;
    int cha, i = 0;

    printf("Enter a string : ");
    gets(str);

    printf("you entered: %s \n", str);

    for (cha = 0; cha < str; cha++)
        if (str[cha] == '\0')
            break;
    printf("lenght: %d\n", cha);
   
    printf("\n reversed: ");
    for (cha; cha >= 0; cha--){
        rev = str[cha];
        putchar(rev);
    }

    printf("\n upper: ");
    while (str[i] != '\0') {
        upp = str[i];
        putchar(toupper(upp));
        i++;
    }

   //printf("upper string: %c \n", upp);

   int parole = 0;
    
    for (int i = 0; i < str; i++){
        if (str[i] == '\0')
            break;
        else if (isblank(str[i]))
            parole++;
    }
    printf("\n parole = %d \n", parole+1);
    
    for (int i = 0; i < str; i++){
        if (str[i] == '\0')
            break;
        else if (isblank(str[i]))
            parole++;
    }
}   