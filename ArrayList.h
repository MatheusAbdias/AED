#include <stdlib.h>
#include <assert.h>

struct _arraylist {
    int * vector;
    int index;
    int size;
};

struct _arraylist *arraylist_create(int size) {
    /* Allocate Memory */
    struct _arraylist *list = malloc(sizeof(struct _arraylist));
    list->size = size;
    list->vector = calloc(size, sizeof(int));
    list->index=0;
    return list;
}