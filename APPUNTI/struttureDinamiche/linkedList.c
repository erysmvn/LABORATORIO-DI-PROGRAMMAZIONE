#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct Node *addNode(int data);
struct Node *removeNode(int data);
struct Node *insertNode(int pos, int data);
struct Node *sortList();
void menu();
void print();

struct Node{
    int data;
    void * next;
};

struct Node * head = NULL;

int main(){
    int option = 0;
    int true = 1;
    int x, pos;
    while (true){
        menu();
        printf("\nwhat do you want to do?: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("what data do you want to insert?: ");
                scanf("%d", &x);
                struct Node *new = addNode(x);
                break;
            
            case 2:
                printf("what data do you want to remove?: ");
                scanf("%d", &x);
                removeNode(x);
                break;
            
            case 3:
                printf("what data do you want to insert?: ");
                scanf("%d", &x);
                printf("in which position?: ");
                scanf("%d", &pos);
                struct Node *newIn = insertNode(pos-1, x);
                break;
            
            case 4:
                print();
                break;
            
            case 5:
                sortList();
                break;

            case 6:
                true = 0;
                break;
            
            default:
                printf("\nwrong value\n");
        }
    }
}

void menu(){
    printf("you have the following options:\n");
    printf("\t 1 -> add a node to the list\n");
    printf("\t 2 -> remove a node into the list\n");
    printf("\t 3 -> insert a node into the list\n");
    printf("\t 4 -> print the list\n");
    printf("\t 5 -> sort list\n");
    printf("\t 6 -> exit\n");
}

void print(){
    struct Node * current = head;
    printf("\n");
    while (current != NULL){
        printf("| %d | -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node *addNode(int data){
    struct Node * new = NULL;

    if (head == NULL){
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        head = new;
        new->next = NULL;
    } else{
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        new->next = head;
        head = new;
    }

    return new;
}

struct Node *removeNode(int data){
    struct Node * current = head;
    struct Node * prox = current->next;
    if (current == NULL)
        return NULL;
    
    if (current->data == data) {
        head = current->next;
        current = head;
        prox = current->next;
    } else{
        while (prox->data != data){
            current = current->next;
            prox = prox->next;
        }
        if (prox->data == data){
            current->next = prox->next;
            free(prox);
        }
    }
}   

struct Node *insertNode(int pos, int data){
    struct Node * current = head;
    
    for (int i = 1; i < pos; i++)
        current = current->next;
    
    if (current == NULL)
        return NULL;

    struct Node * new = NULL;

    new = malloc(sizeof(struct Node));
    if (new == NULL)
        return NULL;    
    new->data = data;
    new->next = current->next;
    current->next = new;

    return new;
}

struct Node *sortList(){
    struct Node * current = head;
    struct Node * prox;
    int temp;
    int swapped;

    do{
    swapped = 0;
        while (current->next != NULL){
            prox = current->next;
            if (prox->data < current->data){
                temp = current->data;
                current->data = prox->data;
                prox->data = temp;
                swapped = 1;
            }
        current = current->next;
        }
    } while (swapped);
}