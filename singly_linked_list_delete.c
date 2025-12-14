#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addEnd(int x) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeofstruct node));
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

void deleteFirst() {
    struct node *temp;
    if (head == NULL)
        return;

    temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL)
        return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deleteElement(int x) {
    struct node *temp, *prev;

    if (head == NULL)
        return;

    if (head->data == x) {
        deleteFirst();
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
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
    addEnd(40);

    deleteFirst();
    deleteElement(30);
    deleteLast();

    display();

    return 0;
}
