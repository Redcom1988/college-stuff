#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int idn;
    int category;
    int nominal;
    int change;
} queue;

void getInput(char fieldName[], queue src[], int incr) {
    getchar();
    if (strcmp(fieldName, "name") == 0) {
        fgets(src[incr].name, sizeof(src[incr].name), stdin);
        size_t len = strlen(src[incr].name);
        if (len > 0 && src[incr].name[len - 1] == '\n')
            src[incr].name[len - 1] = '\0';
    }
}

int isEmpty(int t, int h) {
    if (!t == h) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(int maxQueue, int t, int h) {
    if ((h + 1) % maxQueue == t) {
        return 1;
    } else {
        return 0;
    }
}

void enqueueData(queue src[], int current) {
    printf("\nNama: ");
    getInput("name", src, current);
    printf("NIM: ");
    scanf("%d", &src[current].idn);
    printf("UKT: ");
    scanf("%d", &src[current].category);
    printf("Nominal: ");
    scanf("%d", &src[current].nominal);
}

int main() {
    int n, current = 0, choice;
    char returnConfirmation;
    int tail, head;

    printf("Program Antrian Pembayaran UKT:\n");
    printf("Input Maks Antrian: ");
    scanf("%d", &n);
    queue stdb[n];

     do {
        printf("\nMenu:");
        printf("\n1. Tambah Antrian");
        printf("\n2. Proses Pembayaran");
        printf("\n3. Lihat Antrian");
        printf("\n3. Keluar");
        printf("\n\nPilihan: ");
        scanf("%d", &choice);

         switch (choice) {
            case 1:
                if (!isFull(n, tail, head) | isEmpty(tail, head)) {
                    enqueueData(stdb, tail);
                    // printf("\nNama: ");
                    // getInput("name", stdb, tail);
                    // printf("NIM: ");
                    // scanf("%d", &stdb[tail].idn);
                    // printf("UKT: ");
                    // scanf("%d", &stdb[tail].category);
                    // printf("Nominal: ");
                    // scanf("%d", &stdb[tail].nominal);
                    tail++;
                } else {
                    printf("Antrian sudah penuh\n");
                }
                break;
            case 2:
                if (n > 1) {
                    // printf
                } else {
                    printf("Antrian Kosong.\n");
                }
                break;
            case 3:
                printf("\nDATA ANTRIAN MAHASISWA\n");
                printf("Nama\tNIM\tUKT\tNominal\n");
                for (int i = 0; i < n; i++) {
                    printf("%s\t%d\t%d\t%d", &stdb[i].name &stdb[i].idn &stdb[i].category &stdb[i].nominal);
                }
                break;
            case 4:
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