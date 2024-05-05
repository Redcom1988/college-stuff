#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int weight;
    float height;
} data;

int main() {
    int n;
    float itvalw, itvalh;
    printf("Ketik Jumlah Pasien: ");
    scanf("%d", &n);
    data ptn[n];

    for (int i = 0; i < n; i++) {
        printf("Data ke %d \n", i+1);
        getchar();
        printf("Ketik Nama Pasien: ");
        fgets(ptn[i].name,sizeof(ptn[i].name), stdin);
        fflush(stdin);
        printf("Ketik Berat Badan Pasien: ");
        scanf("%d", &ptn[i].weight);
        printf("Ketik Tinggi Badan Pasien: ");
        scanf("%f", &ptn[i].height);
        printf("\n");
    }

    float minWeight = ptn[0].weight;
    float minHeight = ptn[0].height;
    int minWeightIndex;
    int minHeightIndex;

    for (int j = 0; j < n; j++) {
        itvalw += ptn[j].weight;
        itvalh += ptn[j].height;

        if (ptn[j].weight < minWeight)
            minWeight = ptn[j].weight;
            minWeightIndex = j;

        if (ptn[j].height < minHeight)
            minHeight = ptn[j].height;
            minHeightIndex = j;
    }

    float avgWeight = itvalw/n;
    float avgHeight = itvalh/n;

    printf("Rata-rata berat badan: %.2f \n", avgWeight);
    printf("Rata-rata tinggi badan: %.2f \n", avgHeight);
    printf("Minimum berat badan: %.2f  Nama: %s\n", minWeight, ptn[minWeightIndex].name);
    printf("Minimum tinggi badan: %.2f  Nama: %s\n", minHeight, ptn[minHeightIndex].name);
    
}