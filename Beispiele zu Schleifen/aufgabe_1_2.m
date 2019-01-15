#include <stdio.h>

int main()
{
    int lenght = 10; //Wie viele Zahlen Array haben soll
    int array[lenght];
    int summe = 0;
    int mittelwert = 0;
    
    for (int i=0; i < lenght; i++)
    {
        array[i]=rand()%10; //%x gibt an bis zu welchem Wert die Random Werte sein sollen, %100 = alle Zahlen von 0-100
    }
    
    printf("Zahlen:\n ");
    for(int k=0; k<lenght; k++)
    {
        printf("%d ", array[k]);
    }
    
    printf("\nZahlen umgekehrt:\n ");
    for(int j=lenght-1; j>=0; j--)
    {
        printf("%d ", array[j]);
    }
    
    printf("\nSumme: ");
    for(int x=0; x<lenght; x++)
    {
        summe = summe + array[x];
    }
    
    printf("\n %d", summe);
    mittelwert = summe/lenght;
    printf("\nMittelwert: \n %d", mittelwert);
    
}
