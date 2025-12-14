#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addFirst(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void addEnd(int x) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void addAtPos(int x, int pos) {
    int i;
    struct node *newnode, *temp;

    if (pos == 1) {
        addFirst(x);
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    addEnd(10);
    addEnd(20);
    addEnd(30);

    addFirst(5);

    addAtPos(15, 3);

    display();

    return 0;
}
