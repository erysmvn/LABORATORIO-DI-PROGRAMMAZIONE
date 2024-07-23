#include <stdio.h>
#include <math.h>

int main(){
    int num, size, count = 0;

    printf("inserisci un numero decimale: ");
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++){
        if (pow(2, i) < num){
            size = i;
            break;
        }
    }
    printf("%d\n", size);

    for (int i = size; i <= 0; i++){
        if (pow(2, i) <= num){
            num = num - pow(2, i);
            printf("1");
        }
        else {
            printf("0");
        }
    }

    return 0;
}