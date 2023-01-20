#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n, adj[MAX][MAX], visited[MAX];

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        //vertex is not visited yet and there is an edge
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    dfs(start);
    return 0;
}

/*
Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter the start vertex: 1

*/
