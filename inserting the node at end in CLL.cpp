#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// Create initial list
void create() {
    int n, i, enode;
    struct node *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &enode);

        newnode->data = enode;

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
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

// Insert at end
int main() {
    create();
    display();

    struct node *enode;

    // Allocate memory
    enode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to insert at end: ");
    scanf("%d", &enode->data);

    // Case 1: Empty list
    if(head == NULL) {
        head = tail = enode;
        enode->next = head;
    }
    else {
        tail->next = enode;
        tail = enode;
        tail->next = head;
    }

    printf("\nAfter inserting:\n");
    display();

    printf("\nHead data (tail->next): %d\n", tail->next->data);

    return 0;
}
