#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void menu();
void addStudent(char nameFile[], int matr, int vote);
void average(char nameFile[]);
void showAll(char nameFile[]);

struct Studente {
    int matricola;
    int voto;
};

char buffer[200] = { 0 } ;

int main(){
    int choice;
    int true = 1; // to enter the loop
    int matricola = 0; // to enter the loop
    int voto = 40; // to enter the loop
    char fileName[] = "register.txt";

    while (true){
        menu();
        printf("QUALE AZIONE VUOI SVOLGERE?: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            while (matricola < 1 || matricola > 999999){
                printf("inserisci la matricola: ");
                scanf("%d", &matricola);
            }
            while (voto < 18 || voto > 31){
                printf("inserisci il voto ottenuto (31 = 30L): ");
                scanf("%d", &voto);
            }
            addStudent(fileName, matricola, voto);
            matricola = 0;
            voto = 0;
            break;
        
        case 2:
            average(fileName);
            break;
        
        case 3:
            showAll(fileName);
            break;
        
        case 4:
            true = 0;
            break;
        
        default:
            printf("SCELTA NON VALIDA, RIPROVA\n");
            break;
        }
    }
}

void menu(){
    printf("\n");
    printf("1 -> AGGIUNGI UNO STUDENTE\n");
    printf("2 -> MOSTRA MEDIA DEI VOTI\n");
    printf("3 -> MOSTRA LISTA STUDENTI\n");
    printf("4 -> ESCI\n");
}

void addStudent(char nameFile[], int matr, int vote){
    struct Studente new;
    new.matricola = matr;
    new.voto = vote;

    FILE * pf = fopen(nameFile, "a");
    if (pf == NULL)
        printf("errore nell'apertura di %s\n", nameFile);
    else 
        fprintf(pf, "%d \t %d\n", new.matricola, new.voto);

    fclose(pf);
}

void average(char nameFile[]){
    FILE * pf = fopen(nameFile, "r");
    float num, matr, lines = 0;
    float avg = 0;
    
    if (pf == NULL)
        printf("errore nell'apertura di %s\n", nameFile);
    else{
        while (fscanf(pf, "%f %f", &matr, &num) != EOF){
            avg += num;
            lines++;
        }
        printf("\n \t MEDIA DEI VOTI: { %.2f }\n", (avg / lines));
    }
    fclose(pf);
}

void showAll(char nameFile[]){
    FILE * pf = fopen(nameFile, "r");
    
    if (pf == NULL)
        printf("errore nell'apertura di %s\n", nameFile);
    else{
        int result = fscanf(pf, "%s", buffer);
        while (result != EOF){
            printf("N.MATRICOLA = %s \t", buffer);
            result = fscanf(pf, "%s", buffer);
            printf("VOTO = %s\n", buffer);
            result = fscanf(pf, "%s", buffer);
        }
    }
    fclose(pf);
}
