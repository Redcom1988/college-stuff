#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 26

bool isConnected(int num_nodes, int adjacency_matrix[num_nodes][num_nodes]) {
    bool visited[MAX_NODES] = {false};
    int stack[MAX_NODES];
    int top = -1;
    int connected_nodes = 0;

    stack[++top] = 0;
    visited[0] = true;

    while (top != -1) {
        int current = stack[top--];
        connected_nodes++;
        for (int i = 0; i < num_nodes; i++) {
            if (adjacency_matrix[current][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }

    return connected_nodes == num_nodes;
}

int main() {
    int num_nodes;
    printf("Enter the number of vertices (maximum %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    printf("\n");

    int adjacency_matrix[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            char connection[3];
            printf("Is there a connection between %c and %c? (y/n): ", 'A' + i, 'A' + j);
            scanf("%s", connection);
            if (strcmp(connection, "y") == 0 || strcmp(connection, "Y") == 0) {
                adjacency_matrix[i][j] = adjacency_matrix[j][i] = 1;
            }
        }
    }

    printf("\nGraph Information:\n");
    printf("Number of vertices: %d\n", num_nodes);

    printf("\n===================== \n");
    printf("   Adjacency Matrix   \n");
    printf("===================== \n");

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    if (isConnected(num_nodes, adjacency_matrix)) {
        printf("\nThe graph is connected.\n");
    } else {
        printf("\nThe graph is not connected.\n");
    }

    return 0;
}
