#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printFile(char * fileName);
void transcribe(char * sourceFileName, char * destinationFileName);

int main(){
    FILE *pf = fopen("cheatCodes.txt", "w");

    fprintf(pf, "Spongebob Squarepants.\n");
    
    char fileName[] = "cheatCodes.txt";

    printFile(fileName);

    fclose(pf);
}

void printFile(char * fileName){
    FILE * filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
        printf("error");
    else {
        char c;
        while ((c = fgetc(filePointer)) != EOF){
            printf("%c", c);
        }

        fclose(filePointer);
    }
}

void transcribe(char * sourceFileName, char * destinationFileName){
    FILE * sourcePointer = fopen(sourceFileName, "r");
    FILE * destinationPointer = fopen(destinationFileName, "w");

    if (sourcePointer == NULL || destinationPointer == NULL)
        printf("error");
    else {
        char c;
        while ((c = fgetc(sourcePointer)) != EOF){
            fprintf(destinationPointer, "%c", c);
        }
        fclose(sourcePointer);
        fclose(destinationPointer);
    }
}