#include <stdio.h>
#include <ctype.h>
#include <strings.h>

int anagrammiStrings(int n, char str[n], char check[n]);

int main(){
    int n = 50;
    int str[n];
    
    printf("Enter a string : \n");
    fgets(str, n, stdin);

    anagrammiStrings(n, str, str);

    return 0;
}

int anagrammiStrings(int n, char str[n], char check[n]){
    char anagram[n];

    for (int i = 0; str[i] != '\0'; i++){
        if (isblank(str[i])){
            for (int j = i+1; (str[j] != ' ') && (str[j] != '\0'); j++)
                fgets(anagram, n, stdin);
            for (int j = i; (str[j] != ' ') && (str[j] != '\0'); j--)
                fgets(anagram, n, stdin);
        }
    }
    if ((strcmp(anagram, check))){
        printf("possibile anagramma: %s\n", anagram);
        anagrammiStrings(n, anagram, check);
    }
    return 0;
}