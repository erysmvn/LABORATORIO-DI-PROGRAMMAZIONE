#include <stdio.h>

int main(){
    float array[3];
    float matrix[3][3] = {{2, 4.2, 5.3}, {1.5, 3.2, 2}, {2.2, 13.4, 2.7}};
    float sum;

    for (int i = 0; i < 3; i++){
        sum = 0;
        for (int j = 0; j < 3; j++)
            sum += matrix[i][j];
        array[i] = sum;
    }

    printf("\n");
    for (int i = 0; i < 3; i++)
        printf("| %.2f ", array[i]);
    printf("|\n");
}