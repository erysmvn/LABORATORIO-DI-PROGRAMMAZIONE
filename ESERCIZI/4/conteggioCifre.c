#include <stdio.h>

int main(){
    int num, count = 0;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    do{
        count += 1;    
        printf("cifra %d = [%d]\n", count, (num % 10));
        num /= 10;
    } while ((num*10) / 10 != 0);
    
    printf("le cifre in totale sono %d", count);
}