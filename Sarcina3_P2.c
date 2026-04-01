#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* aduna(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    char* rezultat = (char*)malloc(maxLen + 2);

    int i = lenA - 1, j = lenB - 1, k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int cifraA = (i >= 0) ? a[i--] - '0' : 0;
        int cifraB = (j >= 0) ? b[j--] - '0' : 0;
        int suma = cifraA + cifraB + carry;
        rezultat[k++] = (suma % 10) + '0';
        carry = suma / 10;
    }
    rezultat[k] = '\0';

    for (int stanga = 0, dreapta = k - 1; stanga < dreapta; stanga++, dreapta--) {
        char temp = rezultat[stanga];
        rezultat[stanga] = rezultat[dreapta];
        rezultat[dreapta] = temp;
    }
    return rezultat;
}

void calculeazaFibonacci(int n) {
    if (n == 0) { printf("0\n"); return; }
    if (n == 1) { printf("1\n"); return; }

    char *f1 = strdup("0");
    char *f2 = strdup("1");
    char *f3 = NULL;

    clock_t start = clock();
    for (int i = 2; i <= n; i++) {
        f3 = aduna(f1, f2);
        free(f1);
        f1 = f2;
        f2 = f3;
    }
    clock_t end = clock();

// Pentru afisarea numarului Fibonacci, dar utilizeaza multa memorie: printf("Fib(%d) = %s\n", n, f2);
   if (n > 1000) {
        printf("Fib(%d) calculat. Lungime: %zu cifre.\n", n, strlen(f2));
    } else {
        printf("Fib(%d) = %s\n", n, f2);
    }

    printf("Timp: %.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(f1);
    free(f2);
}

int main() {
    int n;
    printf("Introduceti pozitia N: ");
    scanf("%d", &n);
    calculeazaFibonacci(n);
    return 0;
}
