#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "../Sort.h"

using namespace std;
class SortList : public ::testing::Test {
protected:
    virtual void TearDown(){
        free(list);
    }
    int size = 5;
    int* list = (int*)calloc(size,sizeof(int));
};
/*
TEST_F(SortList,selectionSortTest) {
    for(int index = 0; index < size; index++){
        list[index] = size-index;
    }
    SelectionSort(list,size);

	for(int index=0;index<size;index++){
        EXPECT_EQ(list[index],index+1);
    }
}

TEST_F(SortList,insertioSortTest) {
    for(int index = 0; index < size; index++){
        list[index] = size-index;
    }
    InsertionSort(list,size);

	for(int index=0;index<size;index++){
        EXPECT_EQ(list[index],index+1);
    }
}

TEST_F(SortList,boubleSortTest) {
    for(int index = 0; index < size; index++){
        list[index] = size-index;
    }
    boubleSort(list,size);

	for(int index=0;index<size;index++){
        EXPECT_EQ(list[index],index+1);
    }
}

TEST_F(SortList,MergeSort) {
    for(int index = 0; index < size; index++){
        list[index] = size-index;
    }
    mergeSort(list,size);

	for(int index=0;index<size;index++){
        EXPECT_EQ(list[index],index+1);
    }
}
*/
TEST_F(SortList,quickSort) {
    for(int index = 0; index < size; index++){
        list[index] = size-index;
    }

    quickSort(list,0,size);

	for(int index=0;index<size;index++){
        EXPECT_EQ(list[index],index+1);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}