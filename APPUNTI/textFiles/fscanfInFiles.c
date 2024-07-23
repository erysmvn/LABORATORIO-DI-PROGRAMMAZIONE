#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char buffer[200] = { 0 } ;

int main(){
    FILE * fp = fopen("fscanfTry.txt", "r");

    if (fp == NULL)
        printf("FAILLL\n");

    int result = fscanf(fp, "%s", buffer);
    while (result != EOF){
        printf("%s\n", buffer);
        result = fscanf(fp, "%s", buffer);
    }

    fclose(fp);

    return 0;
}