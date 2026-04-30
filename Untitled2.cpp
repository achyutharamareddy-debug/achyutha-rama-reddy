#include <stdio.h>
#include <stdlib.h>

/* ===== DOUBLY LINKED LIST ===== */

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void create(){
    int n, i;
    printf("enter no.of nodes: ");
    scanf("%d", &n);

    struct node *newnode;

    for(i = 0; i < n; i++){
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("enter data at node %d: ", i + 1);
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void display(){
    struct node *temp = head;

    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ===== CIRCULAR SINGLY LINKED LIST ===== */

struct node *chead = NULL, *ctail = NULL;   // reused same struct

void create_circular(){
    int n, i;
    printf("\nenter n size for circular list: ");
    scanf("%d", &n);

    struct node *newnode;

    for(i = 0; i < n; i++){
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("enter node %d data: ", i + 1);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(chead == NULL){
            chead = ctail = newnode;
            ctail->next = chead;
        }
        else{
            ctail->next = newnode;
            ctail = newnode;
            ctail->next = chead;
        }
    }
}

void display_circular(){
    if(chead == NULL){
        printf("Circular list empty\n");
        return;
    }

    struct node *temp = chead;

    printf("Circular list: ");
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != chead);

    printf("(head)\n");
}

/* ===== MAIN ===== */

int main(){
    create();
    display();

    // insert at first
    struct node *enode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the inserting data at first: ");
    scanf("%d", &enode->data);

    enode->prev = NULL;
    enode->next = head;

    if(head != NULL)
        head->prev = enode;
    else
        tail = enode;

    head = enode;
    display();

    // insert at end
    enode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the inserting data at end: ");
    scanf("%d", &enode->data);

    enode->next = NULL;
    enode->prev = tail;

    if(tail != NULL)
        tail->next = enode;
    else
        head = enode;

    tail = enode;
    display();

    // insert at position
    int pos, i;
    struct node *temp = head;

    printf("\nenter the position: ");
    scanf("%d", &pos);

    enode = (struct node *)malloc(sizeof(struct node));
    printf("enter the inserting data at position %d: ", pos);
    scanf("%d", &enode->data);

    if(pos == 1){
        enode->prev = NULL;
        enode->next = head;

        if(head != NULL)
            head->prev = enode;
        else
            tail = enode;

        head = enode;
    }
    else{
        for(i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }

        if(temp == NULL){
            printf("Invalid position\n");
        }
        else{
            enode->next = temp->next;
            enode->prev = temp;

            if(temp->next != NULL)
                temp->next->prev = enode;
            else
                tail = enode;

            temp->next = enode;
        }
    }
    display();

    // delete first
    if(head != NULL){
        temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        free(temp);
    }
    printf("\nafter deleting first: ");
    display();

    // delete last
    if(tail != NULL){
        temp = tail;
        tail = tail->prev;

        if(tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        free(temp);
    }
    printf("\nafter deleting last: ");
    display();

    // reverse
    struct node *currentnode = head, *nextnode;

    while(currentnode != NULL){
        nextnode = currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = nextnode;
        currentnode = nextnode;
    }

    temp = head;
    head = tail;
    tail = temp;

    printf("\nafter reversing: ");
    display();

    /* ===== Circular List Calls ===== */
    create_circular();
    display_circular();

    return 0;
}
