int teile(int *x, int links, int rechts){
    int i=links, j=rechts-1, pivot=x[rechts];
    int temp;
    do {
        while(x[i]<pivot && i<rechts-1){
        i++;
        }
        while(x[j]>=pivot && j>links){
        j--
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
    int Teiler = 0;
    if(links < rechts) {
    teiler - teile(x, links, rechts);
    quickSort(x, links, rechts);
    quickSort(x, teiler + 1, rechts);
    }
