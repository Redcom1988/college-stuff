#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int pageCount;
} data;

int main() {
    int n, maxPagecountIndex;
    printf("Ketikkan banyak buku: ");
    scanf("%d", &n);
    data lib[n];
    
    for (int i = 0; i < n; i++) {
        printf("Buku ke %d \n", i+1);
        getchar();  
        printf("Judul: ");
        fgets(lib[i].name,sizeof(lib[i].name), stdin);
        fflush(stdin);
        printf("Jumlah Halaman: ");
        scanf("%d", &lib[i].pageCount);
        printf("\n");
    }

    int maxPageCount = lib[0].pageCount;
        for (int j = 1; j < n; j++) {
            if (lib[j].pageCount > maxPageCount) {
                maxPageCount = lib[j].pageCount;
                maxPagecountIndex = j;
            }
        }

    printf("Buku yang paling tebal adalah %s dengan jumlah halaman %d", lib[maxPagecountIndex].name, lib[maxPagecountIndex].pageCount);
    return 0;
}

int a[0]