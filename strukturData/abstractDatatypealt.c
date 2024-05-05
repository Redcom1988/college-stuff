#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char Nama[20];
  int NIM;
  int UTS;
  int UAS;
  int Tugas;
  int Kuis;
  float Nilai;
  char grade[2];
}Mhs;

int main() {
  int i,n;
  printf("Masukkan banyak mahasiswa: ");
  scanf("%d", &n);
  Mhs mkKomputer[n];

  while (getchar() != '\n');

  for (i = 0; i < n; i++) {
    printf("\nKetik Nama Mahasiswa: ");
    fgets(mkKomputer[i].Nama,sizeof(mkKomputer[i].Nama), stdin);
    printf("Ketik NIM Mahasiswa ");
    scanf("%d", &mkKomputer[i].NIM);
    printf("Ketik nilai UTS: ");
    scanf("%d", &mkKomputer[i].UTS);
    printf("Ketik nilai UAS: ");
    scanf("%d", &mkKomputer[i].UAS);
    printf("Ketik nilai tugas: ");
    scanf("%d", &mkKomputer[i].Tugas);
    printf("Ketik nilai kuis: ");
    scanf("%d", &mkKomputer[i].Kuis);

    mkKomputer[i].Nilai = 0.3 * mkKomputer[i].UTS + 0.3 * mkKomputer[i].UAS + 0.2 * mkKomputer[i].Tugas + 0.2 * mkKomputer[i].Kuis;
    printf("Nilai rata-rata: %.2f \n", mkKomputer[i].Nilai);

    if (mkKomputer[i].Nilai >= 80)
      strcpy(mkKomputer[i].grade, "A");
    else if (mkKomputer[i].Nilai >= 65)
      strcpy(mkKomputer[i].grade, "B");
    else if (mkKomputer[i].Nilai >= 50)
      strcpy(mkKomputer[i].grade, "C");
    else if (mkKomputer[i].Nilai >= 30)
      strcpy(mkKomputer[i].grade, "D");
    else
      strcpy(mkKomputer[i].grade, "E");
    
    printf("\nPenilaian: %s \n", mkKomputer[i].grade);
  }
  return 0
}