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
