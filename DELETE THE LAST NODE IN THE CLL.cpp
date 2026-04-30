#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// create list
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
            newnode->next = head;
            tail = newnode;
        }
    }
}

// display list
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

    printf("(head)\n");
}

// main function
int main() {
    create();
    display();

    struct node *temp, *prev;

    // CASE 1: Empty list
    if(head == NULL) {
        printf("\nList is empty, nothing to delete\n");
    }

    // CASE 2: Only one node
    else if(head == tail) {
        temp = head;
        head = tail = NULL;
        free(temp);
    }

    // CASE 3: More than one node
    else {
        temp = head;

        // traverse to last node
        while(temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        tail = prev;
        free(temp);
    }

    printf("\nAfter deleting last node:\n");
    display();

    if(tail != NULL)
        printf("\nTail next (should be head): %d\n", tail->next->data);

    return 0;
}
