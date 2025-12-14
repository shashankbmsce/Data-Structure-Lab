#include <stdio.h>

#define MAX 10

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int node) {
    int i;
    visited[node] = 1;

    for (i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int isConnected(int graph[MAX][MAX], int n) {
    int i;
    for (i = 0; i < n; i++) visited[i] = 0;

    dfs(graph, n, 0);

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) return 0; // Not connected
    }
    return 1; // Connected
}

int main() {
    int n = 5;
    int graph[MAX][MAX] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;

    if (isConnected(graph, n))
        printf("Connected\n");
    else
        printf("Not Connected\n");

    return 0;
}
