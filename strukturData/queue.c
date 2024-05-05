// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct {
//     char name[100];
//     int idn;
//     int category;
//     int nominal;
//     int change;
// } queue;

// void getInput(char fieldName[], queue src[], int incr) {
//     getchar();
//     if (strcmp(fieldName, "name") == 0) {
//         fgets(src[incr].name, sizeof(src[incr].name), stdin);
//         size_t len = strlen(src[incr].name);
//         if (len > 0 && src[incr].name[len - 1] == '\n')
//             src[incr].name[len - 1] = '\0';
//     }
// }

// int isEmpty(int t, int h) {
//     if (!t == h) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// int isFull(int maxQueue, int t, int h) {
//     if ((h + 1) % maxQueue == t) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// void enqueueData(queue src[], int current) {
//     printf("\nNama: ");
//     getInput("name", src, current);
//     printf("NIM: ");
//     scanf("%d", &src[current].idn);
//     printf("UKT: ");
//     scanf("%d", &src[current].category);
//     printf("Nominal: ");
//     scanf("%d", &src[current].nominal);
// }

// int main() {
//     int n, current = 0, choice;
//     char returnConfirmation;
//     int tail, head;

//     printf("Program Antrian Pembayaran UKT:\n");
//     printf("Input Maks Antrian: ");
//     scanf("%d", &n);

//     queue stdb[n];

//     do {
//         printf("\nMenu:");
//         printf("\n1. Tambah Antrian");
//         printf("\n2. Proses Pembayaran");
//         printf("\n3. Lihat Antrian");
//         printf("\n3. Keluar");
//         printf("\n\nPilihan: ");
//         scanf("%d", &choice);

//          switch (choice) {
//             case 1:
//                 if (!isFull(n, tail, head) | isEmpty(tail, head)) {
//                     enqueueData(stdb, tail);
//                     // printf("\nNama: ");
//                     // getInput("name", stdb, tail);
//                     // printf("NIM: ");
//                     // scanf("%d", &stdb[tail].idn);
//                     // printf("UKT: ");
//                     // scanf("%d", &stdb[tail].category);
//                     // printf("Nominal: ");
//                     // scanf("%d", &stdb[tail].nominal);
//                     tail++;
//                 } else {
//                     printf("Antrian sudah penuh\n");
//                 }
//                 break;
//             case 2:
//                 if (n > 1) {
//                     // printf
//                 } else {
//                     printf("Antrian Kosong.\n");
//                 }
//                 break;
//             case 3:
//                 printf("\nDATA ANTRIAN MAHASISWA\n");
//                 printf("Nama\tNIM\tUKT\tNominal\n");
//                 for (int i = 0; i < n; i++) {
//                     printf("%s\t%d\t%d\t%d", &stdb[i].name &stdb[i].idn &stdb[i].category &stdb[i].nominal);
//                 }
//                 break;
//             case 4:
//                 printf("Anda yakin (Y/T): ");
//                 scanf(" %c", &returnConfirmation);
//                 if (returnConfirmation == 'Y' || returnConfirmation == 'y') {
//                     printf("Terimakasih\n");
//                     exit(0);
//                 }
//                 break;
//             default:
//                 printf("Pilihan tidak valid.\n");
//             }
//     } while (1);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char nim[10];
    int ukt;
    int nominal;
} Pembayaran;

int isEmpty(int t, int h, int status) {
    return (t == h && status == 0);
}

int isFull(int t, int h, int status) {
    return (t == h && status == 1);
}

void enqueueData(Pembayaran src[], int current) {
    getchar();
    printf("\nInput Data Mahasiswa\n");
    printf("Nama : ");
    fgets(src[current].name, sizeof(src[current + 1].name), stdin);
    strtok(src[current].name, "\n");
    printf("NIM : ");
    fgets(src[current].nim, sizeof(src[current + 1].nim), stdin);
    strtok(src[current].nim, "\n");
    printf("UKT : ");
    scanf("%d", &src[current].ukt);
    printf("Nominal : ");
    scanf("%d", &src[current].nominal);
}

int main() {
    int maks_antrian, pilihan, total_bayar;
    char keluar;
    int head = 0, tail = 0, status = 0;

    printf("Program Antrian Pembayaran UKT\n");
    printf("Input maks antrian : ");
    scanf("%d", &maks_antrian);
    Pembayaran Data[maks_antrian];

    do {
        printf("\nMenu : \n1. Tambah Antrian\n2. Proses Pembayaran\n3. Lihat Antrian\n4. Keluar\n");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                if (!isFull(tail, head, status) || isEmpty(tail, head, status)) {
                    enqueueData(Data, tail);
                    tail = (tail + 1) % maks_antrian;
                    status = 1;
                } else {
                    printf("\njumlah antiran sudah mencapai batas Maksimum yaitu %d", maks_antrian);
                }
                break;
            case 2:
                if (!isEmpty(head, tail, status)) {
                    printf("\nData mahasiswa\n");
                    printf("Nama : %s\n", Data[head].name);
                    printf("NIM : %s\n", Data[head].nim);
                    printf("UKT : %d\n", Data[head].ukt);
                    printf("Nominal : %d\n", Data[head].nominal);
                    printf("Masukkan Nominal Bayar : ");
                    scanf("%d", &total_bayar);
                    if (Data[head].nominal > total_bayar) {
                        printf("\nUang yang anda masukkan belum cukup\n");
                    } else {
                        Data[head].nominal = Data[head].nominal - total_bayar; 
                        status = 0;
                    }

                    if (Data[head].nominal == 0) {
                        printf("\nUang yang anda masukkan sudah cukup\n");
                        head = (head + 1) % maks_antrian;
                    } else if (Data[head].nominal < 0) {
                        printf("\nUang yang anda masukkan sudah cukup\n");
                        printf("\nKembalian : %d \n", (Data[head].nominal * -1));
                        head = (head + 1) % maks_antrian;
                    }
                    
                } else {
                    printf("\nAntrian Kosong\n");
                }
                break;
            case 3:
                if (!isEmpty(head, tail, status) || isFull(head, tail, status)) {
                    printf("\nDaftar Antrian\n");
                    printf("| %-40s | %-10s | %3s | %-16s | \n\n", "Nama", "NIM", "UKT", "Nominal");
                    int i = head;
                    do {
                        printf("| %-40s | %-10s | %-3d | Rp.%-13d |\n", Data[i].name, Data[i].nim, Data[i].ukt, Data[i].nominal);
                        i = (i + 1) % maks_antrian;
                    } while (i != tail);
                } else {
                    printf("\nAntrian Kosong\n");
                }
                break;
            case 4:
                printf("\nApakah Anda Yakin (Y/T) ?");
                scanf(" %c", &keluar);
                if (keluar == 'y' || keluar == 'Y') {
                    printf("\nTerimaksih\n");
                    exit(0);
                }
                break;
            default:
                printf("\nPilihan Tidak Tersedia\n");
                break;
        }
    } while (1);

    return 0;
}
