#include <stdio.h>
#include <math.h>

void createArray(int *array, int length) {
    srand(time(0));
    
    for(int i = 0; i < length; i++)
    {
        int rng = rand();
        array[i] = rng%1000;
    }
}

void showArrayInConsole(int *array, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}

void showArrayReverseInConsole(int *array, int length) {
    for(int i = length; i >= 1; i--) {
        printf("%d ", array[i-1]);
    }
}

int minArray(int *array, int length) {
    int min = array[0];
    for (int i = 0; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    } return min;
}

int avgArray(int *array, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum = sum + array[i];
    } return sum/length;
}

int maxArray(int *array, int length) {
    int max = array[0];
    for (int i = 0; i < length; i++) {
       if (array[i] > max) {
           max = array[i];
       }
   } return max;
}

int sumArray(int *array, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum = sum + array[i];
    } return sum;
}

void differFromAvg(int *array, int length, int average) {
    int result = 0;
    for(int i = 0; i < length; i++) {
        if((array[i]*0.8) > average || (array[i]*1.2) < average) {
            array[i] = average;
        }
        printf("%d ", array[i]);
    }
}

void countNumLength (int *array, int length, int *count, int countLength) {
    int sumNumLength = 0;
    for (int i = 0; i < countLength; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        sumNumLength = log10(array[i]);
        count[sumNumLength]++;
    }
}

int main() {
    int length = 100;
    int numbers[length];
    int countLength = 3;
    int count[countLength];
    
    createArray(numbers,length);
    printf("Array: \n");
    showArrayInConsole(numbers, length);
    printf("\nArray reverse:\n");
    showArrayReverseInConsole(numbers, length);
    
    printf("\n\nMin: %d", minArray(numbers, length));
    int average = avgArray(numbers, length);
    printf("\nAvg: %d\n", average);
    printf("Max: %d\n", maxArray(numbers, length));
    printf("Sum: %d\n", sumArray(numbers, length));

    countNumLength(numbers, length, count, countLength);
    printf("\n\neinstellig: %d", count[0]);
    printf("\nzweistellig: %d", count[1]);
    printf("\nsonstige: %d\n", count[2]);
    
    printf("\nArray without statistical outliers: \n");
    differFromAvg(numbers, length, average);

    return 0;
}

//By Neupa
