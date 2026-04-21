#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Kaba Kuvvet (Brute-Force) Yöntemi
// Mantık: Hiçbir optimizasyon yapmadan, metni her noktadan bölüp
// tüm yer değiştirme (swap) ve sabit bırakma ihtimallerini dener.
bool isScrambleBruteForce(char* s1, char* s2, int len) {
    // 1. Temel Durum: Eğer uzunluk 1 ise, sadece karakterlerin aynı olup olmadığına bakarız.
    if (len == 1) {
        return s1[0] == s2[0];
    }

    // 2. Temel Durum: Metinler birebir aynıysa, direkt true döneriz.
    if (strncmp(s1, s2, len) == 0) {
        return true;
    }

    // Metni 1. indisten başlayarak son karaktere kadar her olası noktadan böleriz (i = bölme noktası)
    for (int i = 1; i < len; i++) {

        // İHTİMAL 1: YER DEĞİŞTİRME YOK (Düğüm sabit kalmış)
        // 1. metnin sol tarafı ile 2. metnin sol tarafı VE
        // 1. metnin sağ tarafı ile 2. metnin sağ tarafı eşleşiyor mu?
        bool noSwap = isScrambleBruteForce(s1, s2, i) &&
                      isScrambleBruteForce(s1 + i, s2 + i, len - i);

        if (noSwap) {
            return true; // Eğer eşleşirse bu bir karmaşık (scramble) metindir.
        }

        // İHTİMAL 2: YER DEĞİŞTİRME VAR (Düğüm çapraz yer değiştirmiş)
        // 1. metnin sol tarafı ile 2. metnin SAĞ tarafı VE
        // 1. metnin sağ tarafı ile 2. metnin SOL tarafı eşleşiyor mu?
        bool swap = isScrambleBruteForce(s1, s2 + len - i, i) &&
                    isScrambleBruteForce(s1 + i, s2, len - i);

        if (swap) {
            return true; // Eğer çapraz eşleşirse bu da bir karmaşık metindir.
        }
    }

    // Tüm dallar denendi ve hiçbir eşleşme bulunamadıysa false döneriz.
    return false;
}

int main() {
    char s1[] = "great";
    char s2[] = "rgeat"; // 'g' ve 'r' yer değiştirmiş

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        printf("Metin uzunluklari farkli, scramble olamaz.\n");
        return 0;
    }

    printf("--- Brute-Force Yontemi ---\n");
    if (isScrambleBruteForce(s1, s2, len1)) {
        printf("Sonuc: '%s', '%s' metninin karistirilmis (scrambled) halidir.\n", s2, s1);
    } else {
        printf("Sonuc: Karistirilmis hali DEGILDIR.\n");
    }

    return 0;
}
