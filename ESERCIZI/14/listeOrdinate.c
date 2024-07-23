#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//#define NULL 0

struct Node * addNode(int data);
void printList();
struct Node * addNode2(int data);
void printList2();
struct Node * sortList(struct Node * listHead);
struct Node * mergeLists(struct Node * listOne, struct Node * listTwo);

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = NULL;
struct Node * head2 = NULL;

int main(){
    int n;

    printf("quanto devono essere grandi le linked list?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        addNode((rand() % 20));
    
    for (int i = 0; i < n; i++)
        addNode2((rand() % 20));
    
    printf("\n LISTA 1: \n");
    printList();
    
    printf("\n LISTA 1 (ORDINATA) : \n");
    sortList(head);
    printList();
    
    printf("\n LISTA 2: \n");
    printList2();
    
    printf("\n LISTA 2 (ORDINATA) : \n");
    sortList(head2);
    printList2();

    printf("\n LISTA 3 : \n");
    mergeLists(head, head2);
    sortList(head);
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

struct Node * addNode2(int data){
    struct Node * new = NULL;

    if (head2 == NULL){
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        head2 = new;
        new->next = NULL;
    } else{
        new = malloc(sizeof(struct Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        new->next = head2;
        head2 = new;
    }
    return new;
}

void printList2(){
    struct Node * current = head2;
    
    while (current != NULL){
        printf("| %d | -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node * sortList(struct Node * listHead){
    struct Node * current = listHead;
    struct Node * scroll = current;
    int temp;

    while (current->next != NULL){
        scroll = current;
        while (scroll != NULL){
            if (current->data > scroll->data){
                temp = current->data;
                current->data = scroll->data;
                scroll->data = temp;
            } else{
                scroll = scroll->next;
            }
        }
        current = current->next;
    }
    return listHead;
}

struct Node * mergeLists(struct Node * listOne, struct Node * listTwo){
    struct Node * current = listOne;
    struct Node * newNext = listTwo;

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