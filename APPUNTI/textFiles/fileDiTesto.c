#include <stdio.h>

int main() {
    int num = 3;
//  forme equivalenti
    printf("the number is %d\n", num);
    fprintf(stdin, "the number is %d\n", num);

//  per char
    char c = "k";
    fputc(c, stdout);

//  per stringhe
    char s[] = "hello world";
    fputs(s, stdout);

    int value;
//  forme equivalenti
    scanf("%d", &num);
    fscanf(stdin, "%d", &value);

//  get char
    char letter = fgetc(stdin);
    printf("%c", letter);

//  get string
    char poem[30];
    fgets(poem, 30, stdin);
    printf("%s", poem);
}