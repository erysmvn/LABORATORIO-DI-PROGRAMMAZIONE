#include <stdio.h>

void inc(int * a);

int main(){
    struct point{
        float x;
        float y;
    };
    
    struct rectangle{
        struct point p1;
        struct point p2;
    };
    
    struct rectangle r, * rp = &r;

// forme equivalenti di dire la stessa cosa
/*
    r.p1.x;
    rp->p1.x;
    (*rp).p1.x;
*/

    int a = 8;
    printf("%d\n", a);
    int * pa = &a;
    inc(pa);
    //inc(&a); equivalentemente
    printf("%d", a);
    
    const int * const pointer = &a; // Pointer costante a variabili costanti

    int b[5];
    int * pB = &b[0]; // ora questi due avranno la stessa funzione
    // pB = b è una forma equivalente di * pB = &b[0];
    *(pB + 3); // questo corrisponde a b[3]
    pB[3]; // anceh questa è una forma equivalente



}

void inc(int * a){
    *a = *a+1;
}