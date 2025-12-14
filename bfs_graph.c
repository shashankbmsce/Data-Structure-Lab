#include <stdio.h>

#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int i, node;

    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 5;
    int graph[MAX][MAX] = {0};

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    bfs(graph, n, 0);
    return 0;
}
