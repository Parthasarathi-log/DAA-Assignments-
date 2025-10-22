#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 999999

int cost[MAX][MAX], visited[MAX], n;

void prim() {
    int edge_count = 0, total_cost = 0;
    visited[0] = 1;

    while (edge_count < n - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge: %d - %d (%d)\n", a, b, cost[a][b]);
            visited[b] = 1;
            total_cost += cost[a][b];
            edge_count++;
        }
    }

    printf("Total cost: %d\n", total_cost);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    prim();
    return 0;
}