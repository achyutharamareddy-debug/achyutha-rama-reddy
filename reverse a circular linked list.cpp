#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// Create Circular Linked List
void create() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node *newnode;

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if(head == NULL) {
            head = tail = newnode;
            newnode->next = head;
        } else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }
}

// Display CLL
void display() {
    if(head == NULL) return;

    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(HEAD)\n");
}

// Reverse CLL
void reverse() {
    if(head == NULL) return;

    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode;

    do {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    } while(current != head);

    // Fix last node
    head->next = prev;

    // Swap head and tail
    current = head;
    head = tail;
    tail = current;
}

// Main function
int main() {
    create();

    printf("\nOriginal List:\n");
    display();

    reverse();

    printf("\nReversed List:\n");
    display();

    return 0;
}
