#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *tab = NULL;
int n = 0;

void initializare(int size) {
    if (tab != NULL) free(tab);
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

void selectionSort() {
    clock_t start = clock();
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++)
            if(tab[j] < tab[min]) min = j;
        int temp = tab[i];
        tab[i] = tab[min];
        tab[min] = temp;
    }
    clock_t end = clock();
    printf("Timpul sortarii 'Selection sort': %.6f sec\n", (double)(end-start)/CLOCKS_PER_SEC);
}

void quickSortRec(int low, int high) {
    if(low < high) {
        int pivot = tab[high];
        int i = low-1;
        for(int j = low; j < high; j++) {
            if(tab[j] < pivot) {
                i++;
                int temp = tab[i];
                 tab[i] = tab[j];
                 tab[j] = temp;
            }
        }
        int temp = tab[i+1];
         tab[i+1] = tab[high];
          tab[high] = temp;
        int pi = i+1;
        quickSortRec(low, pi-1);
        quickSortRec(pi+1, high);
    }
}

void quickSort() {
    clock_t start = clock();
    quickSortRec(0, n-1);
    clock_t end = clock();
    printf("Timpul sortarii 'Quick sort': %.6f sec\n", (double)(end-start)/CLOCKS_PER_SEC);
}

int main() {
    int al, size;
    do {
        printf("\nMeniu:\n1.Initializare tabloului\n2.Afisarea tabloului\n3.Eliberare memoriei tabloului\n4.Selection sort\n5.Quick sort\n0.Iesire\nAlege optiunea: ");
        scanf("%d", &al);
        switch(al) {
            case 1: printf("Marime: "); scanf("%d", &size); initializare(size); break;
            case 2: afisare(); break;
            case 3: eliberarememorie(); break;
            case 4: selectionSort(); break;
            case 5: quickSort(); break;
        }
    } while(al != 0);
    return 0;
}
