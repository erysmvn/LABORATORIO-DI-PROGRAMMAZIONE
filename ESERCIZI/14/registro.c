#include <stdio.h>
#include <string.h>

struct student{
    char surname[12];
    float worstRating;
    float betterRating;
    float averageRating;
};

int main(){
    int choice;
    int true = 1;
    int index, max = 18;
    char wanted[12];

    struct student Luigi;
        strcpy(Luigi.surname, "Rossi");
        Luigi.worstRating = 18;
        Luigi.betterRating = 28;
        Luigi.averageRating = 23;

    struct student Fulvio;
        strcpy(Fulvio.surname, "Coppola");
        Fulvio.worstRating = 30;
        Fulvio.betterRating = 30;
        Fulvio.averageRating = 30;

    struct student Minecraft;
        strcpy(Minecraft.surname, "Herobrine");
        Minecraft.worstRating = 18;
        Minecraft.betterRating = 21;
        Minecraft.averageRating = 19.5;

    struct student Reg[]= {Luigi, Fulvio, Minecraft};
    
    while(true){
        printf("1 -> mostrami tutti gli studenti\n");
        printf("2 -> cerca uno studente per cognome\n");
        printf("3 -> mostrami lo studente con la media più alta\n");
        printf("4 -> esci\n");
        printf("che operazione vuole svolgere?: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                for(int i = 0; i < sizeof(Reg)/sizeof(Reg[0]); i++)
                    printf("Cognome: {%-2s}\t, Peggior Voto: {%.2f}, Miglior Voto: {%.2f}, Voto Medio: {%.2f}\n", Reg[i].surname, Reg[i].worstRating, Reg[i].betterRating, Reg[i].averageRating);
                break;
            
            case 2:
                printf("scrivi il Cognome della persona da cercare: ");
                scanf("%s", wanted);
                for(int i = 0; i < sizeof(Reg)/sizeof(Reg[0]); i++){
                    if (!strcmp(Reg[i].surname, wanted))
                        printf("Cognome: {%-2s}\t, Peggior Voto: {%.2f}, Miglior Voto: {%.2f}, Voto Medio: {%.2f}\n", Reg[i].surname, Reg[i].worstRating, Reg[i].betterRating, Reg[i].averageRating);
                }
                break;
            
            case 3:
                for(int i = 0; i < sizeof(Reg)/sizeof(Reg[0]); i++){   
                    if (Reg[i].averageRating > max){
                        max = Reg[i].averageRating;
                        index = i;
                    }
                }
                printf("Cognome: {%-2s}\t, Peggior Voto: {%.2f}, Miglior Voto: {%.2f}, Voto Medio: {%.2f}\n", Reg[index].surname, Reg[index].worstRating, Reg[index].betterRating, Reg[index].averageRating);
                break;
            
            case 4:
                printf("\n{uscita dal programma}");
                true = 0;
                break;
            
            default:
                printf("\nvalore non valido\n");
                break;
        }
    }
}