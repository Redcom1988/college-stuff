#include <stdio.h>
#include <stdlib.h>

// method algoritma prim dengan beberaoa parameter
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
        // nilai min diatur menjadi sangat tinggi
        // index merupakan indeks dari min
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

            // cek apakah vertex j memiliki hubungan dengan vertex kini
            // cek apakah vertex j belum pernah dikunjungi
            // cek apakah bobotnya lebih kecil dari weight kini
            if (graph[index][j] && !check[j] && graph[index][j] < weight[j]) {
                // set nilai parent dan weight
                parent[j] = index;
                weight[j] = graph[index][j];
            }
        }
    }

    // lakukan perulangan sebanyak jumlah vertex
    for (int i = 0; i < V; i++) {
        // mencari vertex terakhir yang belum terpilih
        if (!check[i]) {
            // set vertex terakhir
            current[V-1] = i;
            break;
        }
    }    
}

int main() {
    system("cls");

    // inisialisasi variabel jumlah vertex
    int V;
    // input total vertex
    printf("Masukkan jumlah vertex : ");
    scanf("%d", &V);

    // inisialisasi matriks ketetanggaan dari graf
    int graph[V][V];

    // input edge dan bobotnya pada graph
    printf("\nInput bobot dari edge (ketik 0 jika tidak ada edge)\n");

    // nested for loop untuk mengakses matriks ketetanggaan
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {

            // inisialisasi variabel bobot
            int W;
            printf("Bobot dari edge %d - %d : ", i + 1, j + 1);
            // user input nilai bobot
            scanf("%d", &W);
            // input bobot ke dalam matriks
            graph[i][j] = W;
            graph[j][i] = W;

        }
    }

    // inisialisasi mst, array parent, dan current
    // mst adalah nilai minimum pada perentangan pohon
    // parent adalah vertex yang berhubungan dengan current
    // parent lebih dahulu dikunjungi sebelum current
    // current adalah vertex yang kini dikunjungi
    int parent[V], current[V], mst = 0;
    // set parent pertama menjadi -1 
    // karena vertex pertama tidak memiliki parent
    parent[0] = -1;
    // set current pertama menjadi 0 (vertex pertama)
    current[0] = 0;

    // panggil fungsi prim
    prim(V, graph, parent, current);

    // tampilkan hasil mst
    printf("\nHasil Algoritma MST Prim : \n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[current[i]]+1, current[i]+1, graph[parent[current[i]]][current[i]]);
        mst += graph[parent[current[i]]][current[i]];
    }
    printf("MST : %d", mst);

    return 0;
}