#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// create sample list
void create() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node *newnode, *temp;

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

// display CLL
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

    struct node *enode, *temp;
    enode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter newly created node data: ");
    scanf("%d", &enode->data);

    int i, pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    // CASE 1: Empty list
    if(head == NULL) {
        head = tail = enode;
        enode->next = head;
    }

    // CASE 2: Insert at beginning
    else if(pos == 1) {
        enode->next = head;
        head = enode;
        tail->next = head;
    }

    // CASE 3: Insert at middle/end
    else {
        temp = head;

        for(i = 1; i < pos - 1; i++) {
            temp = temp->next;

            // position out of range
            if(temp == head) {
                printf("Position out of range\n");
                return 0;
            }
        }

        enode->next = temp->next;
        temp->next = enode;

        // if inserted at last ? update tail
        if(temp == tail) {
            tail = enode;
        }
    }

    printf("\nAfter inserting:\n");
    display();

    printf("\nTail next (should be head): %d\n", tail->next->data);

    return 0;
}
