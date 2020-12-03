#include<stdio.h>
int cost_matrix[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
    for(i = 1; i <= n; i++)
        if(cost_matrix[v][i] && !visited[i])
            q[++r] = i;
    if(f <= r) {
        visited[q[f]] = 1;
    bfs(q[f++]);
 }
}

void main() {
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);

    for(i=1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("\n Enter graph data in matrix form:\n");
    for(i=1; i<=n; i++) {
        for(j=1;j<=n;j++) {
            scanf("%d", &cost_matrix[i][j]);
        }
    }

    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    bfs(v);
    printf("\n The node which are reachable are:\n");

    for(i=1; i <= n; i++) {
        if(visited[i])
            printf("%d\t", i);
        else {
            printf("\n Bfs is not possible. Not all nodes are reachable");
            break;
        }
    }
}
