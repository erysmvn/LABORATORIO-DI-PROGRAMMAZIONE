#include <stdio.h>

int main(){
    int a, b;

    printf("inserisci il primo numero: ");
    scanf("%d", &a);

    printf("inserisci il secondo numero: ");
    scanf("%d", &b);

    if (( a % b == 0 ) || ( b % a == 0 )){
        if ( a % b == 0 ){
            printf("%d e\' divisibile per %d.", a,b);
        }
        else if ( b % a == 0 ){
            printf("%d e\' divisibile per %d.", b,a);
        }
    } else {
        printf("nessuno dei due numeri e\' divisibile per l'altro.");
    }

    return 0;
}