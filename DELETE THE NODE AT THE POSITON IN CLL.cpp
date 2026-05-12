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

int main() {
    int pos, i;
    create();
    display();

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    struct node *temp = head, *prev;

    // CASE 1: Empty list
    if(head == NULL) {
        printf("List is empty\n");
    }

    // CASE 2: Delete first node
    else if(pos == 1) {
        if(head == tail) {
            free(head);
            head = tail = NULL;
        } else {
            temp = head;
            head = head->next;
            tail->next = head;
            free(temp);
        }
    }

    // CASE 3: Delete at middle or end
    else {
        for(i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;

            // position out of range
            if(temp == head) {
                printf("Invalid position\n");
                return 0;
            }
        }

        prev->next = temp->next;

        // if deleting last node
        if(temp == tail) {
            tail = prev;
        }

        free(temp);
    }

    printf("\nAfter deletion:\n");
    display();

    if(tail != NULL)
        printf("\nTail next (should be head): %d\n", tail->next->data);

    return 0;
}
