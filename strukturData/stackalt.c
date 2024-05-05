#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    int pageCount;
    char author[100];
} stack;

void getInput(char field[], stack src[], int incr) {
    getchar()
    fgets(src[incr].field, sizeof(src[incr].field), stdin);
    size_t len = strlen(src[incr].field);
    if (len > 0 && src[incr].field[len - 1] == '\n')
        src[incr].field[len - 1] = '\0';
}

int main() {
    int n, current = 0, choice;
    char returnConfirmation;

    printf("Program tumpukan buku:\n");
    printf("Ketik jumlah maksimum tumpukan: ");
    scanf("%d", &n);
    stack libdb[n];

     do {
        printf("\nMenu:");
        printf("\n1. Tambah Buku");
        printf("\n2. Ambil Buku");
        printf("\n3. Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &choice);

         switch (choice) {
            case 1:
                if (current < n) {
                    printf("\nKetik Judul Buku: ");
                    // scanf(“ %[^\n]s”, libdb[current].title);
                    // getchar();
                    // fgets(libdb[current].title,sizeof(libdb[current].title), stdin);
                    // fflush(stdin);
                    printf("Jumlah halaman: ");
                    scanf("%d", &libdb[current].pageCount);
                    getchar();
                    printf("Penerbit: ");
                    // scanf(“ %[^\n]s”, libdb[current].author);
                    // fgets(libdb[current].author,sizeof(libdb[current].author), stdin);
                    getInput("author", libdb, current);
                    printf("Buku berhasil ditambahkan!\n");
                    current++;
                } else {
                    printf("Tumpukan buku sudah penuh!\n");
                }
                break;
            case 2:
                if (current > 0) {
                    printf("Anda yakin (Y/T): ");
                    scanf(" %c", &returnConfirmation);
                    if (returnConfirmation == 'Y' || returnConfirmation == 'y') {
                        printf("Buku dengan judul %s berhasil diambil\n", libdb[current - 1].title);
                        current--;
                    }
                } else {
                    printf("Tidak ada buku yang bisa diambil.\n");
                }
                break;
            case 3:
                printf("Anda yakin (Y/T): ");
                scanf(" %c", &returnConfirmation);
                if (returnConfirmation == 'Y' || returnConfirmation == 'y') {
                    printf("Terimakasih\n");
                    exit(0);
                }
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (1);

    return 0;
}