#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isScrambleDivideAndConquer(char* s1, char* s2, int len) {
    if (len == 1) return s1[0] == s2[0];
    if (strncmp(s1, s2, len) == 0) return true;


    int count[256] = {0};
    for (int i = 0; i < len; i++) {
        count[(unsigned char)s1[i]]++;
        count[(unsigned char)s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    for (int i = 1; i < len; i++) {

        if (isScrambleDivideAndConquer(s1, s2, i) &&
            isScrambleDivideAndConquer(s1 + i, s2 + i, len - i)) {
            return true;
        }

        if (isScrambleDivideAndConquer(s1, s2 + len - i, i) &&
            isScrambleDivideAndConquer(s1 + i, s2, len - i)) {
            return true;
        }
    }
    return false;
}

int main() {
    char s1[] = "elma ve armut";
    char s2[] = "male ev armtu";

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        printf("Metin uzunluklari farkli, scramble olamaz.\n");
        return 0;
    }

    printf("--- Bol ve Fethet / Backtracking Yontemi ---\n");
    if (isScrambleDivideAndConquer(s1, s2, len1)) {
        printf("Sonuc: '%s', '%s' metninin karistirilmis (scrambled) halidir.\n", s2, s1);
    } else {
        printf("Sonuc: Karistirilmis hali DEGILDIR.\n");
    }

    return 0;
}
