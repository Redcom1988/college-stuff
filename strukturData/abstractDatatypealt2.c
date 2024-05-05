#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nama[20];
    int NIM;
    int UTS;
    int UAS;
    int Tugas;
    int Kuis;
    float NFinal;
    char grade[2];
} Mhs;

int getNilai(const char *tipe) {
    int Nilai;
    do {
        printf("Ketik nilai %s: ", tipe);
        scanf("%d", &Nilai);
    } while (Nilai < 0 || Nilai > 100);
    return Nilai;
}

int main() {
    int i, n;
    printf("Masukkan banyak mahasiswa: ");
    scanf("%d", &n);
    Mhs mkKomputer[n];

    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("\nKetik Nama Mahasiswa: ");
        fgets(mkKomputer[i].Nama, sizeof(mkKomputer[i].Nama), stdin);
        printf("Ketik NIM Mahasiswa: ");
        scanf("%d", &mkKomputer[i].NIM);

        mkKomputer[i].UTS = getNilai("UTS");
        mkKomputer[i].UAS = getNilai("UAS");
        mkKomputer[i].Tugas = getNilai("tugas");
        mkKomputer[i].Kuis = getNilai("kuis");

        mkKomputer[i].NFinal = 0.3 * mkKomputer[i].UTS + 0.3 * mkKomputer[i].UAS + 0.2 * mkKomputer[i].Tugas + 0.2 * mkKomputer[i].Kuis;
        printf("Nilai mutu: %.2f \n", mkKomputer[i].NFinal);

        if (mkKomputer[i].NFinal >= 80)
            strcpy(mkKomputer[i].grade, "A");
        else if (mkKomputer[i].NFinal >= 65)
            strcpy(mkKomputer[i].grade, "B");
        else if (mkKomputer[i].NFinal >= 50)
            strcpy(mkKomputer[i].grade, "C");
        else if (mkKomputer[i].NFinal >= 30)
            strcpy(mkKomputer[i].grade, "D");
        else
            strcpy(mkKomputer[i].grade, "E");

        printf("Penilaian: %s \n", mkKomputer[i].grade);
    }

    return 0;
}
