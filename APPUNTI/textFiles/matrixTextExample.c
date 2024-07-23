#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){
    int n = 4;
    int m = 5;

    FILE * fs = fopen("matrixFile.txt", "r");
    
    if(fs != NULL){
        fscanf(fs, "%d %d", n, m);
        int ** mat = (int **)malloc(n * sizeof(int *));
        int i, j;
        for (i = 0; i < n; i++)
            mat[i] = (int *)malloc(m * sizeof(int));
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++)
                fscanf(fs, "%d ", &mat[i][j]);
        }
        
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }

        fclose(fs);
    } 
    else
        printf("Errore nell'apertura del file di testo\n");
}