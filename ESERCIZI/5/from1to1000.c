#include <stdio.h>

int main(){
    int num = 1;
    int prod = 1;

    while ( ((num >= 1) && (num <= 1000))){
        printf("inserisci un numero tra 1 e 1000: ");
        scanf("%d", &num);
        prod = prod * num;
        if (prod >= num){
            printf("il prodotto tra i val inserisi è momentaneamente [%d] \n", prod);
        } else {
            printf("\noverflow raggiunto");
            break;
        }
    }
    if ( (num < 1) || (num > 1000) ) {
        printf("\nvalore non valido");
    }

    return 0;
}