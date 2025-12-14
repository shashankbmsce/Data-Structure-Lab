#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void addEnd(struct node **head, int x) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void display(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct node **head) {
    struct node *prev = NULL, *curr = *head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void concatenate(struct node *head1, struct node *head2) {
    struct node *temp = head1;

    if (head1 == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
}

int main() {

    addEnd(&head1, 30);
    addEnd(&head1, 10);
    addEnd(&head1, 20);

    addEnd(&head2, 40);
    addEnd(&head2, 50);

    sortList(head1);
    reverseList(&head1);
    concatenate(head1, head2);

    display(head1);

    return 0;
}
