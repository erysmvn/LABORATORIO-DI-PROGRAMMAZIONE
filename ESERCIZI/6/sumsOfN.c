#include <stdio.h>

int main(){
    int num, sum = 0;

    printf("inserisci un numero: ");
    scanf("%d", &num);

    while (num != 0){
        sum += (num % 10);
        num /= 10;
    };
    
    printf("la somma delle cifre è: {%d}", sum);

    return 0;
}