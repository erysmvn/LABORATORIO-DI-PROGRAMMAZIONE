#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;

    printf("inserisci la lunghezza delle righe: ");
    scanf("%d", &n);
    printf("inserisci la lunghezza delle colonne: ");
    scanf("%d", &m);

    int ** matrix = (int** )malloc( n * sizeof(int *) );
    matrix[0] = (int *)malloc( (n * m) * sizeof(int) );
    for (int i = 1; i < n; i++){
        matrix[i] = matrix[0] + (i * m);
    }

    printf("DYNAMIC-ALLOCATED MATRIX: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("| %d ", matrix[i][j]);
        }
        printf("| \n");
    }
    printf("\n");

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("insert row [%d] column [%d] value: ", i, j);
            scanf("%d", *(matrix + i) + j);
            //printf("%d\n", *(matrix + i) + j);
            //printf("%d\n", &matrix[i][j]);
        }
    }
    printf("\n");
    
    printf("MATRIX: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("| %d ", **(matrix + i) + j);
        }
        printf("| \n");
    }
/*
*/
}