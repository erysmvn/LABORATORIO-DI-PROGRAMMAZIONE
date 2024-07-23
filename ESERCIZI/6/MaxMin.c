#include <stdio.h>
#include <math.h>

int main(){
    int n, max, min, i;
    

    printf("inserisci il numero di elementi: ");
    scanf("%d", &n);

    int str[n];
    
    for (i = 0; i < n; i++){
        printf("inserisci il numero in posizione [%d]: ", i);
        scanf("%d", &str[i]);
    }
    max = str[i-1];
    min = max;

    for (i = 0; i < n; i++){
        if (str[i] > max)
            max = str[i];
        else if (str[i] < min)
            min = str[i];
    }

    printf("il valore MASSIMO è {%d}, mentre il valore MINIMO è {%d}", max, min);

    return 0;
}