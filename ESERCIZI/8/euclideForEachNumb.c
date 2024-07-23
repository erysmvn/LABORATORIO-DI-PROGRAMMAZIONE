#include <stdio.h>

int main(){
    int num, j;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    for (int i = 2; i <= num; i++){
        if ((num % i) == 0){
            j = 2;
            while ((i % j) != 0 && j <= i){
                j++;
            }
            if (j >= i) {
                printf("%d e\' divisibile per {%d} e questo è primo\n", num, i);
            }
        } 
    }
}