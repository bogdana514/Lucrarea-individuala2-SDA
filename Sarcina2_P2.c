#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *tab = NULL;
int n = 0;

void initializare(int size) {
    n = size;
    tab = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++) tab[i] = rand() % 1000;
}

void afisare() {
    for(int i = 0; i < n; i++) printf("%d ", tab[i]);
    printf("\n");
}

void eliberarememorie() {
    free(tab);
    tab = NULL;
    n = 0;
}

int linearSearch(int x) {
    for(int i = 0; i < n; i++) if(tab[i] == x) return i;
    return -1;
}

int binarySearch(int x) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(tab[mid] == x) return mid;
        else if(tab[mid] < x) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int al, size, x;
    do {
        printf("\nMeniu:\n1.Initializare tablou\n2.Afisare tablou\n3.Eliberarea memoriei\n4.Linear search\n5.Binary search\n0.Iesire\nAlege optiunea: ");
        scanf("%d", &al);
        switch(al) {
            case 1: printf("Marime: "); scanf("%d", &size); initializare(size); break;
            case 2: afisare(); break;
            case 3: eliberarememorie(); break;
case 4:
    printf("Numar cautat: "); scanf("%d", &x);

    clock_t start = clock();
    int pos = -1;
    for(int i = 0; i < 10000; i++) {
        pos = linearSearch(x);
    }
    clock_t end = clock();

    if(pos != -1) {
        printf("Elementul %d a fost gasit la indexul: %d\n", x, pos);
    } else {
        printf("Elementul %d nu exista in tablou.\n", x);
    }
    printf("Timpul cautarii 'Linear search': %.6f sec\n", (double)(end-start)/CLOCKS_PER_SEC);
    break;

case 5:
    qsort(tab, n, sizeof(int), cmp);

    printf("Numar cautat: "); scanf("%d", &x);

    clock_t start2 = clock();
    int pos2 = -1;
    for(int i = 0; i < 10000; i++) {
        pos2 = binarySearch(x);
    }
    clock_t end2 = clock();

    if(pos2 != -1) {
        printf("Elementul %d a fost gasit la indexul: %d\n", x, pos2);
    } else {
        printf("Elementul %d nu exista in tablou.\n", x);
    }
    printf("Timpul cautarii 'Binary search': %.6f sec\n", (double)(end2-start2)/CLOCKS_PER_SEC);
    break;
        }
    } while(al != 0);
    return 0;
}
