#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    int pageCount;
    char author[100];
} stack;

int main() {
    int n, choice;
    printf("Pengumpulan Tumpukan Buku")
    printf("Ketik jumlah maksimum tumpukan: ")
    scanf("%d, &n")
    stack libdb[n]

    printf("Menu:");
    printf("\n 1. Tambah Buku");
    printf("\n 2. Ambil Buku");
    printf("\n 3. Keluar:");
    printf("\n Pilihan: ");
    scanf("%d", &choice)

    char returnConfirmation;
    do
    {
        switch(choice)
        {
            case 1:
                ...
                break;
            case 2:
                ...
                break;
            case 3:
                printf("Anda yakin (Y/T): ")
                scanf("%s", &returnConfirmation)
        }
        while (returnConfirmation != 'Y')
    }
}