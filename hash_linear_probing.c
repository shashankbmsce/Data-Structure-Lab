#include <stdio.h>

#define M 10

int HT[M];

void init() {
    int i;
    for (i = 0; i < M; i++)
        HT[i] = -1;
}

void insert(int key) {
    int h = key % M;
    int i = h;

    while (HT[i] != -1) {
        i = (i + 1) % M;
        if (i == h) return;
    }
    HT[i] = key;
}

void display() {
    int i;
    for (i = 0; i < M; i++)
        printf("%d\n", HT[i]);
}

int main() {
    int keys[] = {1234, 5678, 4321, 8765, 1111, 2222};
    int n = 6;
    int i;

    init();

    for (i = 0; i < n; i++)
        insert(keys[i]);

    display();

    return 0;
}
