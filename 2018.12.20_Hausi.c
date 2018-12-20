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


//BUBBLESORT
void pankiSwap(int *array, int i) {
    int temp = 0;
    temp = array[i];
    array[i] = array[i+1];
    array[i+1] = temp;
}    

void bubbleSort(int *array, int length) {
    int temp = 0;
    int swaped = 0;
    
    for(int d = 0; d < length-1; d++) {
        swaped = 0;
        for(int i = 0; i < length-1 - d; i++) {
            if(array[i] > array[i+1]) {
                pankiSwap(array, i);
                swaped = 1;
            }
        }
        if(swaped == 0) {
            break;
        }
    }
}


//MINSORT
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
    
    
    //BUBBLESORT
    createArray(numbers, length);
    start = clock();
    bubbleSort(numbers, length);
    finish = clock();
    printf("Bubblesort Dauer: %d", finish-start);
    
    start = clock();
    bubbleSort(numbers, length);
    finish = clock();
    printf("\nBubblesort Dauer sortiert: %d", finish-start);
    
    
    //MINSORT
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

//By Neupa
