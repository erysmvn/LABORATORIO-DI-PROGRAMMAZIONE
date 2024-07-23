#include <stdio.h>

int main(){
    int num;

    printf("inserisci un numero: ");
    scanf("%d", &num);

    for ( int i = 1; i <= num; i++){
        if ( num % i == 0){
            printf("%d è divisibile per [%d]\n", num, i);
        } 
    }

    return 0;
}