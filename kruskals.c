#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX], n, e;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal() {
    int i, count = 0, cost = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, e, sizeof(Edge), cmp);

    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("Edge: %d - %d (%d)\n", u, v, edges[i].w);
            cost += edges[i].w;
            union_set(u, v);
            count++;
        }
    }

    printf("Total cost: %d\n", cost);
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter each edge (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal();
    return 0;
}
