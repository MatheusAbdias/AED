#include <stdlib.h>

void SelectionSort(int *list, int size)
{
    for (int index = 0; index < size - 1; index++)
    {
        int lowerIndex = index;

        for (int jIndex = index + 1; jIndex < size; jIndex++)
        {

            if (list[jIndex] < list[lowerIndex])
            {
                lowerIndex = jIndex;
            }
        }

        int temp = list[index];
        list[index] = list[lowerIndex];
        list[lowerIndex] = temp;
    }
}

void InsertionSort(int *list, int size)
{
    for (int index = 1; index < size; index++)
    {

        for (int jIndex = index; jIndex > 0; jIndex--)
        {
            if (list[jIndex - 1] > list[jIndex])
            {
                int temp = list[jIndex - 1];

                list[jIndex - 1] = list[jIndex];
                list[jIndex] = temp;
            }
        }
    }
}

void bubbleSort(int *list, int size)
{
    for (int index = 0; index < size; index++)
    {
        int indexMax = 0;
        for (int jIndex = 0; jIndex < size - index; jIndex++)
        {
            if (list[jIndex] > list[indexMax])
            {
                indexMax = jIndex;
            }
        }
        int temp = list[size - 1 - index];

        list[size - 1 - index] = list[indexMax];
        list[indexMax] = temp;
    }
}

void merge(int *listMain, int mainSize, int *listFirstBranch, int firstBranchSize, int *listSecondBranch, int secondBranchSize)
{
    int indexMain = 0, indexFirstBranch = 0, indexSecondBranch = 0;

    while (indexFirstBranch < firstBranchSize && indexSecondBranch < secondBranchSize)
    {

        if (listFirstBranch[indexFirstBranch] <= listSecondBranch[indexSecondBranch])
        {
            listMain[indexMain] = listFirstBranch[indexFirstBranch];
            indexFirstBranch++;
        }
        else
        {
            listMain[indexMain] = listSecondBranch[indexSecondBranch];
            indexSecondBranch++;
        }

        indexMain++;
    }

    while (indexFirstBranch < firstBranchSize)
    {
        listMain[indexMain] = listFirstBranch[indexFirstBranch];
        indexFirstBranch++;
        indexMain++;
    }

    while (indexSecondBranch < secondBranchSize)
    {
        listMain[indexMain] = listSecondBranch[indexSecondBranch];
        indexSecondBranch++;
        indexMain++;
    }
}

void mergeSort(int *list, int size)
{
    if (size > 1)
    {
        int indexMid = size / 2;
        int firstBranchSize = indexMid, secondBranchSize = size - indexMid;

        int *listFirstBranch = (int *)malloc(firstBranchSize * sizeof(int));
        int *listSecondBranch = (int *)malloc(secondBranchSize * sizeof(int));

        for (int index = 0; index < indexMid; index++)
        {
            listFirstBranch[index] = list[index];
        }

        for (int index = indexMid; index < size; index++)
        {
            listSecondBranch[index - indexMid] = list[index];
        }

        mergeSort(listFirstBranch, firstBranchSize);
        mergeSort(listSecondBranch, secondBranchSize);
        merge(list, size, listFirstBranch, firstBranchSize, listSecondBranch, secondBranchSize);

        free(listFirstBranch);
        free(listSecondBranch);
    }
}

void switch_values(int *list, int firstValue, int secondValue)
{
    int temp = list[firstValue];

    list[firstValue] = list[secondValue];
    list[secondValue] = temp;
}

int partition(int *list, int indexFirst, int indexEnd)
{
    int indexPivo = indexFirst;
    int randIndex = rand() % (indexEnd - indexFirst) + indexFirst;

    switch_values(list, randIndex, indexEnd);

    int pivo = list[indexEnd];
    for (int index = indexFirst; index < indexEnd; index++)
    {
        if (list[index] <= pivo)
        {
            switch_values(list, indexPivo, index);
            indexPivo++;
        }
    }

    switch_values(list, indexPivo, indexEnd);

    return indexPivo;
}

void quickSort(int *list, int start, int end)
{
    if (end > start)
    {
        int indexPivo = partition(list, start, end);

        quickSort(list, start, indexPivo - 1);
        quickSort(list, indexPivo + 1, end);
    }
}

int findMax(int *list, int size)
{
    int max = list[0];
    for (int index = 1; index < size; index++)
    {
        if (max < list[index])
        {
            max = list[index];
        }
    }
    return max;
}

void countingSort(int *list, int size)
{
    int max = findMax(list, size);
    int *countList = (int *)calloc(max, sizeof(int));
    for (int index = 0; index < size; index++)
    {
        countList[list[index]]++;
    }

    for (int index = 1; index <=max; index++)
    {
        countList[index] += countList[index - 1];
    }

    int *sortedList = (int *)malloc(size * sizeof(int));
    for (int index = 0; index < size; index++)
    {
        countList[list[index]] -= 1;
        int sortedIndex = countList[list[index]];
        sortedList[sortedIndex] = list[index];
    }

    for (int index = 0; index < size; index++)
    {
        list[index] = sortedList[index];
    }
    free(sortedList);
    free(countList);
}