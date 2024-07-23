#include <stdio.h>

void fibonacci(int n);

int main(){
    int num;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    fibonacci(num);

    return 0;
}

void fibonacci(int n){
    int sum, i = 0, f = 0, f1 = 1;
    
    do{
        printf("%d\n", f1);
        sum = f + f1;
        f = f1;
        f1 = sum;
        i++;
    } while (i < n);
}