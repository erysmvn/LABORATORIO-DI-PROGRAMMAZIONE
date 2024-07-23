#include <stdio.h>

int main(){
    float a;
    int b;

    printf("inserisci un numero reale: ");
    scanf("%f", &a);

    float base = a;

    printf("inserisci un numero intero: ");
    scanf("%d", &b);

    if (b == 0){
        a = 1;
    }

    for (int i = 1; i < b; i++){
        a *= base;
    }
    
    printf("il numero {%f} ** {%d} è {%f}", base, b, a);

    return 0;
}