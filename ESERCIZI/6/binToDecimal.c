#include <stdio.h>
#include <math.h>

int main(){
    int binSize, i = 0;
    int decimal = 0;

    printf("inserisci un numero binario: ");
    scanf("%d", &binSize);

    int binNum = binSize;

    while (binSize != 0){
        binSize /= 10;
        i++;
    }

    binSize = i;
    
    for (i = 0; i < binSize; i++){
        decimal += (binNum % 10) * pow(2, i);
        binNum /= 10;
    }

    printf("numero in decimale: {%d}", decimal);

    return 0;
}