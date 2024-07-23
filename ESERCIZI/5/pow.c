#include <stdio.h>

int main(){
    int a, b;

    printf("inserisci il primo numero: ");
    scanf("%d", &a);

    int ris = a;

    printf("inserisci il secondo numero: ");
    scanf("%d", &b);

    for ( int i = 1; i < b; i++){
        ris *= a;
        
        if (ris < a){
            printf("overflow\n");
            break;
        }
    }
    if (ris > a){
        printf("%d^%d = [%d]", a, b, ris);
    }

    return 0;
}