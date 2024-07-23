#include <stdio.h>
#include <stdlib.h>

struct Node *addNode(int data);
struct Node *removeNode(int data);
struct Node * searchDuplicates(int k, int n);
void print();

struct Node{
    int data;
    void * next;
};

struct Node * head = NULL;

int main(){
    int n, k, num;

    printf("tell me, how many nodes do you want?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        //printf("insert num: ");
        //scanf("%d", &num);
        //struct Node * new = addNode(num);
        struct Node * new = addNode((rand() % 6) + 1);
    }

    print();

    printf("insert k: ");
    scanf("%d", &k);

    if (k <= 1)
        printf("invalid value\n");
    else
        searchDuplicates(k, n);
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

struct Node * searchDuplicates(int k, int n){
    struct Node * current = head;
    struct Node * scroll = current->next;
    int counter = 1;
    int datiDaRimuovere[n];
    datiDaRimuovere[0] = 0;
    int lenght = 0;
    int dataToRemove;

    while (current->next != NULL){
        dataToRemove = current->data;
        while (scroll->next != NULL){
            if (scroll->data == dataToRemove)
                counter++;
            if (counter == k){
                datiDaRimuovere[lenght] = dataToRemove;
                lenght++;
                counter = 1;
            }
            scroll = scroll->next;
        }
        current = current->next;

        if (scroll->next == NULL && scroll->data == dataToRemove){
            counter++;
            if (counter == k){
                datiDaRimuovere[lenght] = dataToRemove;
                lenght++;
                counter = 1;
            }
        } else
            scroll = current->next;
    }

    for (int i = 0; i < lenght; i++){
        dataToRemove = datiDaRimuovere[i];
        do{
            removeNode(dataToRemove);
        } while (removeNode(dataToRemove) != NULL);    
    }
    return head;
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
        while (prox->data != data && prox->next != NULL){
            current = current->next;
            prox = prox->next;
        }
        if (prox->data == data){
            current->next = prox->next;
            free(prox);
        }
        if (prox->next == NULL && prox->data != data)
            return NULL;
    }
    return head;
}   