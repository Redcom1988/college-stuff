#include <stdio.h>
#include <stdlib.h>
    
// method algoritma kruskal dengan beberapa parameter
void sort(int V, int total, int edges[total][3], int index[total]) {

    // inisialisai array weight dengan panjang total
    int weight[total];

    // perulangan untuk set setiap nilai dari weight dan indexnya
    // nilai weight di set menjadi bobot pada edges
    // nilai index di set menjadi index dari bobot edge 
    for(int i = 0; i < total; i++) {
        weight[i] = edges[i][2];
        index[i] = i;
    }

    // nested for loop untuk melakukan bubble sort pada array weight
    for(int i = 0; i < total-1; i++) {
        for(int j = 0; j < total-1; j++) {

            // cek apakah elemen sebelah kiri lebih besar dari yang kanan
            if(weight[j] > weight[j+1]) {
                // tukar nilai kiri dan kanan dengan bantuan temp
                int temp1 = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp1;
                // tukar index kiri dan kanan dengan bantuan temp
                int temp2 = index[j];
                index[j] = index[j+1];
                index[j+1] = temp2;
            }
        }
    }
}

// method mencari parent dari vertex kini
// return nilai vertex jika parent bernilai -1
// selain itu, return fungsi find (rekursif)
int find(int parent[], int i) {
    if (parent[i] == -1) return i;
    return find(parent, parent[i]);
}

// method menggabungkan 2set berbeda 
void unionSet(int parent[], int x, int y) {

    // temukan parent dari masing-masing set
    int xset = find(parent, x);
    int yset = find(parent, y);
    // gabungkan 2set dengan menjadikan salah satu sebagai parent
    parent[xset] = yset;
}

// method algoritma kruskal dengan beberapa parameter
void kruskal(int V, int total, int edges[total][3], int tree[V-1][3], int index[total]) {

    // inisialisasi array parent dengan panjang V
    // atur setiap nilai parent menjadi -1
    int parent[V];
    for (int i = 0; i < V; i++) parent[i] = -1;

    // inisialisasi variabel count dan i bernilai 0
    // count digunakan untuk menghitung jumlah edge pada mst
    // i digunakan untuk mengakses indeks dalam array edges dan index
    int count = 0, i = 0;

    // loop while akan berjalan selama count kurang dari V-1
    while (count < V - 1) {

        // mengambil vertex u dan v dari edge yang ada di edges[index[i]]
        int u = edges[index[i]][0];
        int v = edges[index[i]][1];
        // memanggil fungsi find yang disimpan dalam variabel x dan y
        int x = find(parent, u);
        int y = find(parent, v);

        // cek apakah x != y (artinya u dan v berada dalam set yang berbeda)
        if (x != y) {
            // input u dan v serta bobotnya kedalam array tree
            tree[count][0] = u;
            tree[count][1] = v;
            tree[count][2] = edges[index[i]][2];
            // gabungkan 2set x dan y
            unionSet(parent, x, y);
            // menuju iterasi selanjutnya
            count++;
        }
        // perbarui nilai i tanpa melebihi nilai total
        i = (i+1) % total;
    }
}

int main() {
    // deklarasi jumlah vertex
    int V = 4;

    // deklarasi array edges dengan bobot dan vertex
    int edges[][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    // menghitung jumlah edge
    int total = sizeof(edges) / sizeof(edges[0]);

    // deklarasi array index dengan panjang total
    int tree[V - 1][3], index[total];

    // inisialisasi array tree dengan 0
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < 3; j++) {
            tree[i][j] = 0;
        }
    }

    // memanggil method sort
    sort(V, total, edges, index);

    // memanggil method kruskal
    kruskal(V, total, edges, tree, index);

    // print hasil algoritma kruskal
    printf("\nHasil Algoritma MST Kruskal : \n");
    printf("Edge\tWeight\n");
    int mst = 0;
    for (int i = 0; i < V - 1; i++) {
        printf("%d - %d\t%d\n", tree[i][0], tree[i][1], tree[i][2]);
        mst += tree[i][2];
    }
    printf("MST : %d\n", mst);

    return 0;
}