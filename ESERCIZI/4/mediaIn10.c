#include <stdio.h>

int main(){
    int num, i, sum = 0;

    for ( i = 0; i < 10; i++ ){
        printf("inserisci il %d* numero: ", i+1);
        scanf("%d", &num);

        sum += num;
    }

    printf("la media dei num inseriti e\' %d. ", ( sum / i ) );
    
    return 0;
}