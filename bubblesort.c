#include <stdio.h>
#include <string.h>
void erzeugeArray(int *, int);
void zeigeArrayInConsole(int *, int);
void dreiEcksTausch(int *, int);
void bubbleSort(int *, int);

int main()
{
	int anz = 10;
	int z[anz];
	
	erzeugeArray(z, anz);
	printf("Array mit %d zufälligen Zahlen:\n ", anz);
	zeigeArrayInConsole(z, anz);
    bubbleSort(z, anz);
    printf("\nArray mit %d zufälligen Zahlen sortiert:\n ", anz);
   	zeigeArrayInConsole(z, anz);
    printf("\n\n");
  /*
    printf("Maximalzahl der nötigen Vergleiche wäre (%d-1)*(%d-1) = %d\n", anz, anz, (anz-1)*(anz-1));
    printf("Verbesserte Version (pro Durchlauf 1 Vergleich weniger) wäre (%d + %d + %d + ... + 2 + 1 = %d\n",); //Hier noch anz usw
    printf("Tatsächlich benötigte Vergleiche (Ausstieg mit break wenn fertig sortiert) = %d\n", anzY); //Hier noch anzY berechnen
  */
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
        printf("%d, ", array[i]);
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

void bubbleSort(int *z, int anz)
{
        int getauscht;
        for (int d=0; d < anz-1; d++){
            getauscht = 0;
         
            for (int v=0; v < anz-1-d; v++){ /* v++! */
                if (z[v] > z[v+1]){ /* Nicht mit -1 sondern mit +1*/
                    dreiEcksTausch (z, v);
                }
            }
    }
    return 0;
}
