#include <stdio.h>

struct pointWithLink{
    float x; // coordinata x
    float y; // coordinata y
    struct pointWithLink * pPointer; // puntatore al punto successivo
}

struct Node{
    int data;
    struct Node * link;
}

int main(){
    struct pointWithLink point1, point2;

    point1.x = 2.4;
    point1.y = 1.2;
    point1.pPointer = &point2;
    
    point2.x = 3.7;
    point2.y = 1.3;
    point2.pPointer = NULL;
}