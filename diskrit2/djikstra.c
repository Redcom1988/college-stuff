#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int main() {

    int num_nodes;
    printf("|| User Input ||\n\n");
    printf("Masukkan Jumlah Vertex : ");
    scanf("%d", &num_nodes);
    printf("\n");

    int adjMatrix[MAX_NODES][MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            int distance;
            printf("Jarak dari vertex %d ke %d adalah: ", i+1, j+1);
            scanf("%d", &distance);
            if (distance != 0) {
                adjMatrix[i][j] = distance;
            }
        }
    }

    printf("\n====================== \n");
    printf("\n|| Matrix Adjacency ||\n\n");

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}