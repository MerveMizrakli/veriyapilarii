#include <stdio.h>

int main() {
    int n, i, aranilan, a=0;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n);

    int dizi[n];

    printf("Dizinin elemanlarini giriniz: ");
    for (i=0; i<n; i++) {
        scanf("%d", &dizi[i]);
    }

    printf("Aranacak elemani giriniz: ");
    scanf("%d", &aranilan);

    // linear search
    for (i=0; i<n; i++) {
        if (dizi[i] == aranilan) {
            printf("%d sayisi %d. indekste bulundu.\n", aranilan, i);
            a = 1; // eleman bulundu
            break;
        }
    }

    if (a == 0) {
        printf("%d sayisi dizide bulunamadi.\n", aranilan);
    }

    return 0;
}

