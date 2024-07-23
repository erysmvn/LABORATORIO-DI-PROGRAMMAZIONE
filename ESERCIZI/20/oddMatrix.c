#include <stdio.h>
#include <stdlib.h>

int validate(int n, int matrix[][n], int max);
int stampaSottoMatrici(int n, int matrix[][n], int m);

int main(){
    int n = 2;
    int count = 0;

    while ((n % 2) == 0){
        printf("inserisci la lunghezza della matrice quadrata (dispari): ");
        scanf("%d", &n);
        if ((n % 2) == 0)
            printf("valore non valido\n");
    }

    int ** matrix = (int** )malloc( n * sizeof(int *) );
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc( n * sizeof(int) );

    int * vector = (int *)malloc( n * sizeof(int) );

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
            vector[count] = matrix[i][j];
            count++;
        }
    }
    
    for (int i = n-1; i > (n / 2); i--){
        for (int j = n-1; j > (n / 2); j--){
            vector[count] = matrix[i][j];
            count++;
        }
    }

    for (int i = n-1; i > (n / 2); i--){
        for (int j = 0; j < (n / 2); j++){
            vector[count] = matrix[i][j];
            count++;
        }
    }
    
    for (int i = 0; i < (n / 2); i++){
        for (int j = n-1; j > (n / 2); j--){
            vector[count] = matrix[i][j];
            count++;
        }
    }

    printf("ARRAY: \n");
    for (int i = 0; vector[i] != 0; i++){ // cioè out of range
        if (i == n / 2)
            printf("|");
        printf("| %d ", vector[i]);
    }
    printf("| \n");

    int k;
    printf("inserisci un numero k: ");
    scanf("%d", &k);

    if (validate(n, *matrix, k))
        printf("la matrice contine i valori da 0 a %d\n", k);
    else
        printf("esiste numero n > k\n");

    int m;
    printf("inserisci un numero m, grandezza sottomatrice: ");
    scanf("%d", &m);

    stampaSottoMatrici(n, *matrix, m);

    return 0;
}

int validate(int n, int matrix[][n], int max){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] > max)
                return 0;
    return 1;
}

int stampaSottoMatrici(int n, int matrix[][n], int m) {

    if (m > n) {
        printf("Dimensione della sotto-matrice non valida.\n");
        return -1; // Errore
    }

    int ** newMatrix = (int **)malloc( m * sizeof(int *) );
    for (int i = 0; i < m; i++)
        newMatrix[i] = (int *)malloc( m * sizeof(int) );
 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++)
            newMatrix[i][j] = matrix[i][j];
    }
 
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++)
            printf("| %d ", newMatrix[i][j]);
        printf("| \n");
    }
}