#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char Nama[20];
  int UTS;
  int UAS;
  int Tugas;
  int Kuis;
  float Nilai;
  char Status[6];
}Mhs ;

int main() {
  int i,n;
  printf("Masukkan banyak mahasiswa: ");
  scanf("%d", &n);
  Mhs kelasD[n];

  for (i = 0; i < n; i++) {
    getchar();
    printf("Ketik Nama: ");
    fgets(kelasD[n].Nama,sizeof(kelasD[n].Nama), stdin);
    printf("Ketik nilai UTS: ");
    scanf("%d", &kelasD[i].UTS);
    printf("Ketik nilai UAS: ");
    scanf("%d", &kelasD[i].UAS);
    printf("Ketik nilai tugas: ");
    scanf("%d", &kelasD[i].Tugas);
    printf("Ketik nilai kuis: ");
    scanf("%d", &kelasD[i].Kuis);

    kelasD[i].Nilai = (3.0/10*kelasD[i].UTS) + (3.0/10*kelasD[i].UAS) + (2.0/10*kelasD[i].Tugas) + (2.0/10*kelasD[i].Kuis);
    printf("Nilai rata-rata: %.2f \n", kelasD[i].Nilai);

     if (kelasD[i].Nilai >= 60) {
       printf("Status: Lulus \n");
      } else { 
     printf("Status: Gagal \n");
     }
    
    printf("\n");

  }
}