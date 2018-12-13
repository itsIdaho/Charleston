#include <stdio.h>
#include <string.h>
void erzeugeArray(int *, int);
void zeigeArrayInConsole(int *, int);
void dreiEcksTausch(int *, int);
int bubbleSort(int *, int);

int main()
{
	int anz = 10;
	int z[anz];
	int anzY = 0;
	
	erzeugeArray(z, anz);
	printf("Array mit %d zufälligen Zahlen:\n ", anz);
	zeigeArrayInConsole(z, anz);
    anzY = bubbleSort(z, anz);
    printf("\nArray mit %d zufälligen Zahlen sortiert:\n ", anz);
   	zeigeArrayInConsole(z, anz);
    printf("\n\n");
    printf("Maximalzahl der nötigen Vergleiche wäre (%d-1)*(%d-1) = %d\n", anz, anz, (anz-1)*(anz-1));
    printf("Verbesserte Version (pro Durchlauf 1 Vergleich weniger) wäre (%d + %d + %d + ... + 2 + 1 = %d\n", anz-1, anz-2, anz-3, (anz/2)*(1+anz));
    printf("Tatsächlich benötigte Vergleiche (Ausstieg mit break wenn fertig sortiert) = %d\n", anzY);
    //zuerst int anzY (Funktion) Speicher geben (int anzY = 0;) dann im Bubble Sort deklarieren (int min = 0;), unten beim bubbleSort in der Sort-Schleife min++,
    //da zählt es jeden durchlauf ein "min" Wert dazu, dann return min; um den Wert zurück zu geben
    //dann anzY = bubbleSort(z, anz); um den Wert "gleichzusetzen" und im printf per ("%d", anzY) ausgeben
 	return 0;
}

void erzeugeArray(int * array, int anz)
{    
    srand(time(0));
    for (int i = 0; i < anz; i++) 
    {
        array[i] = rand()%100;
    }
    return 0;
}

void zeigeArrayInConsole(int * array, int anz) 
{
    for (int i = 0; i < anz; i++) /* For schleife nicht mit ; abschließen, sonst glaubt der Compiler sie hört hier auf und array[i] zeigt einen "undeclared" fehler an*/
        printf("%d ", array[i]);
        return 0;
        
        
   // for(int i = 0; i<100;i++){ Geschwungene Klammer erst nötig wenn man mehrere Zeilen in der For-Schleife braucht
   // }    
        
        
}

void dreiEcksTausch(int *array, int position) /*Oben stehen "Prototypen", hier sollte man schon die Namen angeben*/ 
{
    int temp = array[position];
    array[position] = array[position+1];
    array[position+1]=temp;
    return 0;
}

int bubbleSort(int *z, int anz) // Da sie zurück gibt von void auf int
{
    int min = 0;
        int getauscht;
        for (int d=0; d < anz-1; d++){
            getauscht = 0;
         
            for (int v=0; v < anz-1-d; v++){ /* v++! */
                min++;
                if (z[v] > z[v+1]){ /* Nicht mit -1 sondern mit +1*/
                    dreiEcksTausch (z, v);
                }
            }
    }
    return min;
}
