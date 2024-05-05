#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int main() {

    // Meminta user untuk input jumlah vertex
    int num_nodes;
    printf("|| User Input ||\n\n");
    printf("Masukkan Jumlah Vertex : ");
    scanf("%d", &num_nodes);
    printf("\n");

    // Deklarasi awal matriks ketetanggan
    int adjMatrix[MAX_NODES][MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Iterasi untuk input koneksi antara vertex
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            int connection;
            printf("Apakah ada koneksi dari %d ke %d? (1/0) : ", i+1, j+1);
            scanf("%d", &connection);
            if (connection) {
                adjMatrix[i][j] = 1;
            }
        }
    }

    // Mengecek apakah setiap vertex memiliki 
    // hubungan untuk menentukan jika graf terhubung atau tidak
    int connection;
    int list[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        int row = i;
        for (int j = 0; j < num_nodes; j++) {
            if (adjMatrix[row][j] == 1) {
                connection++;
            }
        }
        if (connection > 0) {
            list[i] = 1;
        }
        connection = 0;
    }

    // Menampilkan hasil program matriks ketetanggaan
    printf("\n====================== \n");
    printf("\n|| Matrix Adjacency ||\n\n");

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Menampilkan informasi graf
    printf("\n======================\n");
    printf("\n|| Informasi Graf ||\n\n");
    printf("Jumlah vertex : %d\n", num_nodes);
    printf("Terhubung : ");
    
    // Mengecek apakah graf tersebut terhubung atau tidak terhubung
    int isConnected = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (list[i] == 0) {
            isConnected++;
        }
    }
    printf("%s\n", isConnected > 0 ? "Tidak" : "Ya");

    // Mengecek jumlah derajat dari masing-masing vertex
    int degVertex[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        degVertex[i] = 0;
        for (int j = 0; j < num_nodes; j++) {
            degVertex[i] += adjMatrix[i][j];
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        printf("Derajat vertex %d : %d\n", i+1, degVertex[i]);
    }

    // Asumsikan graf tidak berarah
    int isDirected = 0;
    // Asumsikan graf sederhana
    int isSimple = 1;

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            // Jika tidak simetris maka berarah
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                isDirected++;
            }
            // Jika terdapat loop pada vertex maka tidak sederhana
            if (adjMatrix[i][j] == 1 && i == j) {
                isSimple--;
            }
        }
    }

    printf("Jenis graf : %s%s\n", isDirected ? "Berarah" : "Tidak Berarah", 
            isSimple == 1 ? ", Sederhana" : ", Tidak Sederhana");

    return 0;
}