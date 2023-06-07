// 12S22025- Bronson TM Siallagan
// 12S22004 - Yohana Natalia Siahaan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void getString(char string[]) {
    int c = 0;
    while (1) {
        char x = getchar();
        if (x == '\r') {
            continue;
        }
        if (x == '\n') {
            break;
        }
        string[c] = x;
        string[++c] = '\0';
    }
}

void processString(int panjang_String, char str[]) {
    int n;

    if (strlen(str) % panjang_String == 0) {
        n = strlen(str) / panjang_String;
        n--;
    }
    else {
        n = strlen(str) / panjang_String + 1;
    }

    char soutStr[n][panjang_String + 1];
    int i = 0, j;

    while (i < n) {
        j = 0;
        while (j < panjang_String) {
            soutStr[i][j] = (i * panjang_String + j < strlen(str)) ? str[i * panjang_String + j] : '#';
            j++;
        }
        soutStr[i][panjang_String] = '\0';
        i++;
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", soutStr[i]);
    }

    j = 0;
    while (j < panjang_String) {
        i = 0;
        while (i < n) {
            printf("%c", soutStr[i][j]);
            i++;
        }

        if (j == panjang_String - 1) {
            printf("\n");
            break;
        }

        j++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <panjang_string>\n", argv[0]);
        return 1;
    }

    int panjang_String = atoi(argv[1]);
    char str[MAX];
    getString(str);
    processString(panjang_String, str);
    return 0;  
}