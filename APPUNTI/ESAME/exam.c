#include <stdio.h>
#include <stdlib.h>

void menu();
void firstEx();
void secondEx();

void creaListaDaMatrice(int m, int matrix[][m]);
struct Node * addNode(int data);
void printList();

void creaArrayDaLista(int m);

struct Node {
    int data;
    struct Node * next;
};

struct Node * head = NULL;

int main(){
    int choice = 0;
    
    while (choice < 1 || choice > 3){
        menu();
        printf("COSA VUOI FARE?: ");
        scanf("%d", &choice);        
    
        switch (choice)
        {
        case 1:
            firstEx();
            break;
        
        case 2:
            secondEx();
            break;
        
        case 3:
            break;
        
        default:
            printf("\nSCELTA NON VALIDA\n");
            break;
        }
    }

    return 0;
}

void menu(){
    printf("1 -> ESERCIZIO 1\n");
    printf("2 -> ESERCIZIO 2\n");
    printf("3 -> ESCI\n");
}

void firstEx(){
    int m;

    printf("INSERISCI GRANDEZZA MATRICE: ");
    scanf("%d", &m);

    // alloco la matrice
    int ** matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        matrix[i] = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 9 + 1;
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++)
            printf("| %d ", matrix[i][j]);
        printf("|\n");
    }

    creaListaDaMatrice(m, *matrix);
    printList();

}

void creaListaDaMatrice(int m, int matrix[][m]){
    int check;

    for (int i = 1; i <= m; i++){
        check = 1;
        for (int j = 1; j <= m-1; j++){
            if (matrix[i][j] > matrix[i][j+1]){
                check = 0;
                j = m;
            }
        }
        if (check){
            for (int k = 1; k <= m; k++)
                addNode(matrix[i][k]);
        }
    }
}

struct Node * addNode(int data){
    struct Node * new = NULL;

    new = malloc(sizeof(struct Node));
    if (new == NULL)
        return NULL;
    
    new->data = data;
    if (head == NULL){
        head = new;
        new->next = NULL;
    } else{
        struct Node * current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
        new->next = NULL;
    }
    return new;
}

void printList(){
    struct Node * current = head;
        while (current != NULL){
            printf("| %d | -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
}


void secondEx(){
    int m;

    printf("INSERISCI GRANDEZZA LISTA: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        addNode((rand() % 9) + 1);
    
    printList();
    creaArrayDaLista(m);

}

void creaArrayDaLista(int m){
    int *array = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        array[i] = 0;

    struct Node * current = head;
    int check;
    int count = 0;

    while (current != NULL){
        check = 1;
        for (int i = 0; i < m; i++)
            if (array[i] == current->data)
                check = 0;
        if (check == 1){
            array[count] = current->data;
            count++;
        }
        current = current->next;
    }
    printf("ARRAY\n");
    for (int i = 0; i < count; i++)
        printf("| %d ", array[i]);
    printf("|\n");

}