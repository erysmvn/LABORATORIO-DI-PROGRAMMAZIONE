#include <stdio.h>

int main(){
    int num, fatt = 1;

    printf("inserisci un numero: ");
    scanf("%d", &num);

    for ( int i = num; i > 1; i--){
        fatt = fatt * i;
        
        if (fatt < num){
            printf("overflow\n");
            break;
        }
    }
    if (fatt > num){
        printf("il fattoriale di %d! = [%d]\n", num, fatt);        
    }

    return 0;
}