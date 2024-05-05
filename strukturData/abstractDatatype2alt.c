#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int weight;
    int height;
} data;

int main() {
    int n;
    printf("Ketik Jumlah Pasien: ");
    scanf("%d", &n);
    data ptn[n];

    for (int i = 0; i < n; i++) {
        printf("\nData ke %d \n", i+1);
        getchar();
        printf("Nama: ");
        fgets(ptn[i].name,sizeof(ptn[i].name), stdin);
        fflush(stdin);
        printf("Berat Badan: ");
        scanf("%d", &ptn[i].weight);
        printf("Tinggi Badan: ");
        scanf("%d", &ptn[i].height);
    }

    int minWeight = ptn[0].weight;
    int minHeight = ptn[0].height;
    int minWeightIndex, minHeightIndex;

    for (int j = 0; j < n; j++) {
        if (ptn[j].weight < minWeight) {
            minWeight = ptn[j].weight;
            minWeightIndex = j;
        }

        if (ptn[j].height < minHeight) {
            minHeight = ptn[j].height;
            minHeightIndex = j;
        }
    }

    printf("\nBerat Terendah: %d (%s)\n", minWeight, ptn[minWeightIndex].name);
    printf("Tinggi Terendah: %d (%s)\n", minHeight, ptn[minHeightIndex].name);
    
}