#include <stdlib.h>

void SelectionSort(int *list,int size){
    for (int index=0; index < size; index++){
        int lowerIndex = 0;

        for (int jIndex=0; jIndex<size; jIndex++){
        
            if(list[jIndex]<list[lowerIndex]){
                lowerIndex = jIndex;
            }

        }

        int temp = list[index];
        list[index] = list[lowerIndex];
        list[lowerIndex] = temp;
    }
}

void InsertionSort(int* list, int size){
    for(int index=1;index<size;index++){
        
        for (int jIndex=index;jIndex>0;jIndex--){
            if(list[jIndex-1] > list[jIndex]){
                int temp = list[jIndex-1];
                
                list[jIndex-1]=list[jIndex];
                list[jIndex]=temp;
            }
        }
    }
}

void boubleSort(int *list, int size){
    int indexMax = 0;
    for(int index=0;index<size;index++){

        for(int jIndex=0;jIndex<size-index;jIndex++){
            if(list[jIndex]>list[indexMax]){
                indexMax=jIndex;
            }
        }
        int temp = list[size-1-index];

        list[size-1-index] = list[indexMax];
        list[indexMax] = temp;
    }
}