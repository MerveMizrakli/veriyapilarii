#include <stdio.h>

// Bulanýk analiz ve kümeleme için meyve veri yapýsý
typedef struct {
    char isim[20];
    float tat;
    float sertlik;
    float aromatiklik;
} Meyve;

// Kümeleme için meyve özelliklerine göre benzerlik hesaplamasý
float benzerlik(Meyve m1, Meyve m2) {
    float tatFark = m1.tat - m2.tat;
    float sertlikFark = m1.sertlik - m2.sertlik;
    float aromatiklikFark = m1.aromatiklik - m2.aromatiklik;
    float benzerlikDegeri = tatFark * tatFark + sertlikFark * sertlikFark + aromatiklikFark * aromatiklikFark;
    return benzerlikDegeri;
}

// Kümeleme iþlemini gerçekleþtiren fonksiyon
void kumeleme(Meyve meyveler[], int meyveSayisi, int kumeSayisi) {
    int i, j;
    int enYakinKume;
    float enKucukBenzerlik;

    // Küme merkezlerini rastgele seçme
    Meyve kumeler[kumeSayisi];
    for (i = 0; i < kumeSayisi; i++) {
        kumeler[i] = meyveler[i];
    }

    // Kümeleme iþlemi
    for (i = 0; i < meyveSayisi; i++) {
        enKucukBenzerlik = benzerlik(meyveler[i], kumeler[0]);
        enYakinKume = 0;

        for (j = 1; j < kumeSayisi; j++) {
            float b = benzerlik(meyveler[i], kumeler[j]);
            if (b < enKucukBenzerlik) {
                enKucukBenzerlik = b;
                enYakinKume = j;
            }
        }

        // Meyveyi en yakýn kümeye atama
        printf("%s meyvesi, %d numarali kumeye eklendi.\n", meyveler[i].isim, enYakinKume+1);
    }
}

int main() {
    int meyveSayisi, kumeSayisi, i;

    printf("Kac adet meyve gireceksiniz? ");
    scanf("%d", &meyveSayisi);

    Meyve meyveler[meyveSayisi];

    for (i = 0; i < meyveSayisi; i++) {
        printf("%d. meyvenin adini girin: ", i + 1);
        scanf("%s", meyveler[i].isim);
        printf("%d. meyvenin tat degerini girin (0-10 arasi): ", i + 1);
        scanf("%f", &meyveler[i].tat);
        printf("%d. meyvenin sertlik degerini girin (0-10 arasi): ", i + 1);
        scanf("%f", &meyveler[i].sertlik);
        printf("%d. meyvenin aromatiklik degerini girin (0-10 arasi): ", i + 1);
        scanf("%f", &meyveler[i].aromatiklik);
    }

    printf("\nKac adet kume olusturmak istiyorsunuz? ");
    scanf("%d", &kumeSayisi);

    kumeleme(meyveler, meyveSayisi, kumeSayisi);

    return 0;
}







