#include <stdio.h>
#include <stdlib.h>

void inc(int *num);

int main(){
    int data = 5;
    int* pointerData;
    
    pointerData = &data;

    printf("data: {%d}\n", data);
    printf("pointerData: {%d}\n", *pointerData);
    printf("data (new (value)): {%d}\n", data);
    inc(pointerData);
    printf("data (new (reference)): {%d}\n", data);

    int a = 2;
    int b = 4;
    int* pP;
    pP = &a;
    printf("pointer to: {%d}\n", *pP);
    pP--; // now pP is the pointer to the newxt value
    printf("pointer to: {%d}\n", *pP);
    

    return 0;
}

void inc(int *num){
    (*num)++;
}