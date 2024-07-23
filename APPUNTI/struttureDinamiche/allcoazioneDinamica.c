#include <stdio.h>

struct point{
    float x;
    float y;
};

struct point * AllocaInizializzaPunto(){
    struct point * p = (struct point *)malloc(sizeof(struct point)); // allocazione dinamica
    if (p != NULL){
        printf("insert x: ");
        scanf("%f", &p->x);
        printf("insert y: ");
        scanf("%f", &p->y);
    }
    return p;
};
        
int main(){
    struct point * p = AllocaInizializzaPunto();
    if (p != NULL){
        printf("x = %.2f, y = %.2f", p->x, p->y);
    }
}