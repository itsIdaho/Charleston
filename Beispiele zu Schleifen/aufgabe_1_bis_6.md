#include <stdio.h>
#include <time.h>

void newArray(int *array, int size)
{
    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%100;
    }
}

void showArray(int *array, int size)
{
    printf("Array in normaler Reihenfolge: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void showArrayInReverse(int *array, int size)
{
    printf("\nArray in umgekehrter Reihenfolge: \n");
    for(int i = size; i > 0; i--)
    {
        printf("%d ", array[i-1]);
    }
}

int sumCalculator(int *array, int size)
{
    printf("\nSumme des Array's\n");
    int sum = 0;
    
    for(int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    
    printf("%d", sum);
}

int averageCalculator(int *array, int size)
{
    printf("\nDurchschnitt des Array's\n");
    int average = 0;
    
    for(int i = 0; i < size; i++)
    {
        average = average + array[i];
    } 
    
    average = average/size;
    
    return average;
}

void convertArray(int *array, int size, int average) 
{
    printf("\nArray mit gleichem Durchschnitt\n");
    for(int i = 0; i < size; i++)
    {
        if (average*0.80 > array[i] || average*1.20 < array[i])
        {
            array[i] = average;
        }
        printf("%d ", array[i]);
    }
}

int min(int *array, int size)
{
    printf("\nMinimum:\n");
    int min = array[0];
    
    for(int i = 1; i < size; i++) 
    {
        if(array[i] < min)
        {
            min = array[i];
        }
    }
    printf("%d", min);
}

int max(int *array, int size)
{
    printf("\nMaximum:\n");
    int max = array[0];
    
    for(int i = 1; i < size; i++) 
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    printf("%d", max);
}

void countNumbers(int *array, int size)
{
    int singleDigit = 0;
    int doubleDigit = 0;
    int others = 0;
    
    for(int i = 0; i < size; i++) {
        if (array[i] < 10) 
        {
            singleDigit = singleDigit +1;
        } 
        if(array[i] <= 99 && array[i] >= 10)
        {
            doubleDigit = doubleDigit +1;
        }
        if(array[i] >= 100)
        {
            others = others +1;
        }
    }
    
    printf("\nEinstellige Zahlen: %d", singleDigit);
    printf("\nZweistellige Zahlen: %d", doubleDigit);
    printf("\nAndere Zahlen: %d", others);
}

int main()
{
    int size = 20;
    int array[size];
    
    newArray(array, size);
    showArray(array, size);
    showArrayInReverse(array, size);
    sumCalculator(array, size);
    min(array, size);
    max(array, size);
    countNumbers(array, size);
    
    int average = averageCalculator(array, size);
    printf("%d", average);
    
    convertArray(array, size, average);
    
    return 0;
}

//by ZamohtM
