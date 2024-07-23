#include <stdio.h>

int main(){
    int num;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    int square = num;

    for (int i = 1; i < num; i++)
        square += num;
    
    int cube = square;

    for (int i = num; i < square; i++)
        cube += num;
    
    printf("il quadrato di {%d} e\' {%d}\n", num, square);
    printf("il cubo di {%d} e\' {%d}\n", num, cube);
}