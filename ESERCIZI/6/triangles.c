#include <stdio.h>

int main(){
    int i, j, n = 5;
    
printf("\n");
// square
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

// in-square
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 || i == 4)
                printf("*");
            else if (j == 0 || j == 4)
                printf("*");
            else 
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
 
// triangle
    for (i = 0; i <= n; i++){
        for (j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
 
// triangle-square
    for (i = 0; i <= n; i++){
        for (j = 0; j < i; j++){
            printf("*");
        }
        if (i > 0){
            for (int k = 0; k < n-j; k++){
                printf("+");
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}