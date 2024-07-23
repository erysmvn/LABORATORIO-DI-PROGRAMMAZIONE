#include <stdio.h>

#define max(a, b) ((a)>(b) ? (a): (b))

struct point{
    int x;
    int y;
};

typedef struct point p;

p idk;
idk.x = 4; idk.y = 5;


int main(){
    int a = 5;
    int b = 3;

    printf("%d\n", (a>b) ? a: b); // 5
    printf("%d\n", max(a, b)); // 5
/*  
if (a > b)
    max = a;
else
    max = b;
*/

#if (fausto = 1)
printf("mammt fausto");
#endif
    return 0;
}