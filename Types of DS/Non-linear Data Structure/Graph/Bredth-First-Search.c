#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int n, adj[MAX][MAX], visited[MAX];

void enqueue(int val) {
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
    }
}

int dequeue() {
    int val = -1;
    if (front == -1 || front > rear)
        printf("Queue underflow\n");
    else {
        val = queue[front];
        front++;
    }
    return val;
}

void bfs(int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int val = dequeue();
        printf("%d ", val);

        for (i = 0; i < n; i++) {
            if (adj[val][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d ", &adj[i][j]);
        }
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    bfs(start);
    return 0;
}
