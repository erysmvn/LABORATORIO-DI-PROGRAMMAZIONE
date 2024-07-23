#include <stdio.h>

int * pointerToMax(int array[], int n);

int main(){
    int n;

    printf("quanto deve essere grande l'array?: ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++){
        printf("dammi il valore %d: ", i+1);
        scanf("%d", &array[i]);
    }

    int * pArray = &array[0];

    printf("{il tuo array risulta essere il seguente:} \n");
    for (int i = 0; i < n; i++)
        printf("| %d ", *(pArray+i));
    
    printf("|\n");

    int * pMaxArr = pointerToMax(array, n);
    printf(" *pMaxArr = %d \n", pMaxArr);
    printf(" &array[n-1] = %d \n", &array[n-1]);

}

int * pointerToMax(int array[], int n){
    return &array[n-1];
    /*
    int *pArr = &array[0];
    int *pMaxArr;
    n--;

    *pMaxArr = *(pArr+n);
    */

    //return pMaxArr;
}