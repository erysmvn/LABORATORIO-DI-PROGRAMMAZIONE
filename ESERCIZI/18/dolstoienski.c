#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int main(){
    char book[2048];
    int countRow, countChar, countNumb, countWord;
    char end[5] = "FINE";
    int true = 1;
    
    countRow = 0;
    countChar = 0;
    countNumb = 0;
    countWord = 0;

    printf("Enter a string until \"FINE\": \n");

    while (true){
        gets(book);
        if (!(strcmp(book, end)))
            true = 0;
        countRow++;
    
        for (int i = 0; book[i] != '\0'; i++){
            if(isblank(book[i]))
                countWord++;
            else if (isdigit(book[i]))
                countNumb++;
            else if (isalpha(book[i]))
                countChar++;
        }
        
    }

    printf("Row = %d, Char = %d, Numb = %d, Word = %d\n", countRow, countChar, countNumb, countWord+countRow); 
}