#include <stdio.h>
#include <stdlib.h>

#define NULL 0
struct Node *addNode(int data);
struct Node *addNode1(int data);
struct Node *mergeList();
struct Node *oddEvenSwap();
struct Node *removeDuplicates();
void print();
void print1();

struct Node{
    int data;
    void * next;
};

struct Node * head = NULL;
struct Node * head1 = NULL;

int main(){
    int n;

    printf("tell me, how many nodes do you want?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        struct Node * new = addNode((rand() % 20));
        struct Node * new1 = addNode1((rand() % 20));
    }
    printf("\nLISTA 1:\n");
    print();
    printf("\nLISTA 2:\n");
    print1();
    
    printf("\nLISTA 3:\n");
    mergeList();
    print();
    
    printf("\nLISTA 3 ( ORDINATA ):\n");
    oddEvenSwap();
    print();
    
    printf("\nLISTA 3 ( NO DUPLICATES ):\n");
    removeDuplicates();
    print();
    
    return 0;
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

struct Node *addNode1(int data){
    struct Node * new = NULL;

    if (head1 == NULL){
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        head1 = new;
        new->next = NULL;
    } else{
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        new->next = head1;
        head1 = new;
    }

    return new;
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

void print1(){
    struct Node * current = head1;
    printf("\n");
    while (current != NULL){
        printf("| %d | -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node *mergeList(){
    struct Node * current = head;
    struct Node * newNext = head1;

    while (current->next != NULL){
        current = current->next;
    }
    while (newNext != NULL){
        current->next = newNext;
        current = current->next;
        newNext = newNext->next;
    }
    return newNext;
}

struct Node *oddEvenSwap(){
    struct Node * current = head;
    struct Node * prox = current->next;
    int temp;

    while (current->next != NULL){
        if (current->data % 2 == 1){
            if (prox->data % 2 == 0){
                temp = current->data;
                current->data = prox->data;
                prox->data = temp;
            } else{
                if (prox->next != NULL)
                    prox = prox->next;
                else
                    return current;
            }
        } else{
            current = current->next;
            prox = current->next;
        }
    }
    return current;
}

struct Node *removeDuplicates(){
    struct Node * current = head;
    struct Node * scroll;
    struct Node * prox;
    int temp;

    while (current->next != NULL){
        temp = current->data;
        scroll = current;
        prox = current->next;
        
        while (prox->next != NULL){
            if (prox->data == temp){
                scroll->next = prox->next;  
                free(prox);
                prox = scroll->next;
            } else {
                scroll = scroll->next;
                prox = prox->next;
            }
        }
        current = current->next;
    }
    if ((prox->next == NULL) && ((prox->data == temp) || (prox->data == head->data))){
        current->next = NULL;
        free(prox);
    }
    return head;
}