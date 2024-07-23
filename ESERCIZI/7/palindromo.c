#include <stdio.h>
#include <math.h>

int reverseNum(int num);

int main(){
    int num;
    int reversedNumber;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    reversedNumber = reverseNum(num);

    if (reversedNumber == num)
        printf("%d: palindromo", reversedNumber);
    else
        printf("%d: NON palindromo", reversedNumber);

    return 0;
}

int reverseNum(int num){
    int count = 0;
    int reversedNumber = 0;
    int str = num;

    while (num != 0){
        num /= 10;
        count++;
    }
    count--;

    num = str;

    while (num != 0){
        reversedNumber += (num % 10) * pow(10, count);
        num /= 10;
        count--;
    }

    return reversedNumber;   
}