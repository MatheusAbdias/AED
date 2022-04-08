//Para Windows (MS Visual Studio):
//#include "pch.h"

//Para Linux:
#include <gtest/gtest.h>

#include "../ArrayList.h"
#include <math.h>

class ArraylistTest : public :: testing::Test{
protected:
	virtual void TearDown(){
		free(list->vector);
		free(list);
	}
	virtual void SetUp(){
		int size = 5;	
		list = Init(size);
	}
	struct _arraylist* list = NULL;
};
TEST_F(ArraylistTest, InsertInEmpythArrayList){
	PushBack(list,10);
	EXPECT_EQ(list->index, 1);
	EXPECT_EQ(Get(list,0), 10);

}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}