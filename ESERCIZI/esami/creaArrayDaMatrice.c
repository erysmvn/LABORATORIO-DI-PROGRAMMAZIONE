#include <stdio.h>
#include <stdlib.h>

int creaArrayDaMatrice(int n, int matrix[][n], int array[]);

int main(){
    int n;

    printf("INSERISCI LA LUNGHEZZA DELLA MATRICE: ");
    scanf("%d", &n);

    int ** matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    int * array = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        array[i] = (int)malloc((n*n) * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = (rand() % 8) + 1;

    printf("MATRICE\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    int lenghtArr = creaArrayDaMatrice(n, *matrix, array);

    printf("ARRAY\n");
    for (int i = 0; i < lenghtArr; i++)
        printf("%d ", array[i]);
    printf("\n");
    
}

int creaArrayDaMatrice(int n, int matrix[][n], int array[]){ 
    int sumPrec = 0;
    int sumCurr = 0;
    int lenghtArr = 0;

    for (int i = 0; i < n; i++){   
        sumCurr = 0;
        for (int j = 0; j < n; j++)
            sumCurr += matrix[i][j];
        if (sumPrec > sumCurr || i == 0){
            for (int j = 0; j < n; j++)
                array[lenghtArr++] = matrix[i][j];
        }
        sumPrec = sumCurr;
    }
    return lenghtArr;
}