#include <stdio.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void add(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    cq[rear] = x;
}

void removeElement() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void show() {
    int i;
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    add(10);
    add(20);
    add(30);
    add(40);
    add(50);
    add(60);     

    show();

    removeElement();
    removeElement();
    show();

    removeElement();
    removeElement();
    removeElement();   

    return 0;
}
