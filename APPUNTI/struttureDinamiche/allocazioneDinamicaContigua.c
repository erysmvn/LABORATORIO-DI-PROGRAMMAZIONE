#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 4;
    int m = 5;

    int ** A = (int** )malloc( n * sizeof(int *) );
    
    A[0] = (int *)malloc( (n * m) * sizeof(int) );  

    for (int i = 1; i < n; i++)
        A[i] = A[0] + (i * m);
 
    for (int i = 0; i < n; i++)
        free(A[i]); // prima gli elementi
    free(A); // poi l'array
}