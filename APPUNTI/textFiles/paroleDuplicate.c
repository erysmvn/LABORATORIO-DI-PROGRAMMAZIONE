#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char buffer[255] = { 0 } ;

int main() {
    FILE *input_file = fopen("parole.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL) {
        printf("Errore nell'apertura del file di input");
    }

    if (output_file == NULL) {
        printf("Errore nell'apertura del file di output");
    }

    else if (output_file != NULL && input_file != NULL){
        char line[MAX_LINE_LENGTH];
        char parole[MAX_WORDS_PER_LINE][MAX_WORD_LENGTH];

        while (fgets(line, sizeof(line), input_file)) {
            int word_count = 0;
            char *token = strtok(line, " \n");
            // Ignora il primo token (numero di parole)
            token = strtok(NULL, " \n");

            while (token != NULL) {
                strcpy(parole[word_count++], token);
                token = strtok(NULL, " \n");
            }

            if (!parole_duplicate(parole, word_count)) {
                fprintf(output_file, "%s", line);
            }
        }
    }
    fclose(input_file);
    fclose(output_file);


    return 0;
}