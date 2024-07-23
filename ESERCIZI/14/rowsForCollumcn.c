#include <stdio.h>
#include <stdlib.h>

int* fillMatrix(int n, int matrix[][n]);
void printMatrix(int n, int matrix[][n]);
int rowCollumnsMultiplied(int n, int matrixA[][n], int matrixB[][n]);

int main(){
    int n;

    printf("quanto devono essere grandi le due matrici quadrate?: ");
    scanf("%d", &n);

    int matriceA[n][n];
    fillMatrix(n, matriceA);
    
    int matriceB[n][n];
    fillMatrix(n, matriceB);

    printf("MATRICE A: \n");
    printMatrix(n, matriceA);
    
    printf("MATRICE B: \n");
    printMatrix(n, matriceB);

    printf("MATRICE RIGHE x COLONNE: \n");
    rowCollumnsMultiplied(n, matriceA, matriceB);

}

int* fillMatrix(int n, int matrix[][n]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = (rand() % 9) + 1;
    return 0;
}

void printMatrix(int n, int matrix[][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("| %d ", matrix[i][j]);
        }
        printf("| \n");
    }
}

int rowCollumnsMultiplied(int n, int matrixA[][n], int matrixB[][n]){
    int sum = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                sum += matrixA[i][k] * matrixB[k][j];
            }
            printf("| %d ", sum);
            sum = 0;
        }
        printf("|\n");
    }
}