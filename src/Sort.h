#include <stdlib.h>

void SelectionSort(int *list,int size){
    for (int index=0; index < size-1; index++){
        int lowerIndex = index;

        for (int jIndex=index+1; jIndex<size; jIndex++){
        
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
    for(int index=0;index<size;index++){
        int indexMax = 0;
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

void merger(int* listMain,int mainSize, int* listFirstBranch, int firstBranchSize, int* listSecondBranch,int secondBranchSize){
    int indexMain =0, indexFirstBranch=0, indexSecondBranch=0;

    while(indexFirstBranch<firstBranchSize && indexSecondBranch<secondBranchSize){
        
        if(listFirstBranch[indexFirstBranch] <= listSecondBranch[indexSecondBranch]){
            listMain[indexMain]=listFirstBranch[indexFirstBranch];
            indexFirstBranch++;
        }
        else{
            listMain[indexMain]=listSecondBranch[indexSecondBranch];
            indexSecondBranch++;
        }
        
        indexMain++;
    }
    
    while(indexFirstBranch<firstBranchSize){
        listMain[indexMain] = listSecondBranch[indexSecondBranch];
        indexSecondBranch++;
        indexMain++;
    }

    while(indexSecondBranch<secondBranchSize){
        listMain[indexMain] = listFirstBranch[indexFirstBranch];
        indexFirstBranch++;
        indexMain++;
    }
}

void mergeSort(int *list,int size){
    if(size>1){
        int indexMid = size/2;
        int firstBranchSize = size-indexMid,secondBranchSize=indexMid;

        int* listFirstBranch = (int*)calloc(firstBranchSize, sizeof(int));
        int* listSecondBranch = (int*)calloc(secondBranchSize,sizeof(int));

        for(int index=0; index<indexMid; index++){
            listFirstBranch[index] = list[index];
        }

        for(int index=indexMid; index<size; index++){
            listSecondBranch[index] = list[index];
        }

        mergeSort(listFirstBranch,firstBranchSize);
        mergeSort(listSecondBranch, secondBranchSize);
        merger(list,size,listFirstBranch,firstBranchSize,listSecondBranch,secondBranchSize);

        free(listFirstBranch);
        free(listSecondBranch);
    }
}

