#include <stdio.h>
#include <stdlib.h>

void printList();
void riempiLista(char fileName[]);
struct Node * insertNode(int data);
struct Node * inserimentoOrdinato(int data);

struct Node {
    int data;
    struct Node * next;
};

struct Node * head = NULL;

int main(){
    char fileName[] = "textList.txt";
    int data;
    //riempiLista(fileName);

    FILE * pf = fopen(fileName, "r");

    if (pf == NULL)
        printf("error\n");
    else{
        while (fscanf(pf, "%d", &data) != EOF){
            //inserimentoOrdinato(data);
            insertNode(data);
        }
    }
    /*
    for (int i = 0; i < 5; i++){
        printf("dammi un numero: ");
        scanf("%d", &data);
        inserimentoOrdinato(data);
    }
    */
    
    printList();
}

void riempiLista(char fileName[]){
    FILE * pf = fopen(fileName, "w");
    
    if (pf == NULL){
        printf("error\n");
        return;
    }

    int n, input;

    printf("quanti numeri vuoi inserire?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("inserisci un numero: ");
        scanf("%d", &input);
        fprintf(pf, "%d\n", input);
    }
    fclose(pf);
}

struct Node * inserimentoOrdinato(int data){
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *new = NULL;

    new = malloc(sizeof(struct Node));
    new->data = data;

    while(curr != NULL && curr->data <= data){
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL){
        new->next = head;
        head = new;
    }
    else{
        new->next = curr;
        prev->next = new;
    }

    return head;
}


struct Node * insertNode(int data){
    struct Node * new = NULL;
    struct Node * current = head;
    
    if (head == NULL || head->data >= data){
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        head = new;
        new->next = NULL;
    } else{
        while (current->data < data && current->next != NULL){
            current = current->next;
        }
        if (current->next == NULL){
            new = malloc(sizeof(struct Node));
            if (new == NULL)
                return NULL;
            new->data = data;
            current->next = new;
            new->next = NULL;
        }
        else if (current->data >= data){
            new = malloc(sizeof(struct Node));
            if (new == NULL)
                return NULL;
            new->data = data;
            new->next = current;
            current = new;
        }
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
