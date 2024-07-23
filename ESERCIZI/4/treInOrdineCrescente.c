#include <stdio.h>

int main(){
    int a, b, c;

    printf("inserisci il primo numero: ");
    scanf("%d", &a);

    printf("inserisci il secondo numero: ");
    scanf("%d", &b);

    printf("inserisci il terzo numero: ");
    scanf("%d", &c);

    if ( a >= b && a >= c ){
        if ( b >= c ){
            printf("i numeri in ord. crescente sono: \n %d %d %d", a,b,c);
        } else{
            printf("i numeri in ord. crescente sono: \n %d %d %d", a,c,b);
        }
    } else if ( b >= a && b >= c ){
        if ( a >= c ){
            printf("i numeri in ord. crescente sono: \n %d %d %d", b,a,c);
        } else{
            printf("i numeri in ord. crescente sono: \n %d %d %d", b,c,a);
        }
    } else if ( c >= a && c >= b ){
        if ( a >= b ){
            printf("i numeri in ord. crescente sono: \n %d %d %d", c,a,b);
        } else{
            printf("i numeri in ord. crescente sono: \n %d %d %d", c,b,a);
        }
    }

    return 0;
}