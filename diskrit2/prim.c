#include <stdio.h>
#include <stdlib.h>

// metode algoritma prim dengan beberapa parameter
void prim(int V, int graph[V][V], int parent[V], int current[V]) {
    // inisialisasi array weight dan check dengan panjang array V
    // weight berfungsi untuk menyimpan bobot edges sementara
    // check berfungsi untuk mengecek vertex yang telah dikunjungi
    int weight[V], check[V];

    // atur setiap nilai dari weight dan check
    // nilai weight diatur menjadi sangat tinggi
    // nilai check diatur menjadi 0 (false)
    for (int i = 0; i < V; i++) {
        weight[i] = 9999;
        check[i] = 0;
    }
    // ubah nilai weight pertama menjadi 0 untuk memulai iterasi
    weight[0] = 0;

    // lakukan perulangan pencarian edge dengan bobot minimum
    for (int count = 0; count < V - 1; count++) {
        // inisialisasi variabel index dan min
        int index, min = 9999;

        // lakukan perulangan sebanyak jumlah vertex
        for (int i = 0; i < V; i++) {
            // cek vertex belum dikunjungi dan bobot edge kurang dari min
            if (!check[i] && weight[i] < min) {
                // set ulang min dan indeksnya menjadi bobot
                min = weight[i];
                index = i;
            }
        }
        
        // tandai vertex ke index yang dikunjungi
        check[index] = 1;
        // input vertex yang sedang dikunjungi
        current[count] = index;

        // lakukan perulangan sebanyak jumlah vertex
        for (int j = 0; j < V; j++) {
            // cek apakah vertex j memiliki hubungan dengan vertex kini, belum pernah dikunjungi,
            // dan jika bobotnya lebih kecil dari weight kini
            if (graph[index][j] && !check[j] && graph[index][j] < weight[j]) {
                // set nilai parent dan weight untuk vertex j menjadi index dan bobot edge
                parent[j] = index;
                weight[j] = graph[index][j];
            }
        }
    }

    // cek vertex yang belum dikunjungi 
    for (int i = 0; i < V; i++) {
        // jika belum dikunjungi, set nilai current
        if (!check[i]) {
            current[V - 1] = i;
            break;
        }
    }
}

int main() {
    // inisialisasi jumlah vertex dan array edges
    int V = 4;

    // deklarasi array edges dengan bobot dan vertex
    int edges[][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // deklarasi matriks graph dengan panjang V
    int graph[V][V];

    // inisialisasi matriks graph dengan 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // mengisi matriks ketetanggaan berdasarkan array edges
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        int start = edges[i][0];
        int end = edges[i][1];
        int weight = edges[i][2];
        graph[start][end] = weight;
        graph[end][start] = weight;
    }

    // inisialisasi array parent dan current serta mst
    int parent[V], current[V], mst = 0;
    parent[0] = -1;
    current[0] = 0;

    // memanggil metode prim
    prim(V, graph, parent, current);

    // print hasil algoritma prim
    printf("\nHasil Algoritma MST Prim : \n");
    printf("Edge\tWeight\n");

    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[current[i]] + 1, current[i] + 1, graph[parent[current[i]]][current[i]]);
        mst += graph[parent[current[i]]][current[i]];
    }
    printf("MST : %d", mst);

    return 0;
}
