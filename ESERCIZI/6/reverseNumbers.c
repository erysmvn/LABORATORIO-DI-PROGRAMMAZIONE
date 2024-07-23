#include <stdio.h>
#include <math.h>

int main(){
    int num, count = 0;
    int reversedNum = 0;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    int str = num;

    while (num != 0){
        num /= 10;
        count++;
    }
    count--;

    num = str;

    while (num != 0){
        reversedNum += (num % 10) * pow(10, count);
        num /= 10;
        count--;
    }
    
    printf("il numero invertito è: {%d} ", reversedNum);
    

    return 0;
}