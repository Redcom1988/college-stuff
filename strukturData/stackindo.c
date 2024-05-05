#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char judul[100];
    int jumlahHalaman;
    char penulis[100];
} tumpukanBuku;

int main() {
    int jumlahTumpukan, saatIni = 0, pilihan;
    char konfirmasiKembali;

    printf("Program Tumpukan Buku:\n");
    printf("Masukkan jumlah maksimum tumpukan: ");
    scanf("%d", &jumlahTumpukan);
    tumpukanBuku dbBuku[jumlahTumpukan];

     do {
        printf("\nMenu:");
        printf("\n1. Tambah Buku");
        printf("\n2. Ambil Buku");
        printf("\n3. Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &pilihan);

         switch (pilihan) {
            case 1:
                if (saatIni < jumlahTumpukan) {
                    printf("\nMasukkan Judul Buku: ");
                    scanf("%s", dbBuku[saatIni].judul);
                    printf("Jumlah halaman: ");
                    scanf("%d", &dbBuku[saatIni].jumlahHalaman);
                    printf("Nama Penulis: ");
                    scanf("%s", dbBuku[saatIni].penulis);
                    printf("Buku berhasil ditambahkan!\n");
                    saatIni++;
                } else {
                    printf("Tumpukan buku sudah penuh!\n");
                }
                break;
            case 2:
                if (saatIni > 0) {
                    printf("Apakah Anda yakin (Y/T): ");
                    scanf(" %c", &konfirmasiKembali);
                    if (konfirmasiKembali == 'Y' || konfirmasiKembali == 'y') {
                        printf("Buku dengan judul %s telah diambil\n", dbBuku[saatIni - 1].judul);
                        saatIni--;
                    }
                } else {
                    printf("Tidak ada buku yang bisa diambil.\n");
                }
                break;
            case 3:
                printf("Apakah Anda yakin (Y/T): ");
                scanf(" %c", &konfirmasiKembali);
                if (konfirmasiKembali == 'Y' || konfirmasiKembali == 'y') {
                    printf("Terima kasih\n");
                    exit(0);
                }
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (1);

    return 0;
}
