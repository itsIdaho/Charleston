#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
	Sortieren eines int-Arrays
	
	@author: www.c-howto.de
	@param *x: Zeiger auf int-Array
	@param size: Groesse des Arrays
*/

void fillArray(int *,int , int );
void printArray(int *, int , int );

void quickSort(int *, int , int );
int teile(int *, int , int );

void arrayMinSort(int *, int);
int arrayMinIndex(int *, int, int);

void dreiEcksTausch(int * , int );
int bubbleSort(int *, int );

int  main() {
	// Test
	clock_t start, finish;
	int rows=190,cols=90;
	int a[rows * cols];
	//printArray(&a[0], rows, cols);
	

	
	fillArray(&a[0], rows, cols);
	start = clock();
	arrayMinSort(&a[0], rows*cols);
	finish = clock();
	printf("\nMinsort Dauer: %d",finish-start);
	start = clock();
	arrayMinSort(&a[0], rows*cols);
	finish = clock();
	printf("\nMinsort Dauer sortiert: %d",finish-start);
	
	fillArray(&a[0], rows, cols);
	start = clock();
	bubbleSort(&a[0], rows*cols);
	finish = clock();
	printf("\nBubblesort Dauer: %d",finish-start);
	start = clock();
	bubbleSort(&a[0], rows*cols);
	finish = clock();
	printf("\nBubblesort Dauer sortiert: %d",finish-start);
	
	start = clock();
	quickSort(&a[0],0,rows*cols-1);
	finish = clock();
	printf("\nQuicksort Dauer: %d",finish-start);
	start = clock();
	quickSort(&a[0],0,rows*cols-1);
	finish = clock();
	printf("\nQuicksort Dauer sortiert: %d",finish-start);
	
	printf("\n");
//	printArray(&a[0], rows, cols);
	
	return 0;
}

int teile(int *x , int links, int rechts){
    int i=links, j=rechts-1;
    //int pivot=x[rechts];
    int pivot = x[rand()%(rechts-links)+links];
    int temp;
    do{
        while(x[i]<pivot && i<rechts-1){
            i++;
        }
        while(x[j]>=pivot && j>links){
            j--;
        }
        if(i<j){
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
        }
    }while(i<j);
    if(x[i]>pivot){
        x[rechts]=x[i];
        x[i]=pivot;
    }
    return i;
}
void quickSort(int *x, int links, int rechts){
    int teiler = 0;
    if(links < rechts){
        teiler = teile(x, links, rechts);
        quickSort(x, links, teiler);
        quickSort(x, teiler + 1, rechts);
    }
}

int arrayMinIndex(int *x, int start, int size) {
	int minIndex=start, i;
	for(i=start; i<size; i++) {
		if(x[i] < x[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}
void arrayMinSort(int *x, int size) {
	int i, temp, minIndex;
	for(i=0; i<size-1; i++) {
		minIndex = arrayMinIndex(x, i, size);
		if(i != minIndex) {
		temp = x[i];
		x[i] = x[minIndex];
		x[minIndex] = temp;
		}
	}
}

void fillArray(int *x,int rows, int cols) {
	//srand(time(NULL));
	srand(5);
	int i,j;
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {		
		*(x+(i*cols)+j) = rand() % (rows*cols);
		}
	}
}
void printArray(int *x, int rows, int cols) {
	int i, j;
	printf("\n\n");
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			printf(" \t%3d",*(x+(i*cols)+j));
		}
		printf("\n");
	}
}

void dreiEcksTausch(int *array , int stelle){
    int temp = array[stelle];
    array[stelle]=array[stelle+1];
    array[stelle+1]=temp;
}
int bubbleSort(int *array, int anz){
    int getauscht=0;
    int anzV=0;
    for(int d = 0; d<anz-1;d++){
        getauscht=0;
        for(int v = 0; v<anz-1-d; v++){
            if(array[v]>array[v+1]){
                anzV++;
                dreiEcksTausch(array,v);
                getauscht=1;
            }
        }
        if(getauscht==0) break;
    }
    return anzV;
    
}
