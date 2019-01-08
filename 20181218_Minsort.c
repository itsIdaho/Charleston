#include <stdio.h>
#include <string.h>
#include <time.h>

void createArray(int *array, int length) {
    srand(time(0));
    
    for(int i = 0; i < length; i++)
    {
        int rng = rand();
        array[i] = rng%100;
    }
}

void showArrayInConsole(int *array, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}

int arrayMinIndex(int *x, int start, int size) {
    int minIndex = start;
    for(int i = start; i < size; i++) {
        if(x[i] < x[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void arrayMinSort(int *x, int size) {
    int temp = 0;
    int minIndex = 0;
    for(int i = 0; i < size-1; i++) {
        minIndex = arrayMinIndex(x, i, size);
        if(i != minIndex) {
        temp = x[i];
        x[i] = x[minIndex];
        x[minIndex] = temp;
        }
    }
}

int main() {
    int length = 10000;
    int numbers[length];
    int start = 0;
    int finish = 0;
    
    createArray(numbers, length);
    start = clock();
    arrayMinSort(numbers, length);
    finish = clock();
    printf("\nMinsort Dauer: %d", finish-start);
    
    start = clock();
    arrayMinSort(numbers, length);
    finish = clock();
    printf("\nMinsort Dauer sortiert: %d", finish-start);
    
    return 0;
}
