#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cls");                          // clear screen terminal

    // input total vertex
    int nodes;                              // deklarasi var total vertex
    printf("Masukkan jumlah vertex : ");
    scanf("%d", &nodes);                    // masukkan total vertex

    // input kode prufer
    int length = nodes - 2;                 // panjang code adalah total vertex - 2
    int code[length];                       // deklarasi array prufer code
    printf("Masukkan kode prufer : ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &code[i]);              // input prufer code
        code[i]--;
    }

    // inisialisasi matriks ketetanggaan
    int matrix[nodes][nodes];               // deklarasi matriks baris=kolom
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;               // set default nilai matriks menjadi 0
        }
    }

    // deklarasi variabel untuk rekonstruksi
    int index = 0, node = 0, count = 1;
    int degree[nodes];
    for (int i = 0; i < nodes; i++) degree[i] = 1;       // set default degree menjadi 1
    for (int i = 0; i < length; i++) degree[code[i]]++;  // tambahkan derajat vertex sesuai code

    // algoritma rekonstruksi prufer
    printf("\nProses Rekonstruksi Kode Prufer : \n\n");
    while (count <= length) {               // jalankan algoritma penambahan edge
        while (degree[node] != 1) node++;   // cek vertex yang berderajat 1
        matrix[node][code[index]] = 1;      // set nilai 1 pada baris,kolom matirks
        matrix[code[index]][node] = 1;
        printf("Tambahkan edge yang menghubungkan vertex %d %d\n", node+1, code[index]+1);
        // step increment/decrement
        degree[node]--;                     // decrement derajat vertex 1 (telah terpakai)
        degree[code[index]]--;              // decrement derajat vertex code (telah terpakai)
        index++;                            // increment index untuk melanjutkan array code
        count++;                            // increment count untuk menghitung edge
        node = 0;                           // set node kembali dari 0
    }

    // penambahan edge terakhir
    int last_node1 = 0, last_node2 = 0;             // set default value last node menjadi 0
    for (int i = 0; i < nodes; i++) {
        if (degree[i] == 1) {                       // cek sisa node yang berderajat 1
            if (last_node1 == 0) last_node1 = i;    // set last node pertama
            else last_node2 = i;                    // set last node kedua
        }
    }
    matrix[last_node1][last_node2] = 1;             // set nilai 1 pada baris,kolom matriks
    matrix[last_node2][last_node1] = 1;
    printf("Tambahkan edge yang menghubungkan vertex %d %d\n", last_node1 + 1, last_node2 + 1);

    // print hasil rekonstruksi
    printf("\nHasil Rekonstruksi Kode Prufer : ");
    printf("\nMatriks Ketetanggaan\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            printf("%d ", matrix[i][j]);    // print setiap baris matriks
        }
        printf("\n");                       // pemisah antar baris
    }

    return 0;
}