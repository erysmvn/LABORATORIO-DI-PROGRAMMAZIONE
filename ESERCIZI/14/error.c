#include <stdio.h>

int * InizializzaArray(unsigned int N);

int main(){
    int n = 5;
    int *A = InizializzaArray(n);
    
    for (int i=0;i<n;++i){
        printf("l'elemento A[%d]: %d", i, A[i]);
    }
}

int * InizializzaArray(unsigned int N){
    if(N==0)
        return 0;
    int A[N];
    int i;
    return A;
}