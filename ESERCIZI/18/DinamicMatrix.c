#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;

    printf("inserisci la lunghezza delle righe: ");
    scanf("%d", &n);
    printf("inserisci la lunghezza delle colonne: ");
    scanf("%d", &m);

    int ** matrix = (int** )malloc( n * sizeof(int *) );
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc( m * sizeof(int) );

    /*
    printf("sizeof(int *): %lu\n", sizeof(int *));
    printf("sizeof(int): %lu\n", sizeof(int));
    
    printf("n * sizeof(int *): %lu\n", n * sizeof(int *));
    printf("m * sizeof(int): %lu\n", m * sizeof(int));
    
    printf("(int** )( n * sizeof(int *)): %lu\n", (int** )( n * sizeof(int *)));
    printf("(int *)(m * sizeof(int)): %lu\n", (int *) (m * sizeof(int)));
    
    printf("** matrix: %d\n", ** matrix);
    */

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
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
    
    printf("MATRIX: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("| %d ", matrix[i][j]);
        }
        printf("| \n");
    }
}