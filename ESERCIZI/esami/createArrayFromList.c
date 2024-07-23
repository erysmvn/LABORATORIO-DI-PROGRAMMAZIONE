#include <stdio.h>
#include <stdlib.h>

void printList();
int countList();
struct Node * addNode(int data);
int * creaArray(int k, int n);

struct Node {
    int data;
    struct Node * next;
};

struct Node * head = NULL;

int main(){
    int k;

    for (int i = 0; i < 5; i++){
        addNode((rand() % 8) + 1);
    }
    printf("\n\t\t LISTA: \n");
    printList();

    printf("\ninserisci valore k: ");
    scanf("%d", &k);
    
    int n = countList();

    int * array = creaArray(k, n);

    printf("\n\t ARRAY (ORDINATO PER K): \n");
    for (int i = 1; i <= n; i++) // array[0] is a pointer
        printf("| %d ", array[i]);
    printf("|\n");

}

void printList(){
    struct Node * current = head;

    while (current != NULL){
        printf("| %d | -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int countList(){
    struct Node * current = head;
    int count = 0;

    while (current != NULL){
        current = current->next;
        count++;
    }
    return count;
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

int * creaArray(int k, int n){
    int * array = (int *)malloc(n * sizeof(int));   
    
    struct Node * current = head;
    struct Node * currK = head;
    int count = 1;
    int value;

    while (current != NULL){
        value = current->data;
        if(value < k){
            array[count] = value;
            count++;
        }
        current = current->next;
    }

    while (currK != NULL){
        value = currK->data;
        if(value >= k){
            array[count] = value;
            count++;
        }
        currK = currK->next;
    }

    return array;
}