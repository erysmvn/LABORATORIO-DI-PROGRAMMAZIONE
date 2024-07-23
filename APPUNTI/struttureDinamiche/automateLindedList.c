#include <stdio.h>
#include <stdlib.h>

#define NULL 0
struct Node *addNode(int data);
void print();

struct Node{
    int data;
    void * next;
};

struct Node * head = NULL;

int main(){
    int n;

    printf("tell me, how many nodes do you want?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        struct Node * new = addNode(i);
    }

    print();
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

void print(){
    struct Node * current = head;
    printf("\n");
    while (current != NULL){
        printf("| %d | -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}