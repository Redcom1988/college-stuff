#include <stdio.h>
#include <limits.h>

#define V 6

int parent[V];

// Find set of vertex i
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Does union of i and j. It returns
// false if i and j are already in the same
// set.
void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V]) {
    int mincost = 0; // Cost of min MST.

    // Initialize sets of disjoint sets.
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) { // Skip symmetric part of matrix
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            union1(a, b);
            printf("Edge %d:(%d, %d) cost:%d \n",
                   edge_count++, a, b, min);
            mincost += min;
        } else {
            printf("No more edges to process.\n");
            break;
        }
    }
    printf("\n Minimum cost= %d \n", mincost);
}

// Driver program to test above function
int main() {
    /* Let the user create the graph */
    int cost[V][V];

    printf("Enter the weights for each edge of the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) { // Skip symmetric part of matrix
            printf("Enter the weight of edge between vertex %d and %d: ", i, j);
            scanf("%d", &cost[i][j]);
            cost[j][i] = cost[i][j]; // Assign the symmetric weight
        }
    }

    // Print the solution
    kruskalMST(cost);

    return 0;
}