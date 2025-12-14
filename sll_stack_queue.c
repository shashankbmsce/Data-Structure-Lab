#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *top = NULL;

void push(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    struct node *temp;
    if (top == NULL)
        return;

    temp = top;
    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

void dequeue() {
    struct node *temp;
    if (front == NULL)
        return;

    temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    push(10);
    push(20);
    push(30);
    pop();
    displayStack();
    enqueue(5);
    enqueue(15);
    enqueue(25);
    dequeue();
    displayQueue();

    return 0;
}
