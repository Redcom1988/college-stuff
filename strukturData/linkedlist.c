#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lldata {
    char name[100];
    char nim[11];
    int ukt;
    int nominal;
    struct lldata *next;
} lldata;

int isFull(lldata *head, int maks_antrian) {
    int i = 0;
    lldata *current = head;
    while (current != NULL) {
        i++;
        current = current->next;
    }
    return i == maks_antrian;
}

int countData(lldata *head) {
    int i = 0;
    lldata *current = head;
    while (current != NULL) {
        i++;
        current = current->next;
    }
    return i;
}

lldata* freeIterate(lldata *head, lldata *current) {
    if (countData(head) == 1) {
        free(current);
        return NULL;
    } else {
        return current->next;
        free(current);
    }
}

lldata* freeCheck(lldata *head, lldata *tail) {
    if (countData(head) == 1) {
        free(head);
        return NULL;
    }
}

void showLatest(lldata *head) {
    printf("\nData Pembayaran\n");
    printf("Nama : %s\n", head->name);
    printf("NIM : %s\n", head->nim);
    printf("UKT : %d\n", head->ukt);
    printf("Nominal : %d\n", head->nominal);
}

lldata* enqueueData(lldata *head, lldata *tail) {
    getchar();
    lldata *newNode = (lldata *)malloc(sizeof(lldata));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("\nInput Data Mahasiswa\n");
    printf("Nama : ");
    fgets(newNode->name, sizeof(newNode->name), stdin);
    strtok(newNode->name, "\n");
    printf("NIM : ");
    fgets(newNode->nim, sizeof(newNode->nim), stdin);
    strtok(newNode->nim, "\n");
    printf("UKT : ");
    scanf("%d", &(newNode->ukt));
    printf("Nominal : ");
    scanf("%d", &(newNode->nominal));
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

lldata* payFee(lldata *head, int total_bayar) {
    lldata *current = head;
    if (current == NULL) {
        printf("\nAntrian kosong\n");
    } else {
        showLatest(current);
        printf("\nInput total bayar : ");
        scanf("%d", &total_bayar);
        if (total_bayar == current-> nominal) {
            printf("Uang sudah mencukupi\n");
            head = freeIterate(head, current);
        } else if (total_bayar > current->nominal) {
            printf("Kembalian : %d\n", total_bayar - current->nominal);
            head = freeIterate(head, current);
        } else {
            printf("Uang belum mencukupi\n");
        }
    return head;
    }
}

void showData(lldata *head) {
    lldata *current = head;
    if (current == NULL) {
        printf("\nAntrian kosong\n");
    } else {
        printf("\nData Antrian Pembayaran UKT\n");
        printf("| %-40s | %-10s | %3s | %-16s | \n", "Nama", "NIM", "UKT", "Nominal");
        printf("|==========================================|============|=====|==================|\n");
        while (current != NULL) {
            printf("| %-40s | %-10s | %3d | Rp. %-12d | \n", current->name, current->nim, current->ukt, current->nominal);
            current = current->next;
        }
    }
}

int main() {
    printf("Program Antrian Pembayaran UKT\n");
    int pilihan, total_bayar = 0, n; char keluar;
    lldata *head = NULL, *tail = NULL, *new = NULL;

    printf("Input maks antrian : ");
    scanf("%d", &n);

    do {
        printf("\nMenu : \n1. Tambah Antrian\n2. Pembayaran\n3. Lihat Antrian\n4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                if (isFull(head, n)) {
                    printf("\nAntrian sudah penuh\n");
                } else {
                    head = enqueueData(head, tail);
                    if (tail == NULL) tail = head;
                }
                break;
            case 2:
                head = payFee(head, total_bayar);
                tail = head;
                break;
            case 3:
                showData(head);
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
                printf("\nTotal data: %d\n", countData(head));
                break;
            case 6:
                head = freeCheck(head, tail);
                break;
        }
    } while (1);
}