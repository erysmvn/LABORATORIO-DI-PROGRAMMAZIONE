#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char buffer[255] = { 0 } ;

int main(){
    int k, num;
    char fileName[] = "parole.txt";

    printf("INSERISCI {K}: ");
    scanf("%d", &k);

    FILE * pf = fopen(fileName, "r");

    if (pf == NULL)
        printf("\nerror\n");
    else {
        while (fscanf(pf, "%d", &num) != EOF){
            fscanf(pf, "%d", &num);
            if (k <= num){
                fgets(buffer, 255, pf);
                printf("%s\n", buffer);
            }
            else
                fgets(buffer, 255, pf);
        }
    }
}