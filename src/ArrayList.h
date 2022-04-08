#include <stdlib.h>
#include <assert.h>

struct _arraylist {
    int * vector;
    int index;
    int size;
};

struct _arraylist* Init(int size) {
    /* Allocate Memory */
    struct _arraylist *list = (struct _arraylist*)malloc(sizeof(struct _arraylist));
    list->vector = (int*)calloc(size, sizeof(int));
    list->index=0;
    list->size = size;
    return list;
}

int Get(struct _arraylist* list, int index){
    if(index >= 0 && index < list->index) return list->vector[index];
    return -1;
} 

void ArraySizeDuplicated(struct _arraylist* list){
    list->vector = (int*)realloc(list->vector,2*list->size*sizeof(int));
    list->size*2;
}

void PushBack(struct _arraylist* list,int value){
    if (list->index == list->size) ArraySizeDuplicated(list);
    list->vector[list->index] = value;
    list->index++;
}

void InsertElement(struct _arraylist* list,int value,int index){
    if(index >= 0 && index < list->index){
        if(list->index == list->size)ArraySizeDuplicated(list);
        for(int i = index; i > index; i--){
            list->vector[i] = list->vector[i-1];
        }
        list->vector[index] = value;
        list->index++;
    }
}

void SetValue(struct _arraylist* list,int value,int index){
    if(index >= 0 && index<list->index) list->vector[index]=value;
}

void PopBack(struct _arraylist* list){
    list->index--;
}

void PopElement(struct _arraylist* list,int index){
    if(index >= 0 && index < list->index){
        for(int i=index; i< list->index-1;i++){
            list->vector[i-1] = list->vector[i];
        }
        list->index--;
    }
}

void RepresetationArrayList(struct _arraylist* list){
    printf("###################[Array List]########################");
    printf("[");
    for(int i=0;i<list->index;i++){
        printf("%d", list->vector[i]);
        if(i < list->index-1){
            printf(", ");
        }
    }
    printf("]");
}