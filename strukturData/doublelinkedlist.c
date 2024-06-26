#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lldata {
    char name[100], nim[11];
    int nl, na, np, avg;
    struct lldata *next, *prev;
} lldata;

int isFull(lldata *head, lldata *tail, int maks_antrian) {
    lldata *current = head; int i = 0;
    if (head == tail && head != NULL) {
        i = 1;
    } else {
        while (current != tail) {
            i++;
            current = current->next;
        }
    }
    return i == maks_antrian;
} 

void showAvgData(lldata *head, lldata *tail) {
    lldata *current = head;
    if (current == NULL) {
        printf("\nAntrian kosong\n");
    } else {
        printf("\nData Antrian Pembayaran UKT\n");
        printf("| %-40s | %-10s | %-10s | \n", "Nama", "NIM", "Rata-rata");
        printf("|==========================================|============|============|\n");
        do {
            printf("| %-40s | %-10s | %-10d | \n", current->name, current->nim, current->avg);
            current = current->prev;
        } while (current != head);
    }
}

int main() {
    printf("Program Antrian Pembayaran UKT\n");
    int pilihan, n; char keluar; char rnim[11];
    lldata *head = NULL, *tail = NULL;

    printf("Input maks antrian : ");
    scanf("%d", &n);

    do {
        printf("\nMenu : \n1. Tambah Antrian\n2. Hilangi antrian dengan NIM\n3. Lihat Antrian\n4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan) {
            case 1:
                if (isFull(head, tail, n)) {
                    printf("\nAntrian sudah penuh\n");
                } else {
                    lldata *new = (lldata *)malloc(sizeof(lldata));
                    printf("\nInput Data Mahasiswa\n");
                    printf("Nama : ");
                    fgets(new->name, sizeof(new->name), stdin);
                    strtok(new->name, "\n");
                    printf("NIM : ");
                    fgets(new->nim, sizeof(new->nim), stdin);
                    strtok(new->nim, "\n");
                    printf("Nilai Logika : ");
                    scanf("%d", &(new->nl));
                    printf("Nilai Aritmatika : ");
                    scanf("%d", &(new->na));
                    printf("Nilai Pemrograman : ");
                    scanf("%d", &(new->np));

                    new->avg = (new->nl + new->na + new->np) / 3;

                    if (head == NULL) {
                        head = new; tail = new;
                        head -> next = tail; head -> prev = tail;
                    } else {
                        tail->next = new;
                        new->prev = tail;
                        tail = new;
                    }
                }
                break;
            case 2:
                printf("\nInput NIM data yang ingin dihapus: ");
                fgets(rnim, sizeof(rnim), stdin);
                strtok(rnim, "\n");
                // deleteData(head, rnim);
                if (head == NULL) {
                    printf("\nAntrian kosong\n");
                } else {
                    if (strcmp(head->nim, rnim) == 0) {
                        head = head->next;
                    } else {
                        lldata *temp1 = head;
                        while (temp1->next != NULL && strcmp(temp1->next->nim, rnim) != 0) {
                            temp1 = temp1->next;
                            }
                        if (temp1->next != NULL) {
                            lldata *temp2 = temp1->next;
                            temp1->next = temp2->next;
                            free(temp1);
                        } else {
                            printf("\nData tidak ditemukan\n");
                        }
                    }
                }
            case 3:
                showAvgData(head, tail);
                break;
            case 4:
                printf("\nApakah Anda Yakin (Y/T)? ");
                scanf(" %c", &keluar);
                if (keluar == 'y' || keluar == 'Y') {
                    printf("\nTerimakasih\n");
                    exit(0);
                }
                break;
            case 5:
                printf("%s\n", head->name);
                printf("%s\n", tail->name);
                break;
        }
    } while (1);
}