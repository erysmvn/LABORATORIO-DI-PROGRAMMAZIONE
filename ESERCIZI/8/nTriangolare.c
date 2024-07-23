#include <stdio.h>

int main(){
    int num, count = 0;

    printf("inserisci il numero: ");
    scanf("%d", &num);
    
    int i = 0;

    while (count <= num){
        count += i;
        if (count == num){
            printf("%d è triangolare ed equivale alla somma dei primi {%d} numeri", num, i);
            break;
        }
        i++;
    }
    if (count > num){
        printf("%d NON è triangolare.", num);
    }
}