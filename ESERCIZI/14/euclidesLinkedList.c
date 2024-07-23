#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//#define NULL 0

struct Node * addNode(int data);
void printList();
int euclideValidate(int number);
struct Node * euclideList();

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

int main(){
    int n;

    printf("quanto deve essere grande la linked list?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        addNode((rand() % 20));
        
    printList();
    euclideList();
    printList();
}

struct Node * addNode(int data){
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

void printList(){
    struct Node * current = head;
    
    while (current != NULL){
        printf("| %d | -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int euclideValidate(int number){
    if ((number < 2) && (number > -2))
        return 0;
    for (int i = 2; i < number; i++)
        if ((number != i) && (number % i == 0))
            return 0;
    return 1;
}

struct Node * euclideList(){
    struct Node * current = head;
    struct Node * prev = NULL;

    while (current != NULL){
        if (!euclideValidate(current->data)){
            struct Node* temp = current;
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return head;
}
