#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char nim[10];
    int ukt;
    int nominal;
    struct lldata *next;
} lldata;

// int fillStatus(lldata *head) {
//     if (head == NULL) {
//         return 0;
//     } else if (head != NULL) {
//         return 1;
//     }
// }

void enqueueData(lldata *head, lldata *tail, lldata *new) {
    new = (lldata *)malloc(sizeof(lldata));
    getchar();
    printf("\nNama : ");
    fgets((new)->name, sizeof((new)->name), stdin);
    strtok((new)->name, "\n");
    printf("NIM : ");
    fgets((new)->nim, sizeof((new)->nim), stdin);
    strtok((new)->nim, "\n");
    printf("UKT : ");
    scanf("%d", &(new)->ukt);
    printf("Nominal : ");
    scanf("%d", &(new)->nominal);
    (new)->next = NULL;

    if (head == NULL) {
        head = new;
        tail = new;
    } else {
        (tail)->next = new;
        tail = new;
    }
}

void showData(lldata *head) {
    lldata *current = head;
    if (current == NULL) {
        printf("Antrian kosong\n");
    } else {
        while (current != NULL) {
            printf("| %-40s | %-10s | %3s | %-16s | \n\n", "Nama", "NIM", "UKT", "Nominal");
            printf("| %-40s | %-10s | %3d | Rp. %-12d | \n", current->name, current->nim, current->ukt, current->nominal);
            current = current->next;
        }
    }
}

int main() {
    printf("Program Antrian Pembayaran UKT\n");
    int pilihan;
    lldata *head = NULL, *tail = NULL, *new = NULL;

    do {
        printf("\nMenu : \n1. Tambah Antrian\n2. Lihat Antrian\n3. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                enqueueData(head, tail, new);
                break;
            case 2:
                showData(head);
                break;
            case 3:
                exit(0);
                break;
        }
    } while (1);
}
