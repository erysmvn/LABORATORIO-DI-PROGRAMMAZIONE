#include <stdio.h>

int main(){
    int num, i = 2;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    if (num < 2)
        printf("1 non è primo.\n");
    else{
        for (i = 2; i < num; i++){
            if ((num % i) == 0){
                printf("il numero non è primo.\n");
                break;
            }
        }
    }

    if (i == num)
        printf("il numero è primo.\n");


    return 0;
}
