#include <stdio.h>

int main(){
    int num;

    printf("inserisci un numero: ");
    scanf("%d", &num);

    do{
        printf("[%d]\n", (num % 10));
        num /= 10;
    } while ( ( ( num * 10 ) / 10 ) != 0 );
    
    

    return 0;
}