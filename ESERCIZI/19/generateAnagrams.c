#include <stdio.h>
#include <string.h>

void generateAnagrams(char *str, int start, int end);
void swap(char *a, char *b);

int main() {
    char str[50];
    
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character

    int n = strlen(str);
    generateAnagrams(str, 0, n - 1);

    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generateAnagrams(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (int i = start; i <= end; i++) {
            
            swap((str + start), (str + i));
            generateAnagrams(str, start + 1, end);
            swap((str + start), (str + i)); // backtrack
        }
    }
}