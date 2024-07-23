#include <stdio.h>

int main(){
    int i, j, n = 5;
    
printf("\n"); 
// triangle
    int count = 1;
    for (i = 0; i <= n; i++){
        for (j = 0; j < i; j++){
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}