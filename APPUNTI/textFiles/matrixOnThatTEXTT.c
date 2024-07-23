#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void fillMatrix(int n, int m, int matrix[][m]);
void printMatrix(int n, int m, int matrix[][m]);

int main(){

    int n = 4;
    int m = 3;
    /*
    int ** matrix = (int** )malloc( n * sizeof(int *) );
    for (int i = 0; i < n; i++)
        matrix[i] = (int* )malloc( m * sizeof(int) );
    */

   int matrix[n][m];

    fillMatrix(n, m, matrix);

    printf("MATRICE DA SCRIVERE\n");
    printMatrix(n, m, matrix);

    FILE *filePointer = fopen("matrixFile.txt", "w");
    fprintf(filePointer, "MATRICE NxM:  n = %d ; m = %d\n", n, m); // scriviamo le dimensioni
    
    int fclose(FILE * filePointer);

    FILE *fileAppend = fopen("matrixFile.txt", "a");
    //fprintf(fileAppend, "MATRICE NxM:  n = %d ; m = %d\n", n, m); // scriviamo le dimensioni

    for (int i = 0; i < n; i++){   
        for (int j = 0; j < m; j++){
            fprintf(fileAppend, "| %d ", matrix[i][j]);
        }
        fprintf(fileAppend, "|\n");
    }

    int fclose(FILE * fileAppend);

    FILE * filePrint = fopen("matrixFile.txt", "r");
    
    char c;
    while ((c = fgetc(filePrint)) != EOF){
        printf("%c", c);
    }
    
    int fclose(FILE * filePrint);
}

void fillMatrix(int n, int m, int matrix[][m]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = (rand() % 9) + 1;
}

void printMatrix(int n, int m, int matrix[][m]){
    for (int i = 0; i < n; i++){   
        for (int j = 0; j < m; j++)
            printf("| %d ", matrix[i][j]);
        printf("|\n");
    }
}