#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 2;
    int iCount = 0;
    int jCount = 0;

    while ((n % 2) == 0){
        printf("inserisci la lunghezza della matrice quadrata (dispari): ");
        scanf("%d", &n);
        if ((n % 2) == 0)
            printf("valore non valido\n");
    }

    int ** matrix = (int** )malloc( n * sizeof(int *) );
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc( n * sizeof(int) );

    int ** newMatrix = (int** )malloc( n * sizeof(int *) );
    for (int i = 0; i < n; i++)
        newMatrix[i] = (int *)malloc( n * sizeof(int) );

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = (rand() % 99) + 1; // evitiamo ci siano zeri
        }
    }
    printf("\n");

    printf("MATRIX: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("| %d ", matrix[i][j]);
        }
        printf("| \n");
    }

    for (int i = 0; i < (n / 2); i++){
        for (int j = 0; j < (n / 2); j++){
            newMatrix[iCount][jCount] = matrix[i][j];
            jCount++;
        }
        iCount++;
    }
    
    for (int i = n-1; i > (n / 2); i--){
        for (int j = n-1; j > (n / 2); j--){
            newMatrix[iCount][jCount] = matrix[i][j];
            jCount++;
        }
        iCount++;
    }

    for (int i = n-1; i > (n / 2); i--){
        for (int j = 0; j < (n / 2); j++){
            newMatrix[iCount][jCount] = matrix[i][j];
            jCount++;
        }
        iCount++;
    }
    
    for (int i = 0; i < (n / 2); i++){
        for (int j = n-1; j > (n / 2); j--){
            newMatrix[iCount][jCount] = matrix[i][j];
            jCount++;
        }
        iCount++;
    }

    printf("ARRAY: \n");
    for (int i = 0; i < iCount; i++){ // cioè out of range
        for (int j = 0; j < jCount; j++)
            printf("| %d ", newMatrix[i][j]);
        printf("| \n");
    }
}
