#include <stdio.h>

int reverseArray(int array[], int n);

int main(){
    int n;

    printf("quanto deve essere grande l'array?: ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++){
        printf("dammi il valore %d: ", i+1);
        scanf("%d", &array[i]);
    }
    
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("| %d ", array[i]);
    printf("|\n");

    reverseArray(array, n);
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("| %d ", array[i]);
    printf("|\n");
    
}

int reverseArray(int array[], int n){
    int k = 0;
    int b[n];
    
    for (int i = n-1; i >= 0; i--){
        b[k] = array[i];
        k++;
    }
    for (int i = 0; i < n; i++)
        array[i] = b[i];
    
    return 0;
}