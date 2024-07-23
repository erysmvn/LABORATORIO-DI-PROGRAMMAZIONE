#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 4;
    int m = 5;

    int ** A = (int** )malloc( n * sizeof(int *) );
    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc( m * sizeof(int) );

    free(A[0]); // prima l'elemento zero
    free(A); // poi l'array
}