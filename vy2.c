#include <stdio.h>

int binarySearch(int arr[], int sol, int sag, int x) {
    if (sag >= sol) {
        int orta = sol + (sag - sol) / 2;

        if (arr[orta] == x)
            return orta;

        if (arr[orta] > x)
            return binarySearch(arr, sol, orta - 1, x);

        return binarySearch(arr, orta + 1, sag, x);
    }

    return -1;
}

int main() {
    int dizi[] = {3, 4, 8, 9, 24, 47, 68, 76, 84}; // önce elemanlarý binary search yapabilmemiz için küçükten büyüðe sýralamalýyýz.
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int aranacak =76;

    int sonuc = binarySearch(dizi, 0, n - 1, aranacak);

    if (sonuc == -1)
        printf("Eleman bulunamadi.\n");
    else
        printf("Eleman %d. indiste bulundu.\n", sonuc);

    return 0;
}



