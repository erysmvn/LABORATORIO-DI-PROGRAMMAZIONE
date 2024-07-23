#include <stdio.h>

int main(){
    int num = 0;
    //unsigned int prod = 1;
    int prod = 1;

    while ( ((num < 1) || (num > 1000))){
        printf("inserisci un numero tra 1 e 1000: ");
        scanf("%d", &num);
    
        if ( (num < 1) || (num > 1000) ) {
            printf("\nvalore non valido\n");
        }
    }

    if (num % 2 == 0){
        num--;
    }

    for ( int i = num; i >= 3; i = i - 2 ){
        prod = prod * i;
    
        if (prod < 0){
            printf("\noverflow raggiunto");
            break;
        } else {
            printf("il prodotto tra i val dispari precedenti è [%d] \n", prod);
        }
    }

    return 0;
}