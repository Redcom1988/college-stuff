#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int npeserta;
    char name[20];
    int nt;
    int np;
    int sum;
    float avg;
    char status[8];
} PK;

int getNilai(const char *tipe) {
    int Nilai;
    do {
        printf("Nilai %s: ", tipe);
        scanf("%d", &Nilai);
    } while (Nilai < 0 || Nilai > 100);
    return Nilai;
}

int main() {
    int i, n;
    printf("Masukkan banyak peserta kompetisi: ");
    scanf("%d", &n);
    PK data[n];

    for (i = 0; i < n; i++) {
        printf("\nNomor Peserta: ");
        scanf("%d", &data[i].npeserta);
        while (getchar() != '\n');

        printf("Nama Peserta: ");
        fgets(data[i].name, sizeof(data[i].name), stdin);
        data[i].name[strcspn(data[i].name, "\n")] = 0;

        data[i].nt = getNilai("Teori");
        data[i].np = getNilai("Praktek");

        data[i].sum = (data[i].nt + data[i].np);
        data[i].avg = data[i].sum / 2.0;
        printf("\nTotal Nilai: %d \n", data[i].sum);
        printf("Rata: %.2f \n", data[i].avg);

        if (data[i].avg >= 60)
            strcpy(data[i].status, "Lulus");
        else
            strcpy(data[i].status, "Gagal");

        printf("Penilaian: %s \n", data[i].status);
    }
    return 0;
}
