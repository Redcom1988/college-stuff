#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIMPUL 26

void dfs(int num_simpul, int matriks_ketetanggaan[num_simpul][num_simpul], bool dikunjungi[], int simpul) {
    dikunjungi[simpul] = true;

    for (int i = 0; i < num_simpul; i++) {
        if (matriks_ketetanggaan[simpul][i] && !dikunjungi[i]) {
            dfs(num_simpul, matriks_ketetanggaan, dikunjungi, i);
        }
    }
}

bool terhubung(int num_simpul, int matriks_ketetanggaan[num_simpul][num_simpul]) {
    bool dikunjungi[MAX_SIMPUL] = {false};
    dfs(num_simpul, matriks_ketetanggaan, dikunjungi, 0); // Start DFS from node 0

    // Check if all nodes are visited
    for (int i = 0; i < num_simpul; i++) {
        if (!dikunjungi[i]) {
            return false; // If any node is not visited, graph is not connected
        }
    }
    return true; // If DFS from node 0 visits all nodes, graph is connected
}

int main() {
    int jumlah_simpul;
    printf("Masukkan jumlah simpul (maksimum %d): ", MAX_SIMPUL);
    scanf("%d", &jumlah_simpul);
    printf("\n");

    int matriks_ketetanggaan[MAX_SIMPUL][MAX_SIMPUL] = {0};

    char jenis_graf;
    printf("Apakah grafik tersebut berarah (y) atau tidak berarah (n)? ");
    scanf(" %c", &jenis_graf);

    switch (jenis_graf) {
        case 'y':
        case 'Y':
            for (int i = 0; i < jumlah_simpul; i++) {
                for (int j = 0; j < jumlah_simpul; j++) {
                    char sambungan;
                    printf("Apakah ada sambungan dari %c ke %c? (y/n): ", 'A' + i, 'A' + j);
                    scanf(" %c", &sambungan); // Perhatikan spasi sebelum %c untuk mengonsumsi karakter newline
                    if (sambungan == 'y' || sambungan == 'Y') {
                        matriks_ketetanggaan[i][j] = 1; // Anggap 1 mewakili sambungan
                    }
                }
            }
            break;

        case 'n':
        case 'N':
            for (int i = 0; i < jumlah_simpul; i++) {
                for (int j = i + 1; j < jumlah_simpul; j++) {
                    char sambungan;
                    printf("Apakah ada sambungan antara %c dan %c? (y/n): ", 'A' + i, 'A' + j);
                    scanf(" %c", &sambungan); // Perhatikan spasi sebelum %c untuk mengonsumsi karakter newline
                    if (sambungan == 'y' || sambungan == 'Y') {
                        matriks_ketetanggaan[i][j] = matriks_ketetanggaan[j][i] = 1; // Anggap 1 mewakili sambungan
                    }
                }
            }
            break;

        default:
            printf("Input untuk jenis grafik tidak valid. Keluar.\n");
            return 1;
    }

    printf("\nInformasi Graf:\n");
    printf("Jumlah simpul: %d\n", jumlah_simpul);

    printf("\n   Matriks Ketetanggaan   \n");

    for (int i = 0; i < jumlah_simpul; i++) {
        for (int j = 0; j < jumlah_simpul; j++) {
            printf("%d ", matriks_ketetanggaan[i][j]);
        }
        printf("\n");
    }

    if (terhubung(jumlah_simpul, matriks_ketetanggaan)) {
        printf("\nGraf tersebut terhubung.\n");
    } else {
        printf("\nGraf tersebut tidak terhubung.\n");
    }

    return 0;
}
