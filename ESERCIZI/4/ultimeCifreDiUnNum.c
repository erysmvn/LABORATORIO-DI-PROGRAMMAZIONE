#include <stdio.h>

int main(){
    int num;
    
    while (1) {
        printf("Inserisci un numero: ");
        if (scanf("%d", &num) != 1) {
            printf("Non è un valore intero positivo.\n");
            // Clear the input buffer to avoid infinite loop
            while (getchar() != '\n');
        } else {
            break; 
        }
    }
    printf("la penultima cifra di %d è {%d}\n", num, (( num / 10 ) % 10));
    printf("l'ultima cifra di %d è {%d} ", num, ( num % 10 ) );

    return 0;
}