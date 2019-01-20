
#include <stdio.h>

void NewArray(int *array, int size) //Wird im main mit "int size = 20" deklariert
{
    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%100; //Prozent gibt an in welchem Bereich sich die Zahlen befinden sollen, hier 0-100
    }
}

void ShowArray(int *array, int size)
{
    printf("Array normal Ausgeben: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void ShowArrayReversed(int *array, int size)
{
    printf("\nArray verkehrt Ausgeben: \n");
    for(int i = size; i > 0; i--)
    {
        printf("%d ", array[i-1]);
    }
}

int NumSum(int *array, int size)
{
    printf("\nSumme der Arrayzahlen\n");
    int sum = 0;
    
    for(int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    printf("%d ", sum);
}

int averageCalc(int *array, int size)
{
    printf("\nDurchschnitt des Arrays:\n");
    int average = 0;
    
    for(int i = 0; i < size; i++)
    {
        average = average + array[i];
    }
    average = average/size;
    
    return average;
}

int min(int *array,int size)
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

int main()
{
    int size = 100; //gibt an wie viele Zahlen ausgegeben werden, hier 100
    int array[size];
    
    NewArray(array, size);
    ShowArray(array, size); //arrayname(array, size); um eine Ausgabe zu haben
    ShowArrayReversed(array, size);
    NumSum(array, size);
    min(array, size);
    
    int average = averageCalc(array, size);
    printf("%d", average);
}
